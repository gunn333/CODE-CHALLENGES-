//! Reverse Nodes in k-Group (LeetCode 25)

// Question Link:
// https://leetcode.com/problems/reverse-nodes-in-k-group/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;

  ListNode(int data) {
    val = data;
    next = NULL;
  }
};

ListNode *reverseKGroup(ListNode *head, int k) {
  // Check whether it has k nodes or not
  ListNode *kEnd = head;
  for (int i = 0; i < k; i++) {
    if (kEnd == nullptr) {
      return head;
    } else {
      kEnd = kEnd->next;
    }
  }

  ListNode *end = reverseKGroup(kEnd, k);
  // reverse
  ListNode *cur = head;
  ListNode *prev = end;
  for (int i = 0; i < k; i++) {
    prev = cur;
    cur = cur->next;
    prev->next = end;
    end = prev;
  }
  return prev;
}
