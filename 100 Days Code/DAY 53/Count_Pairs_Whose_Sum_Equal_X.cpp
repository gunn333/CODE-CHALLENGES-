//! Count Pairs Whose Sum Equal to X (GFG)

// Question Link:
// https://www.geeksforgeeks.org/problems/count-pairs-whose-sum-is-equal-to-x/1

#include <bits/stdc++.h>

struct Node {
  int data;
  struct Node *next;
};

using namespace std;

int countPairs(struct Node *head1, struct Node *head2, int x) {
  int count = 0;
  unordered_map<int, bool> visited;

  // Store the head pointer of the first linked list
  Node *temp = head1;

  // Traverse the first linked list and store the values in the map
  while (temp != nullptr) {
    visited[temp->data] = true;
    temp = temp->next;
  }

  // Traverse the second linked list
  while (head2 != nullptr) {
    // Check if the complement of the current value exists in the map
    if (visited.find(x - head2->data) != visited.end()) {
      count++;
    }
    head2 = head2->next;
  }

  return count;
}

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  struct Node *head1 = new Node();
  struct Node *head2 = new Node();
  struct Node *temp1 = head1;
  struct Node *temp2 = head2;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    temp1->data = val;
    temp1->next = (i < n - 1) ? new Node() : nullptr;
    temp1 = temp1->next;
  }
  for (int i = 0; i < m; i++) {
    int val;
    cin >> val;
    temp2->data = val;
    temp2->next = (i < m - 1) ? new Node() : nullptr;
    temp2 = temp2->next;
  }
  cout << countPairs(head1, head2, x) << endl;
  return 0;
}