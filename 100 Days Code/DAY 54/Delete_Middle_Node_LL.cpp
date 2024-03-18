//! Delete Middle Node in a Linked List (LeetCode 2095)

// Question Link:
// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

#include <bits/stdc++.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

ListNode *deleteMiddle(ListNode *head) {
  if (head == NULL || head->next == NULL) {
    return NULL;
  }
  ListNode *fast = head;
  ListNode *slow = head;
  ListNode *prev = NULL;
  while (fast && fast->next) {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  ListNode *curr = slow;
  prev->next = curr->next;
  curr->next = NULL;
  delete curr;
  return head;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head = deleteMiddle(head);
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  return 0;
}