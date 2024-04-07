//! Binary Tree Level Order Traversal Part 2 (LeetCode 107)

// Question Link:
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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

vector<vector<int>> levelOrderBottom(TreeNode *root) {
  if (root == NULL) {
    return {};
  }
  vector<vector<int>> result;
  queue<TreeNode *> q;
  q.push(root);
  q.push(NULL);

  while (q.size() > 1) {
    vector<int> levelNodes;
    while (q.front() != NULL) {
      TreeNode *front = q.front();
      q.pop();
      levelNodes.push_back(front->val);

      if (front->left != NULL) {
        q.push(front->left);
      }

      if (front->right != NULL) {
        q.push(front->right);
      }
    }

    result.push_back(levelNodes);
    q.pop();
    q.push(NULL);
  }
  // reverse is used to reverse the result vector to get the bottom-up level
  // we are not using sort because it will sort the levels in ascending order /
  // descending order
  reverse(result.begin(), result.end());
  return result;
}

int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  vector<vector<int>> result = levelOrderBottom(root);

  for (vector<int> level : result) {
    for (int node : level) {
      cout << node << " ";
    }
    cout << endl;
  }

  return 0;
}
