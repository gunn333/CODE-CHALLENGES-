//! Palindrome Linked List (LeetCode 234)

// Question Link:
// https://leetcode.com/problems/palindrome-linked-list/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode *head) {
  vector<int> res;
  while (head) {
    res.push_back(head->val);
    head = head->next;
  }
  int start = 0, end = res.size() - 1;
  while (start <= end) {
    if (res[start++] != res[end--]) {
      return false;
    }
  }
  return true;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(2);
  head->next->next->next = new ListNode(1);
  cout << isPalindrome(head) << endl;
  return 0;
}