//! Intersection of two linked lists (LeetCode 160)

// Question Link:
// https://leetcode.com/problems/intersection-of-two-linked-lists/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  ListNode *A = headA;
  ListNode *B = headB;
  if (A == NULL || B == NULL)
    return NULL;
  while (A != B) {
    A = A->next;
    B = B->next;

    if (A == NULL && B == NULL)
      return NULL;
    if (A == NULL)
      A = headB;
    if (B == NULL)
      B = headA;
  }
  return A;
}

int main() {
  ListNode *headA = new ListNode(4);
  headA->next = new ListNode(1);
  headA->next->next = new ListNode(8);
  headA->next->next->next = new ListNode(4);
  headA->next->next->next->next = new ListNode(5);

  ListNode *headB = new ListNode(5);
  headB->next = new ListNode(0);
  headB->next->next = new ListNode(1);
  headB->next->next->next = headA->next->next;

  ListNode *res = getIntersectionNode(headA, headB);
  cout << res->val << " ";
  return 0;
}