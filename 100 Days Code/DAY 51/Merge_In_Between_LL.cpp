//! Merge in Between Linked Lists (LeetCode 1669)

// Question Link:
// https://leetcode.com/problems/merge-in-between-linked-lists/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
  ListNode *start;
  ListNode *last;
  ListNode *curr = list1;

  int count = 1;

  while (curr) {

    if (count == a)
      start = curr;
    if (count == b)
      last = curr->next->next;
    curr = curr->next;
    count++;
  }

  start->next = list2;
  curr = list2;
  while (curr->next) {
    curr = curr->next;
  }
  curr->next = last;

  return list1;
}

int main() {
  ListNode *list1 = new ListNode(0);
  list1->next = new ListNode(1);
  list1->next->next = new ListNode(2);
  list1->next->next->next = new ListNode(3);
  list1->next->next->next->next = new ListNode(4);
  list1->next->next->next->next->next = new ListNode(5);

  ListNode *list2 = new ListNode(1000000);
  list2->next = new ListNode(1000001);
  list2->next->next = new ListNode(1000002);

  int a = 3, b = 4;

  ListNode *result = mergeInBetween(list1, a, b, list2);
  while (result) {
    cout << result->val << " ";
    result = result->next;
  }
  return 0;
}

/*
approach:
We are given two linked lists list1 and list2. We are also given two integers
a and b. We have to merge list2 into list1 at the position between a and b.
We can solve this problem using the following steps:
1. We will traverse the list1 and find the node at position a and b.
2. We will store the node at position a in the start and the node at position
b in the last.
3. We will traverse the list2 and find the last node of list2.
4. We will connect the next of the start to the head of list2 and the next of
the last to the next of the last node of list2.
5. Finally, we will return the list1.
*/