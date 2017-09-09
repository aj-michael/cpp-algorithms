#include <string>
#include <vector>

std::vector<int> kmp_prefix_table(std::string pattern) {
  std::vector<int> table;
  table.push_back(0);
  int k = 0;
  for (int q = 1; q < pattern.length(); q++) {
    while (k > 0 && pattern[k] != pattern[q]) {
      k = table[k];
    }
    if (pattern[k] == pattern[q]) {
      k++;
    }
    table.push_back(k);
  }
  return table;
}

// An implementation of the Knuth-Morris-Pratt algorithm.
std::vector<int> kmp(std::string text, std::string pattern) {
  std::vector<int> match_indexes;
  if (text.length() < pattern.length()) {
    return match_indexes;
  }
  std::vector<int> prefix_table = kmp_prefix_table(pattern);
  int q = 0;
  for (int i = 0; i < text.length(); i++) {
    while (q > 0 && pattern[q] != text[i]) {
      q = prefix_table[q];
    }
    if (pattern[q] == text[i]) {
      q++;
    }
    if (q == pattern.length()) {
      match_indexes.push_back(i + 1 - pattern.length());
      q = prefix_table[q - 1];
    }
  }
  return match_indexes;
}

