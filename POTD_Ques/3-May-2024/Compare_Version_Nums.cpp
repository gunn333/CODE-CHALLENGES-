//! Compare Versions Numbers - LeetCode 165

// Question Link:
// https://leetcode.com/problems/compare-version-numbers/

#include <bits/stdc++.h>
using namespace std;

int compareVersion(string version1, string version2) {
  vector<int> v1, v2;
  // temp is used to store the version number
  string temp = "";
  // Split the version 1
  for (int i = 0; i < version1.size(); i++) {
    // If we get a '.' then we push the version number to the vector
    if (version1[i] == '.') {
      // stoi is used to convert string to integer
      v1.push_back(stoi(temp));
      // Clear the temp string
      temp = "";
    } else {
      // If we don't get '.' then we add the number to the temp string
      temp += version1[i];
    }
  }
  // Push the last version number to the vector
  v1.push_back(stoi(temp));
  temp = "";
  // Split the version 2
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
  // Compare the version numbers
  // i < v1.size() && i < v2.size() is used to compare the version numbers till
  // the end of the smaller version number
  while (i < v1.size() && i < v2.size()) {
    if (v1[i] > v2[i]) {
      return 1;
    } else if (v1[i] < v2[i]) {
      return -1;
    }
    // Increment i to compare the next version number
    i++;
  }
  // If v2 is empty and v1 is not empty then return 1
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
  // Test cases
  cout << compareVersion("1.01", "1.001") << endl;
  cout << compareVersion("1.0", "1.0.0") << endl;
  cout << compareVersion("0.1", "1.1") << endl;
  cout << compareVersion("1.0.1", "1") << endl;

  return 0;
}
