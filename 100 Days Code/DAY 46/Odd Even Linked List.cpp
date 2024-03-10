//! Odd Even Linked List (LeetCode 328)

// Question Link:
// https://leetcode.com/problems/odd-even-linked-list/

#include <bits/stdc++.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int val) : val(val), next(NULL) {}
};

using namespace std;

ListNode *oddEvenList(ListNode *head) {
  if (head == NULL)
    return NULL;
  ListNode *odd = head;
  ListNode *even = head->next;
  ListNode *starteven = even;
  while (odd->next != NULL && even->next != NULL) {
    odd->next = even->next;
    odd = odd->next;
    even->next = odd->next;
    even = even->next;
  }
  odd->next = starteven;
  return head;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);
  head->next->next->next->next->next->next = new ListNode(7);
  head->next->next->next->next->next->next->next = new ListNode(8);
  head = oddEvenList(head);
  while (head != NULL) {
    cout << head->val << " ";
    head = head->next;
  }
  return 0;
}