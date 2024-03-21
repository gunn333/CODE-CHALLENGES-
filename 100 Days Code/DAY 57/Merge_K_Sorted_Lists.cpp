//! Merge K Sorted Lists (Leetcode 23)

// Question Link:
// https://leetcode.com/problems/merge-k-sorted-lists/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeKLists(vector<ListNode *> &lists) {
  if (lists.size() == 0)
    return nullptr;
  while (lists.size() > 1) {
    lists.push_back(merge(lists[0], lists[1]));
    lists.erase(lists.begin());
    lists.erase(lists.begin());
  }
  return lists[0];
}
ListNode *merge(ListNode *l1, ListNode *l2) {
  if (!l1)
    return l2;
  if (!l2)
    return l1;
  // if l1->val < l2->val means l1 is smaller so we will merge l1->next with l2
  // and return l1 else we will merge l2->next with l1 and return l2 as head of
  // the merged list
  if (l1->val < l2->val) {
    l1->next = merge(l1->next, l2);
    return l1;
  } else {
    l2->next = merge(l2->next, l1);
    return l2;
  }
}

int main() {
  vector<ListNode *> lists;
  ListNode *l1 = new ListNode(1);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(5);

  ListNode *l2 = new ListNode(1);
  l2->next = new ListNode(3);
  l2->next->next = new ListNode(4);

  ListNode *l3 = new ListNode(2);
  l3->next = new ListNode(6);

  lists.push_back(l1);
  lists.push_back(l2);
  lists.push_back(l3);

  ListNode *result = mergeKLists(lists);
  while (result) {
    cout << result->val << " ";
    result = result->next;
  }
  return 0;
}