//! Number of Students Unable to Eat Lunch (LeetCode 1700)

// Question Link:
// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &students, vector<int> &sandwitches) {
  // del is used to check if any student is unable to eat lunch
  //   del = 1 means there is a student who is unable to eat lunch
  bool del = 1;

  // While del is true we will check if any student is unable to eat lunch
  while (del) {
    // marking del as false initially
    del = 0;

    for (int i = 0; i < students.size(); i++) {
      // If student[i] == sandwitches[0] then student[i] can eat the
      // sandwitches[0]
      if (students[i] == sandwitches[0]) {
        // students.erase(students.begin() + i) will remove the student[i] from
        // the students vector as he/she has eaten the sandwitches[0]
        students.erase(students.begin() + i);
        // students.begin() + i because we want to remove the student[i] from
        // the students  vector not the first element
        i--;
        // sandwitches.erase(sandwitches.begin()) will remove the first element
        // of the sandwitches vector as it has been eaten by the student[i]
        sandwitches.erase(sandwitches.begin());
        // sandwitches.begin() because we want to remove the first element of
        // the sandwitches vector del = 1 keeps the loop running until all the
        // students are able to eat lunch
        del = 1;
      }
    }
  }
  //   students.size() will return the number of students who are unable to eat
  //   lunch as the students vector will have the students who are unable to eat
  //   lunch
  return students.size();
}

int main() {
  vector<int> students = {1, 1, 0, 0};
  vector<int> sandwitches = {0, 1, 0, 1};

  cout << countStudents(students, sandwitches) << endl;
  return 0;
}