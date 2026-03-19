#include <gtest/gtest.h>

import mySTL.iterator;

namespace {

using TestPointerBaseTypes =
    ::testing::Types<char, short, int, long, long long, float, double,
                     long double, unsigned char, unsigned short, unsigned int,
                     unsigned long, unsigned long long>;

template <typename N>
class IteratorTest : public ::testing::Test {};

} // namespace

TYPED_TEST_SUITE(IteratorTest, TestPointerBaseTypes);

TYPED_TEST(IteratorTest, IteratorConcept) {
    using PointerType = TypeParam*;
    using ConstPointerType = const TypeParam*;

    EXPECT_TRUE(mySTL::iterator::Iterator<PointerType>);
    EXPECT_TRUE(mySTL::iterator::Iterator<ConstPointerType>);
}

TYPED_TEST(IteratorTest, FowardIteratorConcept) {
    using PointerType = TypeParam*;
    using ConstPointerType = const TypeParam*;

    EXPECT_TRUE(mySTL::iterator::ForwardIterator<PointerType>);
    EXPECT_TRUE(mySTL::iterator::ForwardIterator<ConstPointerType>);
}

TYPED_TEST(IteratorTest, BidirectionalIteratorConcept) {
    using PointerType = TypeParam*;
    using ConstPointerType = const TypeParam*;

    EXPECT_TRUE(mySTL::iterator::BidirectionalIterator<PointerType>);
    EXPECT_TRUE(mySTL::iterator::BidirectionalIterator<ConstPointerType>);
}

TYPED_TEST(IteratorTest, RandomAccessIteratorConcept) {
    using PointerType = TypeParam*;
    using ConstPointerType = const TypeParam*;

    EXPECT_TRUE(mySTL::iterator::RandomAccessIterator<PointerType>);
    EXPECT_TRUE(mySTL::iterator::RandomAccessIterator<ConstPointerType>);
}
