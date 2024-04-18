//! Two Repeated Elements (GeeeksforGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/two-repeated-elements-1587115621/1

#include <bits/stdc++.h>
using namespace std;

vector<int> twoRepeated(int arr[], int N) {
  // map<key, value> to store the frequency of each element
  unordered_map<int, int> mp;
  vector<int> res;
  // N+2 tak loop chalayenge because 2 elements are repeated
  for (int i = 0; i < N + 2; i++) {
    // key is the element of the array
    int key = arr[i];
    // mp[key] will store the frequency of the element
    mp[key]++;
    if (mp[key] == 2)
      res.push_back(key);
  }
  return res;
}

int main() {
  int N = 4;
  int arr[] = {1, 2, 1, 3, 4, 3};
  vector<int> res = twoRepeated(arr, N);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  return 0;
}