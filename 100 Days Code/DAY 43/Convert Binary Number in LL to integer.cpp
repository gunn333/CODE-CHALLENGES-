//! Convert Binary Number in a Linked List to Integer (LeetCode 1290)

// Question Link:
// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

int getDecimalValue(ListNode *head) {
  int length = 0;
  int ans = 0;
  int t;
  ListNode *temp = head;
  ListNode *test = head;
  while (temp != NULL) {
    length++;
    temp = temp->next;
  }
  while (length >= 0 && test != NULL) {
    t = 0;
    t += test->val;
    t *= pow(2, length - 1);
    ans += t;
    length--;
    test = test->next;
  }

  return ans;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(0);
  head->next->next = new ListNode(1);

  cout << getDecimalValue(head);
  return 0;
}