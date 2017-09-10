#include <vector>

void insertion_sort(std::vector<int> &input) {
  for (int i = 1; i < input.size(); i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (input[j] > input[j + 1]) {
        std::swap(input[j], input[j + 1]);
      } else {
        break;
      }
    }
  }
}

/* In-place merge step. */
void merge(std::vector<int> &input, int start, int mid, int end) {
	int index1 = start;
	int index2 = mid;
	while (true) {
		if (input[index1] < input[index2]) {
			index1++;
		} else {
			index2++;
		}
	}
}

/* Not in-place merge step. */
std::vector<int> merge(std::vector<int> vector1, std::vector<int> vector2) {
	int index1 = 0;
	int index2 = 0;
	std::vector<int> result;
	while (index1 < vector1.size() && index2 < vector2.size()) {
		if (vector1[index1] < vector2[index2]) {
			result.push_back(vector1[index1++]);
		}
		else {
			result.push_back(vector2[index2++]);
		}
	}
	while (index1 < vector1.size()) {
		result.push_back(vector1[index1++]);
	}
	while (index2 < vector2.size()) {
		result.push_back(vector2[index2++]);
	}
	return result;
}

std::vector<int> merge_sort(std::vector<int> &input, int start, int end) {
	if (start >= end - 1) {
		std::vector<int> result{ input[start] };
		return result;
	} else {
		int mid = (start + end) / 2;
		std::vector<int> first_half = merge_sort(input, start, mid);
		std::vector<int> second_half = merge_sort(input, mid, end);
		return merge(first_half, second_half);
	}
}

std::vector<int> merge_sort(std::vector<int> &input) {
	return merge_sort(input, 0, input.size());
}