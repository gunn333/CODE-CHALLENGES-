//! Remove Zero Sum Consecutive Nodes From Linked List(Leetcode 1171)

// Question Link:
// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

ListNode *removeZeroSumSublists(ListNode *head) {
  ListNode *prevHead = NULL;
  ListNode *ans = head;
  ListNode *temp = head;
  while (head) {
    int sum = 0;
    while (temp) {
      sum += temp->val;
      temp = temp->next;
      if (sum == 0) {
        if (ans == head)
          ans = temp;
        if (prevHead)
          prevHead->next = temp;
        head = temp;
        temp = head;
      }
    }
    prevHead = head;
    if (head)
      head = head->next;
    temp = head;
  }
  return ans;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(-3);
  head->next->next->next = new ListNode(3);
  head->next->next->next->next = new ListNode(1);
  ListNode *ans = removeZeroSumSublists(head);
  while (ans) {
    cout << ans->val << " ";
    ans = ans->next;
  }
  return 0;
}