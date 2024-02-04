//! Check if a string is a rotation of another string

#include <iostream>
#include <string>
using namespace std;
bool isRotation(string s1, string s2) {
  if (s1 == s2) {
    return true;
  }
  if (s1.size() != s2.size())
    return false;
  s1 = s1 + s1;
  if (s1.find(s2) == -1) {
    return false;
  }
  return true;
}
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  cout << isRotation(s1, s2);
  return 0;
}