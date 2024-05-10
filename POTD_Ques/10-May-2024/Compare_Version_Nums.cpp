//! Compare Version Numbers (Leetcode 165)

// Question Link:
// https://leetcode.com/problems/compare-version-numbers/

#include <bits/stdc++.h>
using namespace std;

int compareVersion(string version1, string version2) {
  vector<int> v1, v2;
  string temp = "";
  for (int i = 0; i < version1.size(); i++) {
    if (version1[i] == '.') {
      v1.push_back(stoi(temp));
      temp = "";
    } else {
      temp += version1[i];
    }
  }
  v1.push_back(stoi(temp));
  temp = "";
  for (int i = 0; i < version2.size(); i++) {
    if (version2[i] == '.') {
      v2.push_back(stoi(temp));
      temp = "";
    } else {
      temp += version2[i];
    }
  }
  v2.push_back(stoi(temp));
  int i = 0;
  while (i < v1.size() && i < v2.size()) {
    if (v1[i] > v2[i]) {
      return 1;
    } else if (v1[i] < v2[i]) {
      return -1;
    }
    i++;
  }
  while (i < v1.size()) {
    if (v1[i] > 0) {
      return 1;
    }
    i++;
  }
  while (i < v2.size()) {
    if (v2[i] > 0) {
      return -1;
    }
    i++;
  }
  return 0;
}

int main() {
  string version1 = "1.0.1";
  string version2 = "1";
  cout << compareVersion(version1, version2) << endl;
  return 0;
}