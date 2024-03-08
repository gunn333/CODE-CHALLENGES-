//! Merge Two Sorted Lists (leetcode 21)

// Question Link:
// https://leetcode.com/problems/merge-two-sorted-lists/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
  if (!l1)
    return l2;
  if (!l2)
    return l1;
  ListNode *head, *cur;
  if (l1->val < l2->val) {
    head = l1;
    l1 = l1->next;
  } else {
    head = l2;
    l2 = l2->next;
  }
  cur = head;
  while (l1 && l2) {
    if (l1->val < l2->val) {
      cur->next = l1;
      l1 = l1->next;
    } else {
      cur->next = l2;
      l2 = l2->next;
    }
    cur = cur->next;
  }
  if (!l2)
    cur->next = l1;
  else
    cur->next = l2;
  return head;
}

int main() {
  ListNode *l1 = new ListNode(1);
  l1->next = new ListNode(2);
  l1->next->next = new ListNode(4);
  ListNode *l2 = new ListNode(1);
  l2->next = new ListNode(3);
  l2->next->next = new ListNode(4);
  ListNode *head = mergeTwoLists(l1, l2);
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  return 0;
}