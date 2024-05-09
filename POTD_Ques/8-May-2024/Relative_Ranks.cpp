//! Relative Ranks (LeetCode 506)

// Question Link :
// https://leetcode.com/problems/relative-ranks/

#include <bits/stdc++.h>
using namespace std;

vector<string> findRelativeRanks(vector<int> &score) {
  int n = score.size();
  // This vector will store the index of the score and the score itself
  vector<pair<int, int>> temp;
  for (int i = 0; i < n; i++) {
    temp.push_back({score[i], i});
  }
  // Sorting the scores in descending order
  sort(temp.begin(), temp.end());
  reverse(temp.begin(), temp.end());
  
  vector<string> res(n);
  // temp[0].second will be the index of the highest score
  res[temp[0].second] = "Gold Medal";
  if (n > 1) {
    // temp[1].second will be the index of the second highest score
    res[temp[1].second] = "Silver Medal";
  }
  if (n > 2) {
    // temp[2].second will be the index of the third highest score
    res[temp[2].second] = "Bronze Medal";
  }
  for (int i = 3; i < n; i++) {
    // temp[i].second will be the index of the ith highest score
    res[temp[i].second] = to_string(i + 1);
  }
  return res;
}

int main() {
  vector<int> score = {5, 4, 3, 2, 1};
  vector<string> res = findRelativeRanks(score);
  for (string s : res) {
    cout << s << " ";
  }
  return 0;
}