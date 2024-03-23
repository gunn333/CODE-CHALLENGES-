//! Reorder List (Leetcode 143)

// Question Link:
// https://leetcode.com/problems/reorder-list/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

void reorderList(ListNode *head) {
  ListNode *slow = head;
  ListNode *fast = head->next;
  // fast && fast->next != NULL condition is used because if the length of the
  // list is even then fast will be NULL and if the length of the list is odd
  // then fast->next will be NULL so we need to check both conditions
  while (fast && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  // slow is the middle of the list
  ListNode *second = slow->next;
  // breaking the list into two halves
  slow->next = NULL;
  ListNode *prev = NULL;

  // reversing the second half of the list
  while (second != NULL) {
    ListNode *temp = second->next;
    second->next = prev;
    prev = second;
    second = temp;
  }
  // prev is the head of the reversed list
  ListNode *first = head;
  second = prev;
  while (second != NULL) {
    // swapping the nodes
    ListNode *tmp = first->next;
    ListNode *tmp1 = second->next;
    first->next = second;
    second->next = tmp;
    first = tmp;
    second = tmp1;
  }
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  reorderList(head);

  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  return 0;
}