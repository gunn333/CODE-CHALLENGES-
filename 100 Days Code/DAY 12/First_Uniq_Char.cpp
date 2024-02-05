// First Unique Character in a String LeetCode 387

// Question Link:
// https://leetcode.com/problems/first-unique-character-in-a-string/?envType=daily-question&envId=2024-02-05

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int firstUniqChar(string s) {
  int c[26]; // Array jisme har character ki frequency store hogi
  // yeah loop s[i] != '\0' tak chalega matlab jab tak string khatam nahi hoti
  // '\0' is the null character jo string ke end ko represent karta hai
  for (int i = 0; s[i] != '\0'; i++) {
    // s[i] - 'a' se character ki ASCII value se 97 subtract ho jayegi
    // jaise 'a' ki ASCII value 97 hai toh 97 - 97 = 0
    // c[0]++ se c[0] ki value 1 ho jayegi
    c[s[i] - 'a']++;
  }
  for (int i = 0; s[i] != '\0'; i++) {
    if (c[s[i] - 'a'] == 1) {
      return i;
    }
  }
  return -1;
}
int main() {
  string str;
  cin >> str;
  cout << firstUniqChar(str);
  return 0;
}