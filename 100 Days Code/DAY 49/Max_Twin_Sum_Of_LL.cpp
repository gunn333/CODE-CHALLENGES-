//! Maximum Twin Sum of Linked List (Leetcode 2130)

// Question Link:
// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

int pairSum(ListNode *head) {
  int max_sum = 0;
  int length = 0;
  ListNode *curr = head;
  vector<int> vec;
  while (curr != NULL) {
    vec.push_back(curr->val);
    length++;
    curr = curr->next;
  }

  int begin = 0;
  int end = length - 1;
  while (begin < end) {
    max_sum = max(max_sum, (vec[begin] + vec[end]));
    begin++;
    end--;
  }

  return max_sum;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(4);
  head->next->next->next = new ListNode(5);
  head->next->next->next->next = new ListNode(6);
  cout << pairSum(head);
  return 0;
}