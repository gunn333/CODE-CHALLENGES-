//! Reverse Linked List Part 2 (Leetcode 92)

// Question Link:
// https://leetcode.com/problems/reverse-linked-list-ii/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseBetween(ListNode *head, int m, int n) {
  if (head == NULL)
    return NULL;
  vector<int> v;
  // p -
  ListNode *temp = head;
  while (temp != NULL) {
    v.push_back(temp->val);
    temp = temp->next;
  }
  temp = head;
  for (int i = 0; i < m - 1;
       i++) // till m-1 values will remain same as in the list..
    temp = temp->next;
  for (int i = n; i >= m; i--) {
    temp->val = v[i - 1]; // reverse the value within range..
    temp = temp->next;
  }
  return head;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  int m = 2, n = 4;
  ListNode *result = reverseBetween(head, m, n);
  while (result) {
    cout << result->val << " ";
    result = result->next;
  }
  return 0;
}