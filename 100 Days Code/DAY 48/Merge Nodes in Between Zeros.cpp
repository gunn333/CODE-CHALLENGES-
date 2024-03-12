//! Merge Nodes in Between Zeros (Leetcode 2181)

// Question Link:
// https://leetcode.com/problems/merge-nodes-in-between-zeros/

#include <bits/stdc++.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

ListNode *mergeNodes(ListNode *head) {
  ListNode *temp = head->next, *prev = head;
  int sum = 0;
  while (temp) {
    sum += temp->val;
    if (temp->val == 0) {
      prev->val = sum;
      sum = 0;
      if (temp->next != nullptr) {
        prev->next = temp;
        prev = prev->next;
      }
      if (temp->next == nullptr) {
        prev->next = nullptr;
        break;
      }
    }
    temp = temp->next;
  }
  return head;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(0);
  head->next->next = new ListNode(2);
  head->next->next->next = new ListNode(0);
  head->next->next->next->next = new ListNode(3);
  head->next->next->next->next->next = new ListNode(0);
  head->next->next->next->next->next->next = new ListNode(4);
  head = mergeNodes(head);
  while (head != NULL) {
    cout << head->val << " ";
    head = head->next;
  }
  return 0;
}