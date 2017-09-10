#include "gmock/gmock.h"
#include "sorting.h"

using ::testing::ElementsAre;
using ::testing::IsEmpty;

TEST(InsertionSortTest, AlreadySorted) {
  std::vector<int> v { 1, 2, 3, 4, 5 };
  insertion_sort(v);
  ASSERT_THAT(v, ElementsAre(1, 2, 3, 4, 5));
}

TEST(InsertionSortTest, Backwards) {
  std::vector<int> v { 5, 4, 3, 2, 1 };
  insertion_sort(v);
  ASSERT_THAT(v, ElementsAre(1, 2, 3, 4, 5));
}

TEST(MergeSortTest, AlreadySorted) {
	std::vector<int> v{ 1, 2, 3, 4, 5 };
	merge_sort(v);
	ASSERT_THAT(v, ElementsAre(1, 2, 3, 4, 5));
}

TEST(MergeSortTest, ContainsDuplicates) {
	std::vector<int> v{ 2, 1, 3, 2, 4, 3 };
	ASSERT_THAT(merge_sort(v), ElementsAre(1, 2, 2, 3, 3, 4));
}

TEST(MergeSortTest, Backwards) {
	std::vector<int> v{ 5, 4, 3, 2, 1 };
	ASSERT_THAT(merge_sort(v), ElementsAre(1, 2, 3, 4, 5));
}
