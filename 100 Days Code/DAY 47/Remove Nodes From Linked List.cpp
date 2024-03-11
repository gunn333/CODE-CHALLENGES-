//!  Remove Nodes From Linked List (LeetCode 2487)

// Question Link:
// https://leetcode.com/problems/remove-nodes-from-linked-list/description/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverse(ListNode *head) {
  ListNode *curr = head;
  ListNode *prev = NULL;
  while (curr) {
    ListNode *nxt = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nxt;
  }
  return prev;
}
ListNode *removeNodes(ListNode *head) {
  head = reverse(head);
  ListNode *prev = NULL;
  ListNode *curr = head;
  int maxi = head->val;

  while (curr != NULL) {
    maxi = max(maxi, curr->val);
    if (maxi > curr->val) {
      prev->next = curr->next;
    } else {
      prev = curr;
    }
    curr = curr->next;
  }
  head = reverse(head);
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
  head->next->next->next->next->next->next->next->next = new ListNode(9);
  head->next->next->next->next->next->next->next->next->next = new ListNode(10);
  head = removeNodes(head);
  while (head != NULL) {
    cout << head->val << " ";
    head = head->next;
  }
  return 0;
}