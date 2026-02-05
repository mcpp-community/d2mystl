#include <gtest/gtest.h>

import mySTL.array;

// Test the size of non-empty array
TEST(ArrayTest, SizeTest)
{
    mySTL::Array<int, 5> arr;
    EXPECT_EQ(arr.size(), 5);
}

// Test the capacity of non-empty array
TEST(ArrayTest, CapacityTest)
{
    mySTL::Array<int, 10> arr;
    EXPECT_EQ(arr.capacity(), 10);
}

// Test whether the array is empty
TEST(ArrayTest, EmptyTest)
{
    mySTL::Array<int, 5> arr;
    EXPECT_FALSE(arr.empty());

    mySTL::Array<int, 0> empty_arr;
    EXPECT_TRUE(empty_arr.empty());
}

// Test subscript operator access
TEST(ArrayTest, SubscriptOperatorTest)
{
    mySTL::Array<int, 5> arr;
    arr[0] = 10;
    arr[4] = 50;
    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[4], 50);
}

// Test subscript operator of const array
TEST(ArrayTest, ConstSubscriptOperatorTest)
{
    const mySTL::Array<int, 3> arr;
    EXPECT_EQ(arr[0], 0);
}

// Test at method normal access
TEST(ArrayTest, AtMethodValidAccessTest)
{
    mySTL::Array<int, 5> arr;
    arr.at(0) = 20;
    arr.at(4) = 60;
    EXPECT_EQ(arr.at(0), 20);
    EXPECT_EQ(arr.at(4), 60);
}

// Test at method out of range exception
TEST(ArrayTest, AtMethodOutOfRangeTest)
{
    mySTL::Array<int, 5> arr;
    EXPECT_THROW(arr.at(5), std::out_of_range);
    EXPECT_THROW(arr.at(100), std::out_of_range);
}

// Test at method usage in const array
TEST(ArrayTest, ConstAtMethodTest)
{
    const mySTL::Array<int, 5> arr;
    EXPECT_NO_THROW({ [[maybe_unused]] const int &val = arr.at(0); });
    EXPECT_THROW(arr.at(5), std::out_of_range);
}

// Test different types of Array
TEST(ArrayTest, DifferentTypesTest)
{
    mySTL::Array<double, 3> double_arr;
    double_arr[0] = 3.14;
    EXPECT_DOUBLE_EQ(double_arr[0], 3.14);
    mySTL::Array<char, 4> char_arr;
    char_arr[0] = 'A';
    EXPECT_EQ(char_arr[0], 'A');
}

// Test specialization of zero-size array
TEST(ArrayTest, ZeroSizeArrayTest)
{
    mySTL::Array<int, 0> arr;
    EXPECT_EQ(arr.size(), 0);
    EXPECT_TRUE(arr.empty());
}

namespace 
{
    template <typename T>
    concept HasSubscript = requires(T t) { { t[0] }; };
    template <typename T>
    concept HasAt = requires(T t) { { t.at(0) }; };
}

// Test that Array<T,0> does not have operator[] or at
TEST(ArrayTest, ZeroSizeArrayNoSubscriptOrAt)
{
    EXPECT_FALSE((HasSubscript<mySTL::Array<int, 0>>));
    EXPECT_FALSE((HasAt<mySTL::Array<int, 0>>));
}
