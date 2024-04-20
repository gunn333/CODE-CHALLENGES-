//! Find Missing in Second Array (GeeksForGeeks POTD)

// Question Link :
// https://www.geeksforgeeks.org/problems/in-first-but-second5423/1

#include <bits/stdc++.h>
using namespace std;

vector<int> findMissing(int A[], int B[], int N, int M) {
  unordered_set<int> s;
  for (int i = 0; i < M; i++) {
    s.insert(B[i]);
  }
  vector<int> res;
  for (int i = 0; i < N; i++) {
    // If the element is not present in the set, then push it to the result
    // vector
    if (s.find(A[i]) == s.end()) {
      res.push_back(A[i]);
    }
  }
  return res;
}

int main() {
  int N = 5, M = 4;
  int A[] = {1, 2, 3, 4, 5};
  int B[] = {1, 2, 3, 4};
  vector<int> res = findMissing(A, B, N, M);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  return 0;
}