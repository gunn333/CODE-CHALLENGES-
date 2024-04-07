//! Even Odd Tree (LeetCode 1609)

// Question Link:
// https://leetcode.com/problems/even-odd-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isEvenOddTree(TreeNode *root) {
  if (root == NULL) {
    return true;
  }
  queue<TreeNode *> q;
  q.push(root);
  int level = 0;
  while (!q.empty()) {
    int n = q.size();
    int prev = level % 2 == 0 ? 0 : INT_MAX;
    for (int i = 0; i < n; i++) {
      TreeNode *front = q.front();
      q.pop();
      if (level % 2 == 0) {
        if (front->val % 2 == 0 || front->val <= prev) {
          return false;
        }
      } else {
        if (front->val % 2 != 0 || front->val >= prev) {
          return false;
        }
      }
      prev = front->val;
      if (front->left != NULL) {
        q.push(front->left);
      }
      if (front->right != NULL) {
        q.push(front->right);
      }
    }
    level++;
  }
  return true;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(10);
  root->right = new TreeNode(4);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(7);
  root->right->left = new TreeNode(9);
  root->right->right = new TreeNode(11);
  cout << isEvenOddTree(root) << endl;
  return 0;
}