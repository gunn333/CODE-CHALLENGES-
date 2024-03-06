//! Linked List Cycle (LeetCode 141)

// Question Link:
// https://leetcode.com/problems/linked-list-cycle/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
  ListNode *fast = head;
  ListNode *slow = head;
  if (head == NULL) {
    return false;
  }

  while (fast != NULL && fast->next != NULL) {
    fast = fast->next;
    fast = fast->next;
    slow = slow->next;
    if (fast == slow) {
      return true;
    }
  }
  return false;
}

int main() {
  ListNode *head = new ListNode(3);
  head->next = new ListNode(2);
  head->next->next = new ListNode(0);
  head->next->next->next = new ListNode(-4);
  head->next->next->next->next = head->next;
  cout << hasCycle(head) << endl;
  return 0;
}