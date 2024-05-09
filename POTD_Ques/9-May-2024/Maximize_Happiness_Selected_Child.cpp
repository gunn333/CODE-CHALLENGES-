//! Maximize Happiness of Selected Childen (LeetCode 3075)

// Question Link:
// https://leetcode.com/problems/maximize-happiness-of-selected-children/description/?envType=daily-question&envId=2024-05-09

#include <bits/stdc++.h>
using namespace std;

long long maximumHappinessSum(vector<int> &happiness, int k) {
  int n = happiness.size();
  // Sorting the happiness array to get the maximum happiness
  sort(happiness.begin(), happiness.end());
  // sum to store the maximum happiness sum
  long long sum = 0;
  // count to keep track of the number of children selected
  int count = 0;
  // end to keep track of the last element of the array
  int end = n - 1;
  // Selecting the k children with maximum happiness
  while (k) {
    // If the happiness of the last child is greater than the count
    if (happiness[end] - count > 0) {
      // Add the happiness to the sum and decrement the count because the child
      // is selected
      sum += happiness[end] - count;
    }
    // Increment the count
    count++;
    end--;
    k--;
  }
  return sum;
}

int main() {
  vector<int> happiness = {1, 2, 3, 4, 5};
  int k = 2;
  cout << maximumHappinessSum(happiness, k) << endl;
  return 0;
}