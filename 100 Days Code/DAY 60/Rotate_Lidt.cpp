//! Rotate List (Leetcode 61)

// Question Link:
// https://leetcode.com/problems/rotate-list/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;

  ListNode(int data) {
    val = data;
    next = NULL;
  }
};

ListNode *rotateRight(ListNode *head, int k) {
  if (head == NULL)
    return head;
  int num = 1;
  ListNode *current = head;
  ListNode *first = head;
  ListNode *prev = head;
  while (current->next != NULL) {
    num++;
    current = current->next;
  }
  k %= num;
  if (k == 0)
    return head;
  for (int i = 0; i < num - k; i++) {
    prev = first;
    first = first->next;
  }
  prev->next = NULL;
  current->next = head;
  return first;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  int k = 2;
  ListNode *result = rotateRight(head, k);
  while (result != NULL) {
    cout << result->val << " ";
    result = result->next;
  }
  return 0;
}