module;

#include <gtest/gtest.h>

import mySTL.metaInfo;

// Test the name of meta information
TEST(MetaInfoTest, NameTest)
{
    EXPECT_STREQ(mySTL::metaInfo::name, "MySTL");
}

// Test the version number of meta information
TEST(MetaInfoTest, VersionTest)
{
    EXPECT_EQ(mySTL::metaInfo::version.major, 0);
    EXPECT_EQ(mySTL::metaInfo::version.minor, 1);
    EXPECT_EQ(mySTL::metaInfo::version.patch, 0);
}

// Test the description of meta information
TEST(MetaInfoTest, DescriptionTest)
{
    EXPECT_STREQ(mySTL::metaInfo::description, "My Standard Template Library");
}
