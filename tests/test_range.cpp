#include <gtest/gtest.h>

import mySTL.range;
import mySTL.array;

namespace {

using TestPointerBaseTypes =
    ::testing::Types<char, short, int, long, long long, float, double,
                     long double, unsigned char, unsigned short, unsigned int,
                     unsigned long, unsigned long long>;

template <typename N>
class RangeTest : public ::testing::Test {};

} // namespace

TYPED_TEST_SUITE(RangeTest, TestPointerBaseTypes);

TYPED_TEST(RangeTest, CArrayRange) {
    EXPECT_FALSE(mySTL::range::Range<TypeParam[]>);
    EXPECT_TRUE(mySTL::range::Range<TypeParam[5]>);

    EXPECT_FALSE(mySTL::range::Range<const TypeParam[]>);
    EXPECT_TRUE(mySTL::range::Range<const TypeParam[5]>);
}

TYPED_TEST(RangeTest, CArrayIterRange) {
    EXPECT_FALSE(mySTL::range::IterRange<TypeParam[]>);
    EXPECT_TRUE(mySTL::range::IterRange<TypeParam[5]>);

    EXPECT_FALSE(mySTL::range::IterRange<const TypeParam[]>);
    EXPECT_TRUE(mySTL::range::IterRange<const TypeParam[5]>);
}

TYPED_TEST(RangeTest, MySTLArrayRange) {
    EXPECT_TRUE((mySTL::range::Range<mySTL::Array<TypeParam, 0>>));
    EXPECT_TRUE((mySTL::range::Range<mySTL::Array<TypeParam, 5>>));

    EXPECT_TRUE((mySTL::range::Range<const mySTL::Array<TypeParam, 0>>));
    EXPECT_TRUE((mySTL::range::Range<const mySTL::Array<TypeParam, 5>>));
}

TYPED_TEST(RangeTest, MySTLArrayIterRange) {
    EXPECT_TRUE((mySTL::range::IterRange<mySTL::Array<TypeParam, 0>>));
    EXPECT_TRUE((mySTL::range::IterRange<mySTL::Array<TypeParam, 5>>));

    EXPECT_TRUE((mySTL::range::IterRange<const mySTL::Array<TypeParam, 0>>));
    EXPECT_TRUE((mySTL::range::IterRange<const mySTL::Array<TypeParam, 5>>));
}

TYPED_TEST(RangeTest, MySTLArrayRangeFor) {
    mySTL::Array<TypeParam, 5> arr {};

    for ([[maybe_unused]] auto& e : arr) {
    }

    for ([[maybe_unused]] const auto& e : arr) {
    }

    for ([[maybe_unused]] auto&& e : arr) {
    }

    const mySTL::Array<TypeParam, 5> c_arr {};

    for ([[maybe_unused]] auto& e : c_arr) {
    }

    for ([[maybe_unused]] const auto& e : c_arr) {
    }

    for ([[maybe_unused]] auto&& e : c_arr) {
    }

    SUCCEED();
}

TYPED_TEST(RangeTest, MySTLArraySize0RangeFor) {
    mySTL::Array<TypeParam, 0> arr {};

    for ([[maybe_unused]] auto& e : arr) {
    }

    for ([[maybe_unused]] const auto& e : arr) {
    }

    for ([[maybe_unused]] auto&& e : arr) {
    }

    const mySTL::Array<TypeParam, 5> c_arr {};

    for ([[maybe_unused]] auto& e : c_arr) {
    }

    for ([[maybe_unused]] const auto& e : c_arr) {
    }

    for ([[maybe_unused]] auto&& e : c_arr) {
    }

    SUCCEED();
}