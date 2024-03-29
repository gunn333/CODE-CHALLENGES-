//! Binary Tree Postorder Traversal (LeetCode 145)

// Question Link:
// https://leetcode.com/problems/binary-tree-postorder-traversal/

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

vector<int> postorderTraversal(Nodes *root) {
  vector<int> result;
  // Base case
  if (root == NULL) {
    return result;
  }

  // Left Subtree
  vector<int> left = postorderTraversal(root->left);
  // This will insert all the left nodes in the end of the result vector
  result.insert(result.end(), left.begin(), left.end());

  // Right Subtree
  vector<int> right = postorderTraversal(root->right);
  result.insert(result.end(), right.begin(), right.end());

  result.push_back(root->val);

  return result;
}

int main() {
  Nodes *root = new Nodes(1);
  root->right = new Nodes(2);
  root->right->left = new Nodes(3);

  vector<int> result = postorderTraversal(root);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  return 0;
}