//! Insert GCD in a linked list (Leetcode 2807)

// Question Link:
// https://leetcode.com/problems/insert-gcd-in-a-linked-list/

#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

int GCD(int a, int b) {
  while (b) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

ListNode *insertGreatestCommonDivisors(ListNode *head) {
  if (!head || !head->next) {
    return head;
  } else {
    ListNode *current = head;
    ListNode *previous;

    while (current->next) {
      previous = current;
      current = current->next;
      int gcdValue = GCD(previous->val, current->val);
      ListNode *newNode = new ListNode(gcdValue);
      previous->next = newNode;
      newNode->next = current;
    }
    return head;
  }
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  ListNode *ans = insertGreatestCommonDivisors(head);
  while (ans) {
    cout << ans->val << " ";
    ans = ans->next;
  }
  return 0;
}