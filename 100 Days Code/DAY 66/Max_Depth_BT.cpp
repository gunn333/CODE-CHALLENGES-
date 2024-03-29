//! Maximum Depth of Binary Tree (LeetCode 104)

// Question Link:
// https://leetcode.com/problems/maximum-depth-of-binary-tree/

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

int maxDepth(Nodes *root) {
  // Base case
  if (root == NULL) {
    return 0;
  }

  // Recursive case
  int left = maxDepth(root->left);
  int right = maxDepth(root->right);

  return max(left, right) + 1;
}

int main() {
  Nodes *root = new Nodes(3);
  root->left = new Nodes(9);
  root->right = new Nodes(20);
  root->right->left = new Nodes(15);
  root->right->right = new Nodes(7);

  cout << maxDepth(root) << endl;
  return 0;
}