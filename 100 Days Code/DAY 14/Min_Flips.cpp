//! Minimum Number of Flips

// Question Link:
// https://www.geeksforgeeks.org/problems/min-number-of-flips3210/1?page=2&difficulty%5B%5D=0&category%5B%5D=Strings&sortBy=submissions

#include <iostream>
#include <string>
using namespace std;
int minFlips(string S) {
  int n = S.size(), flip = 0, i = 0;

  while (i < S.size()) {

    char expected_char;
    // Agar expected_char even index pe hai toh '0' hoga u can do by 1 as well
    // doesn't matter
    if (i % 2 == 0) {
      expected_char = '0';
    } else {
      expected_char = '1';
    }
    // agar S[i] != expected_char hai toh flip++ krdo
    if (S[i] != expected_char) {
      flip++;
    }
    i++;
  }
  // min(n-flip, flip) isliye kiya hai kyunki agar flip > n-flip hai toh hum
  // n-flip krke bhi same result laa skte hain so we will take min of both
  // n-flip is kitne flip nhi kiye hain aur flip is kitne flip kiye hain
  return min(n - flip, flip);
}
int main() {
  string s = "0001010111";
  cout << minFlips(s) << endl;
  return 0;
}