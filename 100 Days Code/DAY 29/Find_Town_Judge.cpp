//! Find the Town Judge (LeetCode 997)

// Question Link:
// https://leetcode.com/problems/find-the-town-judge/

#include <iostream>
#include <vector>
using namespace std;

int findJudge(int n, vector<vector<int>> &trust) {
  vector<int> whoTrustYou(n + 1);

  for (int i = 0; i < trust.size(); i++) {
    whoTrustYou[trust[i][0]] = -1; // impossible to be town judge
    if (whoTrustYou[trust[i][1]] != -1)
      whoTrustYou[trust[i][1]]++;
  }

  for (int i = 1; i <= n; i++) {
    if (whoTrustYou[i] == n - 1)
      return i; // only 1 person satisfied
  }

  return -1;
}

int main() {
  vector<vector<int>> trust = {{1, 2}};
  cout << findJudge(2, trust) << endl; // Output: 2
  return 0;
}

/*
Logic:

1. Sabse pehle ek vector banayenge jisme hum store karenge ki kis kisne trust
kiya hai.
2. trust vector mei jo bhi trust kiya hai uske 0th index pe 
*/