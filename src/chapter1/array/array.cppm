export module mySTL.array;
import std;

namespace mySTL::impl
{

template <typename T, std::size_t N>
class ArrayImpl
{
  public:
    static constexpr std::size_t CAPACITY = N == 0 ? 1 : N;

    T data[CAPACITY]{};

    constexpr std::size_t size() const noexcept
    {
        return N;
    }

    constexpr std::size_t capacity() const noexcept
    {
        return CAPACITY;
    }

    constexpr bool empty() const noexcept
    {
        return N == 0;
    }
};

} // namespace mySTL::impl

export namespace mySTL
{

template <typename T, std::size_t N>
class Array : public impl::ArrayImpl<T, N>
{
  public:
    constexpr T &operator[](std::size_t index) noexcept
    {
        return this->data[index];
    }

    constexpr const T &operator[](std::size_t index) const noexcept
    {
        return this->data[index];
    }

    constexpr T &at(std::size_t index)
    {
        if (index >= this->size())
        {
            throw std::out_of_range{"Index out of range"};
        }
        return this->data[index];
    }

    constexpr const T &at(std::size_t index) const
    {
        if (index >= this->size())
        {
            throw std::out_of_range{"Index out of range"};
        }
        return this->data[index];
    }

    using Iterator = T *;
    using ConstIterator = const T *;

    constexpr Iterator begin() noexcept
    {
        return this->data;
    }

    constexpr Iterator end() noexcept
    {
        return this->data + N;
    }

    constexpr ConstIterator begin() const noexcept
    {
        return this->data;
    }

    constexpr ConstIterator end() const noexcept
    {
        return this->data + N;
    }
};

template <typename T>
class Array<T, 0> : public impl::ArrayImpl<T, 0>
{
  public:
    using Iterator = T *;
    using ConstIterator = const T *;

    constexpr Iterator begin() noexcept
    {
        return this->data;
    }

    constexpr Iterator end() noexcept
    {
        return this->data;
    }

    constexpr ConstIterator begin() const noexcept
    {
        return this->data;
    }

    constexpr ConstIterator end() const noexcept
    {
        return this->data;
    }
};

} // namespace mySTL