//! UTF-8 Validation (Leetcode 393)

// Question Link:
// https://leetcode.com/problems/utf-8-validation/

#include <bits/stdc++.h>
#include <vector>
using namespace std;
bool validUtf8(vector<int> &data) {
  int cnt = 0; // Number of leading 1s encountered

  // Iterate through each integer in the data vector
  for (int i = 0; i < data.size(); i++) {
    int cur = data[i]; // Current integer being processed

    // Count the number of leading 1s in the current integer
    if (cnt == 0) {
      if ((cur & 128) == 0) {
        continue; // Current byte is a single-byte character
      } else if ((cur & 224) == 192) {
        cnt = 1; // Two-byte character
      } else if ((cur & 240) == 224) {
        cnt = 2; // Three-byte character
      } else if ((cur & 248) == 240) {
        cnt = 3; // Four-byte character
      } else {
        return false; // Invalid UTF-8 encoding
      }
    } else {
      // Check if the current byte is a continuation byte
      if ((cur & 192) != 128) {
        return false; // Invalid UTF-8 encoding
      }
      cnt--; // Decrement the count of leading 1s
    }
  }

  // If cnt is 0, all UTF-8 characters are properly terminated
  return cnt == 0;
}

int main() {
  vector<int> data = {197, 130, 1};
  cout << validUtf8(data) << endl;
  return 0;
}