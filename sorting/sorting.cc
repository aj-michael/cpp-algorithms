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
