//! Swapping Nodes in a Linked List (Leetcode 1721)

// Question Link:
// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

vector<int> vec;
void traverse(ListNode *head) {
  while (head) {
    vec.push_back(head->val);
    head = head->next;
  }
}
ListNode *swapNodes(ListNode *head, int k) {
  traverse(head);
  int a = k - 1;
  int i = 0;
  ListNode *p = head;
  while (p) {
    if (i == a)
      p->val = vec[vec.size() - a - 1];
    else if (i == vec.size() - a - 1)
      p->val = vec[a];
    i++;
    p = p->next;
  }
  return head;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head = swapNodes(head, 2);
  while (head != NULL) {
    cout << head->val << " ";
    head = head->next;
  }
  return 0;
}