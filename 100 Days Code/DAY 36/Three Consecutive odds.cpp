//! Three Consecutive Odds (LeetCode 1550)

// Question Link:
// https://leetcode.com/problems/three-consecutive-odds/

#include <iostream>
#include <vector>
using namespace std;

bool threeConsecutiveOdds(vector<int> &arr) {
  int n = arr.size();
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 == 1) {
      count++;
      if (count >= 3)
        return true;
    } else {
      count = 0;
    }
  }
  return 0;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << threeConsecutiveOdds(arr) << endl;
  return 0;
}