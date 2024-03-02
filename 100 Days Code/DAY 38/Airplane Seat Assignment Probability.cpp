//! Airplane Seat Assignment Probability (LeetCode 1227)

// Question Link:
// https://leetcode.com/problems/airplane-seat-assignment-probability/

#include <bits/stdc++.h>
using namespace std;

double nthPersonGetsNthSeat(int n) {
  // seat -> seat number
  int seat = -1;
  // if n == 1, then the single person will get the seat
  if (n == 1) {
    seat = 1;
  }
  // n != 1, check krega kya 1 se jyada passengers hai
  // seat!=1, check krega kya 1st passenger ne apni seat nhi li
  if (n != 1 && seat != 1) {
    return 1.0 / 2;
  } else {
    return 1.0 / n;
  }
}

int main() {
  int n = 4;
  cout << nthPersonGetsNthSeat(n);
  return 0;
}