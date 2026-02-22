export module mySTL.range;
import std;
import mySTL.iterator;

export namespace mySTL::range
{

template <typename T, std::size_t Size>
constexpr T *begin(T (&arr)[Size]) noexcept
{
    return arr;
}

template <typename T, std::size_t Size>
constexpr T *end(T (&arr)[Size]) noexcept
{
    return arr + Size;
}

template <typename T, std::size_t Size>
constexpr const T *begin(const T (&arr)[Size]) noexcept
{
    return arr;
}

template <typename T, std::size_t Size>
constexpr const T *end(const T (&arr)[Size]) noexcept
{
    return arr + Size;
}

template <typename T>
concept Range = requires(T &t) {
    { t.begin() } -> mySTL::iterator::Iterator;
    { t.end() };
} || requires(T &t) {
    { begin(t) } -> mySTL::iterator::Iterator;
    { end(t) };
};

template <typename T>
concept IterRange = Range<T> && 
(
    requires(T &t) {
        requires std::same_as<std::decay_t<decltype(t.begin())>, std::decay_t<decltype(t.end())>>;
    } || requires(T &t) {
        requires std::same_as<std::decay_t<decltype(begin(t))>, std::decay_t<decltype(end(t))>>;
    }
);

} // namespace mySTL::range