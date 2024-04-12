//! Maximum Level sum of a binary tree (LeetCode 1161)

// Question Link:
// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxLevelSum(TreeNode *root) {
  if (root == NULL) {
    return 0;
  }
  int maxSum = INT_MIN;
  int maxLevel = 0;
  int level = 0;
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty()) {
    int size = q.size();
    int sum = 0;
    level++;
    for (int i = 0; i < size; i++) {
      TreeNode *front = q.front();
      q.pop();
      sum += front->val;
      if (front->left) {
        q.push(front->left);
      }
      if (front->right) {
        q.push(front->right);
      }
    }
    if (sum > maxSum) {
      maxSum = sum;
      maxLevel = level;
    }
  }
  return maxLevel;
}

int main() {
  // Let's create the tree
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(7);
  root->right = new TreeNode(0);
  root->left->left = new TreeNode(7);
  root->left->right = new TreeNode(-8);

  cout << maxLevelSum(root) << endl;
  return 0;
}