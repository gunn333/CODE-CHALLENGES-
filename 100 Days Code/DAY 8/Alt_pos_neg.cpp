//! Alternate positive and negative numbers in an array

#include <bits/stdc++.h>
using namespace std;
void rearrange(int arr[], int n) {
  vector<int> pos;
  vector<int> neg;
  for (int i = 0; i < n; i++) {
    if (arr[i] >= 0) {
      pos.push_back(arr[i]);
    } else {
      neg.push_back(arr[i]);
    }
  }
  int iPos = 0, iNeg = 0, iArr = 0;  // Indexes
  while (iPos < pos.size() &&
         iNeg < neg.size()) {  // Check if both indexes are in vector range
    arr[iArr] = pos[iPos];     // Insert positive number
    iArr++;
    iPos++;
    arr[iArr] = neg[iNeg];
    iArr++;
    iNeg++;
  }
  while (iPos < pos.size()) {  // If negative vector is finished
    arr[iArr++] = pos[iPos++];
  }
  while (iNeg < neg.size()) {
    arr[iArr++] = neg[iNeg++];
  }
}
