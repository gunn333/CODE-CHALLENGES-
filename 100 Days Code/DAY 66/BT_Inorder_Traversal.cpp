//! Binary Tree Inorder Traversal(Leetcode 94)

// Question Link:
// https://leetcode.com/problems/binary-tree-inorder-traversal/

#include <bits/stdc++.h>
using namespace std;

struct Nodes {
  int val;
  Nodes *left;
  Nodes *right;

  Nodes(int data) {
    val = data;
    left = NULL;
    right = NULL;
  }
};

vector<int> inorderTraversal(Nodes *root) {
  vector<int> result;
  // Base case
  if (root == NULL) {
    return result;
  }
  // Left Subtree
  vector<int> left = inorderTraversal(root->left);
  result.insert(result.end(), left.begin(), left.end());

  // Root
  result.push_back(root->val);

  // Right Subtree
  vector<int> right = inorderTraversal(root->right);
  result.insert(result.end(), right.begin(), right.end());
  return result;
}

int main() {
  Nodes *root = new Nodes(1);
  root->right = new Nodes(2);
  root->right->left = new Nodes(3);

  vector<int> result = inorderTraversal(root);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  return 0;
}