//! Sum of Root To Leaf Binary Numbers (LeetCode 1022)

// Question Link:
// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

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

int sumRootToLeaf(TreeNode *root, int sum) {
  if (root == NULL) {
    return 0;
  }
  // Convertion of binary to decimal
  // 2 * sum gives the left shift of the binary number and root->val gives the
  // current bit of the binary number
  // 2 * sum + root->val gives the updated binary number
  sum = (2 * sum) + root->val;
  // If the node is a leaf node, return the sum
  if (root->left == NULL && root->right == NULL) {
    return sum;
  }
  // Recursively call the left and right child of the node
  return sumRootToLeaf(root->left, sum) + sumRootToLeaf(root->right, sum);
}

int sumRootToLeaf(TreeNode *root) { return sumRootToLeaf(root, 0); }

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(1);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(1);
  cout << sumRootToLeaf(root) << endl;
  return 0;
}
