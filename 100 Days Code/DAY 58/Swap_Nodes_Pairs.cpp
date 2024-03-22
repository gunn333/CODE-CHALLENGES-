//! Swap Nodes in Pairs (LeetCode 24)

// Question Link:
// https://leetcode.com/problems/swap-nodes-in-pairs/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

ListNode *swapPairs(ListNode *head) {
  // if head is NULL OR just having a single node, then no need to change
  // anything
  if (head == NULL || head->next == NULL) {
    return head;
  }

  ListNode *temp;    // temporary pointer to store head -> next
  temp = head->next; // give temp what he want

  head->next = swapPairs(head->next->next); // changing links
  temp->next = head;                        // put temp -> next to head

  return temp; // now after changing links, temp act as our head
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);

  ListNode *result = swapPairs(head);

  while (result != NULL) {
    cout << result->val << " ";
    result = result->next;
  }

  return 0;
}