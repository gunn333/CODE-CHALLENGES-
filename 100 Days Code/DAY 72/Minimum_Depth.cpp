//! Minimum Depth of Binary Tree (LeetCode 111)

// Question Link:
// https://leetcode.com/problems/minimum-depth-of-binary-tree/

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

int minDepth(TreeNode *root) {

  if (root == NULL)
    return 0; // Base case...If the subtree is empty i.e. root is NULL, return
              // depth as 0...

  // Initialize the depth of two subtrees...
  int minDepthLeft = minDepth(root->left);
  int minDepthRight = minDepth(root->right);

  // If the both subtrees are empty...
  if (root->left == NULL && root->right == NULL)
    return 1;

  // If the left subtree is empty, return the depth of right subtree after
  // adding 1 to it...
  if (root->left == NULL) {
    return 1 + minDepthRight;
  }

  // If the right subtree is empty, return the depth of left subtree after
  // adding 1 to it...
  if (root->right == NULL) {
    return 1 + minDepthLeft;
  }

  // When the two child function return its depth...
  // Pick the minimum out of these two subtrees and return this value after
  // adding 1 to it...
  return min(minDepthLeft, minDepthRight) +
         1; // Adding 1 bcoz its the current node which is the root node (parent
            // of the two subtrees)
}

int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);
  cout << minDepth(root) << endl;
  return 0;
}