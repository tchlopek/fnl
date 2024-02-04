#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <fnl/hashmap.hpp>

using namespace fnl;
using namespace ::testing;

class HashmapTest : public Test {
public:
  void SetUp() override {
      hp["qwerty"] = 1;
      hp["asd"] = 2;
  }

  auto sut() const {
    return hp;
  }

private:
  hashmap<std::string, int> hp;
};

TEST_F(HashmapTest, FindPresentKey) {
  EXPECT_THAT(sut().find("qwerty"), Optional(Pair(_, Eq(1))));
  EXPECT_THAT(sut().find("asd"), Optional(Pair(_, Eq(2))));
}

TEST_F(HashmapTest, FindMissingKey) {
  EXPECT_FALSE(sut().find("missing key"));
}

TEST_F(HashmapTest, ContainsReturnsTrueForPresentKey) {
  EXPECT_TRUE(sut().contains("qwerty"));
  EXPECT_TRUE(sut().contains("asd"));
}

TEST_F(HashmapTest, ContainsReturnsFalseForMissingKey) {
  EXPECT_FALSE(sut().contains("missing key"));
}
