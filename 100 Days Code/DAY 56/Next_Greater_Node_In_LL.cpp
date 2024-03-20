//! Next Greater Node In Linked List (LeetCode 1019)

// Question Link:
// https://leetcode.com/problems/next-greater-node-in-linked-list/

#include <bits/stdc++.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

vector<int> nextLargerNodes(ListNode *head) {
  vector<int> res;
  while (head != NULL) {
    ListNode *curr = head;
    while (head != NULL && head->val <= curr->val) {
      head = head->next;
    }

    if (head != NULL) {
      res.push_back(head->val);
    } else {
      res.push_back(0);
    }
    head = curr->next;
  }
  return res;
}

int main() {
  ListNode *head = new ListNode(2);
  head->next = new ListNode(1);
  head->next->next = new ListNode(5);
  vector<int> res = nextLargerNodes(head);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  return 0;
}