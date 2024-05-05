//! Delete Node in a Linked List (LeetCode 237)

// Question Link:
// https://leetcode.com/problems/delete-node-in-a-linked-list/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode *node) {
  // if the node is NULL or the next node means the last node is NULL then we
  // can't delete the node so we return
  if (node == NULL || node->next == NULL) {
    return;
  }
  // we copy the value of the next node to the nodeNext
  ListNode *nodeNext = node->next;
  // node->val is the value of the current node
  // nodeNext->val is the value of the next node
  // so we copy the value of the next node to the node and then we delete the
  // next node
  node->val = nodeNext->val;
  // we copy the next of the next node to the next of the current node
  node->next = nodeNext->next;
  // we delete the next node
  delete nodeNext;
}

int main() {
  ListNode *head = new ListNode(4);
  head->next = new ListNode(5);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(9);
  ListNode *node = head->next;
  deleteNode(node);
  while (head != NULL) {
    cout << head->val << " ";
    head = head->next;
  }
  return 0;
}