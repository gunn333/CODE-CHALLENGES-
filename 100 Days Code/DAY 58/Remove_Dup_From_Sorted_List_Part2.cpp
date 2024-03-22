//! Remove Duplicates from Sorted List II (Leetcode 82)

// Question Link:
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head) {
  ListNode *node;
  ListNode *result;
  ListNode *temp;
  result = head;
  while (1) {
    if (result == NULL)
      return NULL;
    else if (result->next && result->val == result->next->val) {
      while (result->next && result->val == result->next->val) {
        result = result->next;
      }
      result = result->next;
    } else
      break;
  }
  node = result;
  while (node) {
    temp = node->next;
    if (temp == NULL)
      return result;
    else if (temp->next && temp->val == temp->next->val) {
      while (temp->next && temp->val == temp->next->val) {
        temp = temp->next;
      }
      temp = temp->next;
      node->next = temp;
    } else {
      node = node->next;
    }
  }
  return result;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(3);
  head->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next = new ListNode(4);
  head->next->next->next->next->next->next = new ListNode(5);

  ListNode *result = deleteDuplicates(head);

  while (result != NULL) {
    cout << result->val << " ";
    result = result->next;
  }

  return 0;
}
