//! Find a Corresponding Node of a Binary Tree in a Clone of That Tree (LeetCode
//! 1379)

// Question Link:
// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode *clone;
  TreeNode() : val(0), left(nullptr), right(nullptr), clone(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr), clone(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right), clone(nullptr) {}
};

TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned,
                        TreeNode *target) {
  // If the original tree is empty, return NULL.
  if (original == NULL) {
    return NULL;
  }

  // If the original tree is equal to the target node, return the cloned tree.
  if (original == target) {
    return cloned;
  }
  // Recurse on the left and right subtrees.
  // Using TreeNode *left because we are returning the left subtree.
  TreeNode *left = getTargetCopy(original->left, cloned->left, target);
  TreeNode *right = getTargetCopy(original->right, cloned->right, target);

  // If the left subtree is not NULL, return the left subtree.
  if (left != NULL) {
    return left;
  }
  return right;
}

int main() {
  TreeNode *original = new TreeNode(7);
  original->left = new TreeNode(4);
  original->right = new TreeNode(3);
  original->right->left = new TreeNode(6);
  original->right->right = new TreeNode(19);

  TreeNode *cloned = new TreeNode(7);
  cloned->left = new TreeNode(4);
  cloned->right = new TreeNode(3);
  cloned->right->left = new TreeNode(6);
  cloned->right->right = new TreeNode(19);

  TreeNode *target = original->right;
  TreeNode *ans = getTargetCopy(original, cloned, target);
  cout << ans->val << endl;
  return 0;
}