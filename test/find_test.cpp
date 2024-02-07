#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <vector>
#include <fnl/find.hpp>

using namespace fnl;
using namespace ::testing;

class FindTest : public Test {
public:
  void SetUp() override {
    vec = { 1, 2, 3 };
  }

  const auto& sut() const {
    return vec;
  }

private:
  std::vector<int> vec;
};

TEST_F(FindTest, FindShouldReturnNonEmptyOptionIterForMatchingPredicate) {
  EXPECT_TRUE(find(sut(), [](int){ return true; }));
}

TEST_F(FindTest, FindShouldReturnIteratorPointingToElementForMatchingPredicate) {
  EXPECT_EQ(find(sut(), [](int v){ return v == 2; }).base(), sut().begin() + 1);
}

TEST_F(FindTest, FindShouldReturnEmptyIteratorForMissingPredicate) {
  EXPECT_FALSE(find(sut(), [](int){ return false; }));
}
