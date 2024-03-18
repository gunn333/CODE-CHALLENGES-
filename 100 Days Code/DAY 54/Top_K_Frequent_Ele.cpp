//! Top K Frequent Elements (LeetCode 347)

// Question Link:
// https://leetcode.com/problems/top-k-frequent-elements/

#include <bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k) {
  sort(nums.begin(), nums.end());
  //   frequency -> (freq, element)
  vector<pair<int, int>> frequency;
  int current = nums[0];
  int def_freq = 1;
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] == current) {
      def_freq++;
    } else {
      // If the next element is different from the current element, then push
      // the current element and its frequency to the frequency vector
      frequency.push_back(make_pair(def_freq, current));
      def_freq = 1;
      current = nums[i];
    }
  }
  // Push the last element and its frequency to the frequency vector
  frequency.push_back(make_pair(def_freq, current));

  // Sort the frequency vector in descending order because we need to find the
  // top k frequent elements
  sort(frequency.begin(), frequency.end(), greater<pair<int, int>>());

  vector<int> result;
  int i = 0;
  while (i < k) {
    // frequency[i].second is the element and frequency[i].first is the frequency
    result.push_back(frequency[i].second);
    i++;
  }
  return result;
}

int main() {
  vector<int> nums = {1, 1, 1, 2, 2, 3};
  int k = 2;
  vector<int> result = topKFrequent(nums, k);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  return 0;
}