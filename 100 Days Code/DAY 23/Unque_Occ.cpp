//! Unique Number of Occurrences (Leetcode 1207)

// Question Link:
// https://leetcode.com/problems/unique-number-of-occurrences/

#include <bits/stdc++.h>
using namespace std;
bool uniqueOccurrences(std::vector<int> &arr) {
  int i = 0;
  std::sort(arr.begin(), arr.end());
  std::vector<int> ans;

  while (i < arr.size()) {
    int count = 1;

    for (int j = i + 1; j < arr.size(); j++) {
      if (arr[i] == arr[j]) {
        count++;
      } else {
        break; // Break when the next element is different
      }
    }

    ans.push_back(count);
    i = i + count;
  }

  std::sort(ans.begin(), ans.end());

  for (int i = 0; i < ans.size() - 1; i++) {
    if (ans[i] == ans[i + 1]) {
      return false;
    }
  }

  return true;
}

int main() {
  std::vector<int> arr = {1, 2, 2, 1, 1, 3};
  std::cout << uniqueOccurrences(arr);
  return 0;
}