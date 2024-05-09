//! Double a Number represented as a Linked List (LeetCode 2816)

// Question Link :
// https://leetcode.com/problems/add-two-numbers-ii/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(NULL) {}
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *doubleIt(ListNode *head) {
  if (head == NULL) {
    return NULL;
  }
  ListNode *new_head = new ListNode(0);
  ListNode *cur_node = new_head;

  while (cur_node != NULL) {
    cur_node->val = (cur_node->val) * 2 % 10;
    if (cur_node->next != NULL && cur_node->next->val >= 5) {
      cur_node->val += 1;
    };
    cur_node = cur_node->next;
  }

  return new_head->val != 0 ? new_head : head;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  ListNode *new_head = doubleIt(head);
  while (new_head != NULL) {
    cout << new_head->val << " ";
    new_head = new_head->next;
  }
  return 0;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  ListNode *new_head = doubleIt(head);
  while (new_head != NULL) {
    cout << new_head->val << " ";
    new_head = new_head->next;
  }
  return 0;
}