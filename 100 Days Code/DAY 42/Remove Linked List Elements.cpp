//! Remove Linked List Elements (LeetCode 203)

// Question Link:
// https://leetcode.com/problems/remove-linked-list-elements/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeElements(ListNode *&head, int val) {
  ListNode *pos = head;
  ListNode *prev = NULL;
  while (pos != NULL) {
    if (pos->val != val) {
      prev = pos;
      pos = pos->next;
    } else {
      if (prev == NULL) {
        head = pos->next;
      } else {
        prev->next = pos->next;
      }
      ListNode *temp = pos;
      pos = pos->next;
      delete temp;
    }
  }
  return head;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(3);
  head->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next->next = new ListNode(6);
  int val = 6;
  ListNode *res = removeElements(head, val);
  while (res != NULL) {
    cout << res->val << " ";
    res = res->next;
  }
  return 0;
}