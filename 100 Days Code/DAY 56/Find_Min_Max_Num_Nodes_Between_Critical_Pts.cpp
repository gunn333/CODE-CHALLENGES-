//! Find The Minimum and Maximum Number of Nodes Between Two Critical Points
//! (LeetCode 2058)

// Question Link:
// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/

#include <bits/stdc++.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

vector<int> nodesBetweenCriticalPoints(ListNode *head) {
  // first index=-1
  int findex = -1;
  // second index=-1
  int sindex = -1;
  // INDEX VARIABLE BHI LAGEGA
  int index = 0;
  // 3 node lagenge for the comprasion
  ListNode *a = head;
  ListNode *b = head->next;
  ListNode *c = head->next->next;

  // find maximum distance
  while (c != NULL) {
    if (b->val > a->val && b->val > c->val ||
        b->val < a->val && b->val < c->val) {
      if (findex == -1) {
        // assign it with value
        findex = index;
      } else {
        sindex = index;
      }
    }
    a = a->next;
    b = b->next;
    c = c->next;
    index++;
  }
  if (sindex == -1) {
    return {-1, -1};
  }
  int maxd = sindex - findex;

  // aab minimum distance nikalna hai
  // sabko wapis aapne jagah pe laana padega
  // first index=-1
  findex = -1;
  // second index=-1
  sindex = -1;
  // INDEX VARIABLE BHI LAGEGA
  index = 0;
  // 3 node langenge for the comprasion
  // minimum nikalne ke liye
  int mind = INT_MAX;
  a = head;
  b = head->next;
  c = head->next->next;
  while (c != NULL) {
    if (b->val > a->val && b->val > c->val ||
        b->val < a->val && b->val < c->val) {
      // kyuki piche rehna chhaiye na
      findex = sindex;
      sindex = index;
      if (findex != -1) {
        // calculate the distance
        int d = sindex - findex;
        mind = min(d, mind);
      }
    }
    a = a->next;
    b = b->next;
    c = c->next;
    index++;
  }
  return {mind, maxd};
}

int main() {
  ListNode *head = new ListNode(2);
  head->next = new ListNode(1);
  head->next->next = new ListNode(5);
  vector<int> res = nodesBetweenCriticalPoints(head);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  return 0;
}