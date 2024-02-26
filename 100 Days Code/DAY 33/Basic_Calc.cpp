//! Basic Calculator (Leetcode 224)

// Question Link:
// https://leetcode.com/problems/basic-calculator/

#include <bits/stdc++.h>
using namespace std;

int calculate(string s) {
  long long int sum = 0;
  int sign = 1;
  stack<pair<int, int>> st;

  for (int i = 0; i < s.size(); i++) {
    if (isdigit(s[i])) {
      long long int num = 0;
      while (i < s.size() && isdigit(s[i])) {
        num = num * 10 + (s[i] - '0');
        i++;
      }
      i--;
      sum += num * sign;
      sign = 1;
    } else if (s[i] == '(') {
      st.push({sum, sign});
      sum = 0;
      sign = 1;
    } else if (s[i] == ')') {
      sum = st.top().first + (st.top().second * sum);
      st.pop();

    } else if (s[i] == '-') {
      sign = -1 * sign;
    }
  }
  return sum;
}

int main() {
  string s;
  cin >> s;
  cout << calculate(s) << endl;
  return 0;
}