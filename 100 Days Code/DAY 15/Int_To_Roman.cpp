//! Integer to Roman (LeetCode - 12)

// Question Link:
// https://leetcode.com/problems/integer-to-roman/

#include <iostream>
using namespace std;
string intToRoman(int num) {
  string ans = "";
  string romanSymbol[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                          "XL", "X",  "IX", "V",  "IV", "I"};
  int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

  for (int i = 0; i < 13; i++) {
    while (num >= values[i]) {
      ans += romanSymbol[i];
      num -= values[i];
    }
  }
  return ans;
}
int main() {
  int num;
  cin >> num;
  cout << intToRoman(num);
  return 0;
}
/*
Approach:
1. isme humne ek array banaya hai jisme roman ke symbol hai.
2. aur ek array banaya hai jisme unke values hai
3. ab humne ek loop chalaya hai jisme humne dekha ki agar number usse bada ya
   equal hai toh uska symbol add kardo aur uska value minus kardo.
4. aur aise hi chalte jao jab tak number 0 nahi ho jata.
5. aur fir ans return kardo.
*/