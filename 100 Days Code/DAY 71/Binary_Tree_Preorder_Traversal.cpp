//! Binary Tree Preorder Traversal (LeetCode 144)

// Question Link:
// https://leetcode.com/problems/binary-tree-preorder-traversal/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode *root) {
  vector<int> result;
  if (root == NULL)
    return result;
  result.push_back(root->val);
  vector<int> left = preorderTraversal(root->left);
  result.insert(result.end(), left.begin(), left.end());
  vector<int> right = preorderTraversal(root->right);
  result.insert(result.end(), right.begin(), right.end());
  return result;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);

  vector<int> result = preorderTraversal(root);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }

  return 0;
}