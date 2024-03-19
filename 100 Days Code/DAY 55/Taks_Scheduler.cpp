//! Task Scheduler (LeetCode 621)

// Question Link:
// https://leetcode.com/problems/task-scheduler/

#include <bits/stdc++.h>
using namespace std;

int leastInterval(vector<char> &tasks, int n) {
  if (tasks.empty()) {
    return 0;
  }
  int cnt = tasks.size();
  vector<int> count(26, 0);
  for (int i = 0; i < cnt; i++) {
    count[tasks[i] - 65]++; // count for corresponding character
  }
  sort(count.begin(), count.end());

  // We do -1 becuase we dont care aboute the last occurance of
  // that task, becuase we dont need to fill anything after that as
  // it is the last task. Hence no cool down after that for it.
  int spaces_to_fill = count[25] - 1;

  // Idle slots between the same task to be filled
  // idleslots = spaces_to_fill * n isliye kiya hain kyuki agar n=2 and
  // spaces_to_fill=3 then idle slots = 3*2 = 6, toh 6 slots mei 3 task ko fit
  // kr skte hain
  int idleslots = spaces_to_fill * n;

  // We started from second most frequent task, as the most frequent task
  // already determines the maximum number of idle slots between its occurrences
  for (int i = 24; i >= 0; i--) {
    // We could fill minimum of the frequency of other task or the
    // spaces that need to be filled
    // min(spaces_to_fill, count[i]) means ki agar spaces_to_fill=3 and
    // count[i]=2 toh 2 hi fill kr skte hain, 3 nhi kr skte
    // idleslots = idleslots - min(spaces_to_fill, count[i]) means ki agar 3
    // slots mei 2 task fit ho gye toh 1 slot bacha hain toh idleslots = 1
    idleslots = idleslots - min(spaces_to_fill, count[i]);
  }

  // If idleslots > 0, then we can fill the remaining slots with tasks otherwise
  // we will return the size of the tasks as we dont need to fill any idle
  // slots.
  if (idleslots > 0) {
    return idleslots + tasks.size();
  }

  return tasks.size();
}

int main() {
  vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  int n = 2;
  cout << leastInterval(tasks, n) << endl;
  return 0;
}