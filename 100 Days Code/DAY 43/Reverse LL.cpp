//! Reverse LL (LeetCode 206)

// Question Link:
// https://leetcode.com/problems/reverse-linked-list/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseList(ListNode *head) {
  ListNode *cur = head;
  ListNode *prev = nullptr;

  while (cur) {
    ListNode *next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  return prev;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  ListNode *res = reverseList(head);
  while (res != NULL) {
    cout << res->val << " ";
    res = res->next;
  }
  return 0;
}