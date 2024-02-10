//! Daily Temperatures (LeetCode 739)

// Question Link:
// https://leetcode.com/problems/daily-temperatures/

#include <bits/stdc++.h>
using namespace std;
vector<int> dailyTemperatures(vector<int> &temperatures) {
  int n = temperatures.size();
  vector<int> ans(n);

  for (int i = n - 2; i >= 0; i--) {
    // aage ke element se compare krne ke liye
    int j = i + 1;
    while (j < n && temperatures[i] >= temperatures[j])
      j += ans[j] ? ans[j] : n;
    /*
    if ans[j] is 0 it means no element are greater than it so, we don't want to
    update our ans,(j < n) is condition for updating ans, so we'll just add n to
    j, making sure our ans[j] remains 0.

    In Simple words, we are skipping the elements which are smaller than the
    current element and are already having ans[j] as 0.
    */
    if (j < n)
      ans[i] = j - i;
  }
  return ans;
}
int main() {
  vector<int> temperatures;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    temperatures.push_back(temp);
  }
  vector<int> ans = dailyTemperatures(temperatures);
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}