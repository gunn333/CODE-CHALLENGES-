//! Same Tree (LeetCode 100)

// Question Link:
// https://leetcode.com/problems/same-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode *p, TreeNode *q) {
  if (p == NULL && q == NULL) {
    return true;
  }
  if (p == NULL || q == NULL) {
    return false;
  }
  if (p->val != q->val) {
    return false;
  }
  return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
  TreeNode *p = new TreeNode(1);
  p->left = new TreeNode(2);
  p->right = new TreeNode(3);

  TreeNode *q = new TreeNode(1);
  q->left = new TreeNode(2);
  q->right = new TreeNode(3);

  cout << isSameTree(p, q) << endl;

  return 0;
}