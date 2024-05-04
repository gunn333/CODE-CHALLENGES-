//! Boats To Save People (LeetCode 881)

// Question Link:
// https://leetcode.com/problems/boats-to-save-people/

#include <bits/stdc++.h>
using namespace std;

int numRescueBoats(vector<int> &people, int limit) {
  // sorting the people because we want to pair the heaviest person with the
  // lightest person
  sort(people.begin(), people.end());
  // start and end pointers to keep track of the people array
  int start = 0, end = people.size() - 1;
  // boats is the number of boats required to save all the people
  int boats = 0;
  while (start <= end) {
    // if people[start] + people[end] meets the limit then we can save both the
    // people in the same boat so we move the start pointer to the next person
    // to pair with the next person
    if (people[start] + people[end] <= limit) {
      start++;
    }
    // end-- because we have to save the heaviest person in the boat so we move
    // the end pointer to the previous person to pair with the next person
    // Simply if the sum is over the limit then heaviest person will go alone
    end--;
    // increment the boats because we have saved the people in the boat
    boats++;
  }
  return boats;
}

int main() {
  vector<int> people = {3, 2, 2, 1};
  int limit = 3;
  cout << numRescueBoats(people, limit);
  return 0;
}