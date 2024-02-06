//! Roman to Integer geeksforgeeks

// Question Link:
// https://www.geeksforgeeks.org/problems/roman-number-to-integer3201/1?page=1&difficulty%5B%5D=0&category%5B%5D=Strings&sortBy=submissions

#include <iostream>
#include <string>
using namespace std;
int charToInt(char c) {
  switch (c) {
  case 'I':
    return 1;
  case 'V':
    return 5;
  case 'X':
    return 10;
  case 'L':
    return 50;
  case 'C':
    return 100;
  case 'D':
    return 500;
  case 'M':
    return 1000;
  }
}
int romanToDecimal(string &str) {
  int res = 0;
  for (int i = 0; i < str.length(); i++) {
    int s1 = charToInt(str[i]);

    // Agar ek se jyada Roman numeral hai toh uska value add karna hai
    if (i + 1 < str.length()) {
      // Next Numeral ko bhi convert kar diya
      int s2 = charToInt(str[i + 1]);
      // Like "VI" me V=5 and I=1 so V > I so res = 0 + 5 = 5
      if (s1 >= s2) {
        res = res + s1;
      } else {
        // Like "IV" me I=1 and V=5 so I < V so res = 5 - 1 = 4
        res = res + s2 - s1;
        i++;
      }
    } else { // Agar ek hi Roman numeral hai toh uska value add karna hai
      res = res + s1;
    }
  }
  return res;
}
