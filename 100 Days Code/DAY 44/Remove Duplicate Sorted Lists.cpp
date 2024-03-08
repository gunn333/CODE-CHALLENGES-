//! Remove Duplicates from Sorted List (leetcode 83)

// Question Link:
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *deleteDuplicates(ListNode *const head) {
  for (ListNode *node = head; node != nullptr;) {
    if (node->next != nullptr && node->val == node->next->val) {
      node->next = node->next->next;
    } else {
      node = node->next;
    }
  }
  return head;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(1);
  head->next->next = new ListNode(2);
  head->next->next->next = new ListNode(3);
  head->next->next->next->next = new ListNode(3);
  ListNode *ans = deleteDuplicates(head);
  while (ans) {
    cout << ans->val << " ";
    ans = ans->next;
  }
  return 0;
}