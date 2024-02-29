//! Relative Ranks (LeetCode 506)

// Question Link:
// https://leetcode.com/problems/relative-ranks/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<string> findRelativeRanks(vector<int> &score) {
  vector<int> copy(score);
  vector<string> ans;
  sort(copy.begin(), copy.end(), greater<int>());

  for (int i = 0; i < score.size(); i++) {
    auto it = find(copy.begin(), copy.end(), score[i]);
    int position = it - copy.begin();

    if (position == 0) {
      ans.push_back("Gold Medal");
    } else if (position == 1) {
      ans.push_back("Silver Medal");
    } else if (position == 2) {
      ans.push_back("Bronze Medal");
    } else {
      ans.push_back(to_string(position + 1));
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> score(n);
  for (int i = 0; i < n; i++) {
    cin >> score[i];
  }
  vector<string> ans = findRelativeRanks(score);
  for (auto i : ans) {
    cout << i << " ";
  }
  return 0;
}