//! Length of Last Word in a String LeetCode

// Question Link:
//

#include <iostream>
#include <string>
using namespace std;
int lengthOfLastWord(string s) {
  int n = s.size();
  int length = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] != ' ') {
      length++;
    } else if (length > 0) {
      break;
    }
  }
  return length;
}
int main() {
  string s;
  getline(cin, s);
  cout << lengthOfLastWord(s) << endl;
  return 0;
} 