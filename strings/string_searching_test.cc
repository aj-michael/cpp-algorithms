#include "gmock/gmock.h"
#include "string_searching.h"

using ::testing::ElementsAre;
using ::testing::IsEmpty;

TEST(KmpTest, TooLongNeedle) {
  ASSERT_THAT(kmp("abc", "abcd"), IsEmpty());
}

TEST(KmpTest, EasyCase) {
  ASSERT_THAT(kmp("abcd", "abc"), ElementsAre(0));
}

TEST(KmpTest, AnotherEasyCase) {
  ASSERT_THAT(kmp("ababaaba", "ba"), ElementsAre(1, 3, 6));
}

TEST(KmpTest, NoMatch) {
  ASSERT_THAT(kmp("abc", "cb"), IsEmpty());
}

TEST(KmpTest, AllMatches) {
  ASSERT_THAT(kmp("aaaaaa", "aaa"), ElementsAre(0, 1, 2, 3));
}

TEST(KmpPrefixTableTest, CLSRExample) {
  ASSERT_THAT(kmp_prefix_table("ababaca"), ElementsAre(0, 0, 1, 2, 3, 0, 1));
}
