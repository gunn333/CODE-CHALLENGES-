//! Sort List (leetcode 148)

// Question Link:
// https://leetcode.com/problems/sort-list/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *sortList(ListNode *head) {
  vector<int> arr;

  ListNode *temp = head;

  while (temp) {
    arr.push_back(temp->val);
    temp = temp->next;
  }

  sort(arr.begin(), arr.end());

  ListNode *curr = head;
  for (int i = 0; i < arr.size(); i++) {
    curr->val = arr[i];
    curr = curr->next;
  }
  return head;
}

int main() {
  ListNode *head = new ListNode(4);
  head->next = new ListNode(2);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(3);

  ListNode *result = sortList(head);

  while (result) {
    cout << result->val << " ";
    result = result->next;
  }

  return 0;
}