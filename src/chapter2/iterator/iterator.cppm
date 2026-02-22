export module mySTL.iterator;
import std;

export namespace mySTL::iterator
{

template <typename T>
concept Iterator = requires(T t, T u) {
    { *t };
    { t == u } -> std::convertible_to<bool>;
};

template <typename T>
concept ForwardIterator = Iterator<T> && requires(T t) {
    { ++t } -> std::same_as<T &>;
    { t++ };
};

template <typename T>
concept BidirectionalIterator = ForwardIterator<T> && requires(T t) {
    { --t } -> std::same_as<T &>;
    { t-- };
};

template <typename T, typename Diff = std::ptrdiff_t>
concept RandomAccessIterator = BidirectionalIterator<T> && requires(T t, const T ct, Diff n) {
    { t + n } -> std::same_as<T>;
    { n + t } -> std::same_as<T>;
    { t - n } -> std::same_as<T>;
    { t - t } -> std::same_as<Diff>;
    { t += n } -> std::same_as<T &>;
    { t -= n } -> std::same_as<T &>;
    { t[n] };
    { ct[n] };
    { t <=> t };
};

template <typename T>
concept ContiguousIterator = RandomAccessIterator<T> && requires(T t) {
    { std::addressof(*t) };
};

} // namespace mySTL::iterator