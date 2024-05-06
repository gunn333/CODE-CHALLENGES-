//! Remove Nodes From Linked List (LeetCode 2487)

// Question Link:
// https://leetcode.com/problems/remove-nodes-from-linked-list/description/?envType=daily-question&envId=2024-05-06

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNodes(ListNode *head) {
  // If head is NULL then it means there is no node in the linked list to remove
  // so return NULL
  if (head == NULL) {
    return NULL;
  }
  // Recursively call the function to remove the nodes from the linked list
  // head->next  = removeNodes(head->next); will first remove the node
  // head->next from linked list and then update the head->next to the new head
  // of the linked list
  head->next = removeNodes(head->next);
  // checks if the current node's value is less than the next node's value and
  // if there is a next node available. If both conditions are true, it moves to
  // the next node in the linked list.
  if (head->next != NULL && head->val < head->next->val) {
    return head->next;
  }
  return head;
}

int main() {
  // Example 1
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
  // Output: 1 -> 3 -> 5 -> 7 -> 9
  while (head != NULL) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;

  return 0;
}