//! Kth Largest Sum in a Binary Tree (LeetCode 2583)

// Question Link:
// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

long long kthLargestLevelSum(TreeNode *root, int k) {
  if (root == NULL) {
    return 0;
  }
  queue<TreeNode *> q;
  q.push(root);
  q.push(NULL);
  long long sum = 0;
  // levelSum will store the sum of each level of the tree
  vector<long long> levelSum;
  while (!q.empty()) {
    TreeNode *front = q.front();
    q.pop();
    if (front != NULL) {
      sum += front->val;
      if (front->left) {
        q.push(front->left);
      }
      if (front->right) {
        q.push(front->right);
      }
    }
    // If the current level has been traversed completely, push a nullptr to
    // mark the end of the level
    if (front == NULL && !q.empty()) {
      q.push(NULL);
      levelSum.push_back(sum);
      sum = 0;
    }
  }
  // If the last level has been traversed completely, push the sum of the last
  // level
  if (sum != 0)
    levelSum.push_back(sum);
  int n = levelSum.size();
  // If k is greater than the number of levels, return -1
  if (k > n) {
    return -1;
  }
  sort(levelSum.begin(), levelSum.end());
  return levelSum[n - k];
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  cout << kthLargestLevelSum(root, 3) << endl;
  return 0;
}