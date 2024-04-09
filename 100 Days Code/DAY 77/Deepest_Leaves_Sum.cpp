//! Deepest Leaves Sum (LeetCode 1302)

// Question Link:
// https://leetcode.com/problems/deepest-leaves-sum/

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

// Get the level/depth of the tree.
int level(TreeNode *root) {
  if (!root)
    return 0;

  int llevel = 0;
  if (root->left)
    llevel = level(root->left);

  int rlevel = 0;
  if (root->right)
    rlevel = level(root->right);

  // Max of left and right +1 for this level.
  return (max(rlevel, llevel) + 1);
}

// Get the sum of all the last level nodes.
int lastlevelsum(TreeNode *root, int curlevel) {
  if (!root)
    return 0;

  int sum = 0;

  // Decrement the level on each stage.
  curlevel -= 1;

  // level 0 indicates that this node is a candidate
  // for the sum.
  if (curlevel == 0)
    return root->val;

  // Recurse on left
  if (root->left)
    sum += lastlevelsum(root->left, curlevel);

  // Recurse on right
  if (root->right)
    sum += lastlevelsum(root->right, curlevel);

  return sum;
}

int deepestLeavesSum(TreeNode *root) {
  // Get the deepest level/depth.
  int l = level(root);

  return lastlevelsum(root, l);
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);
  root->left->left->left = new TreeNode(7);
  root->right->right->right = new TreeNode(8);

  cout << deepestLeavesSum(root) << endl;
  return 0;
}
