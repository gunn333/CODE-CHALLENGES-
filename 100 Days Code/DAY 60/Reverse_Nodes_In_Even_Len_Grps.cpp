//! Reverse Nodes in Even Length Groups (LeetCode 2074)

// Question Link:
// https://leetcode.com/problems/reverse-nodes-in-even-length-groups/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;

  ListNode(int data) {
    val = data;
    next = NULL;
  }
};

ListNode *reverseEvenLengthGroups(ListNode *head) {
  ListNode *temp = head, *tmp;
  int group = 1, grp_length = 0;
  vector<int> list;
  while (temp) {
    tmp = temp;
    while (grp_length < group && temp) {
      list.push_back(temp->val);
      temp = temp->next;
      grp_length++;
    }
    if (grp_length % 2 == 0) {
      for (int i = list.size() - 1; i >= 0; i--) {
        tmp->val = list[i];
        tmp = tmp->next;
      }
    }
    grp_length = 0;
    group++;
    // list = {}; means that it will clear the list
    list = {};
  }
  return head;
}

int main() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);
  head->next->next->next->next->next->next = new ListNode(7);
  head->next->next->next->next->next->next->next = new ListNode(8);

  ListNode *result = reverseEvenLengthGroups(head);
  while (result != NULL) {
    cout << result->val << " ";
    result = result->next;
  }
  return 0;
}