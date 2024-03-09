//! Remove Nth Node From End Of List (LeetCode 19)

// Question Link:
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
  ListNode *temp = head;
  int s = 0;

  while (temp) {
    ++s;
    temp = temp->next;
  }

  temp = head;

  if (s == 1) {
    return nullptr;
  }

  if (s == n) {
    return temp->next;
  }

  for (int i = 0; i < s - n - 1; ++i) {
    temp = temp->next;
  }

  temp->next = temp->next->next;

  return head;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  ListNode *result = removeNthFromEnd(head, 2);

  while (result) {
    cout << result->val << " ";
    result = result->next;
  }

  return 0;
}