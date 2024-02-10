//! Boats to save people (Leetcode 881)

// Question Link:
// https://leetcode.com/problems/boats-to-save-people/

#include <bits/stdc++.h>
using namespace std;
int numRescueBoats(vector<int> &people, int limit) {
  sort(people.begin(), people.end());

  int i = 0, j = people.size() - 1, count = 0;

  while (i <= j) {
    // lightest person + heaviest person sum <= limit they can go together
    if (people[i] + people[j] <= limit) {
      ++i;
      --j;
    }
    // if sum is over the limit, heaviest will go alone.
    else
      --j;

    ++count; // number of boats
  }

  return count;
}
int main() {
  vector<int> people;
  int n, limit;
  cin >> n >> limit;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    people.push_back(temp);
  }
  cout << numRescueBoats(people, limit);
  return 0;
}