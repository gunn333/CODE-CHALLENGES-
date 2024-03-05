//! Middle of the Linked List (LeetCode 876)

// Question Link:
// https://leetcode.com/problems/middle-of-the-linked-list/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *middleNode(ListNode *head) {
  ListNode *slow = head, *fast = head;
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);
  ListNode *middle = middleNode(head);
  cout << middle->val << endl;
  return 0;
}