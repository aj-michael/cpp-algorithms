#include "gmock/gmock.h"
#include "sorting.h"

using ::testing::ElementsAre;
using ::testing::IsEmpty;

TEST(InsertionSortTest, AlreadySorted) {
  std::vector<int> v { 1, 2, 3, 4, 5 };
  ASSERT_THAT(insertion_sort(v), ElementsAre(1, 2, 3, 4, 5));
}

TEST(InsertionSortTest, Backwards) {
  std::vector<int> v { 5, 4, 3, 2, 1 };
  ASSERT_THAT(insertion_sort(v), ElementsAre(1, 2, 3, 4, 5));
}