//! Delete Node in a Linked List (LeetCode 237)

// Question Link:
// https://leetcode.com/problems/delete-node-in-a-linked-list/

#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
  int val;
  ListNode *next;
  ListNode(int val) : val(val), next(NULL) {}
};

void deleteNode(ListNode *node) {
  if (node == NULL || node->next == NULL)
    return;

  ListNode *nodeNext = node->next;
  node->val = nodeNext->val;
  node->next = nodeNext->next;

  delete nodeNext;
}

int main() {
  ListNode *head = new ListNode(4);
  head->next = new ListNode(5);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(9);

  deleteNode(head->next);
  while (head != NULL) {
    cout << head->val << " ";
    head = head->next;
  }
  return 0;
}