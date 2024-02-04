#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <vector>

#include <fnl/util/option_iter.hpp>

using namespace fnl::util;
using namespace ::testing;

using iter_t = std::vector<int>::iterator;

TEST(OptionIterTest, ConvertsToFalseOnDefaultCtor) {
    EXPECT_FALSE(option_iter<iter_t>{});
}

TEST(OptionIterTest, ConvertsToTrueOnAnyIterator) {
    EXPECT_TRUE(option_iter{ iter_t{} });
}

TEST(OptionIterTest, EqCompareWithSameIterators) {
    std::vector v{ 1 };
    EXPECT_EQ(option_iter{ v.begin() }, option_iter{ v.begin() });
}

TEST(OptionIterTest, NotEqCompareWithDifferentIterators) {
    std::vector v{ 1 };
    EXPECT_NE(option_iter{ v.begin() }, option_iter{ v.end() });
}

TEST(OptionIterTest, BaseReturnsOriginalIterator) {
    std::vector v{ 1 };
    EXPECT_EQ(option_iter{ v.begin() }.base(), v.begin());
}

TEST(OptionIterTest, CanAsteriskDereference) {
    std::vector v{ 123 };
    EXPECT_EQ(*option_iter{ v.begin() }, 123);
}

struct Dummy { int val; };

TEST(OptionIterTest, CanArrowDereference) {
    std::vector v{ Dummy{ 123 } };
    EXPECT_EQ(option_iter{ v.begin() }->val, 123);
}
