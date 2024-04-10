//! Sum of Nodes with Even-Valued Grandparent (LeetCode 1315)

// Question Link:
// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

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

int sumEvenGrandparent(TreeNode *root) {
  if (root == NULL) {
    return 0;
  }
  int sum = 0;
  //   Check if the current node is even.
  if (root->val % 2 == 0) {
    //   Check if it has a left child and if the left child has a left child.
    if (root->left != NULL) {
      if (root->left->left != NULL) {
        sum += root->left->left->val;
      }
      if (root->left->right != NULL) {
        sum += root->left->right->val;
      }
    }
    //   Check if it has a right child and if the right child has a right child.
    if (root->right != NULL) {
      if (root->right->left != NULL) {
        sum += root->right->left->val;
      }
      if (root->right->right != NULL) {
        sum += root->right->right->val;
      }
    }
  }

  //  Recurse on left and right. Add the sum of the left and right subtrees.
  if (root->left != NULL) {
    sum += sumEvenGrandparent(root->left);
  }
  if (root->right != NULL) {
    sum += sumEvenGrandparent(root->right);
  }
  return sum;
}

int main() {
  TreeNode *root = new TreeNode(6);
  root->left = new TreeNode(7);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(7);
  root->right->left = new TreeNode(1);
  root->right->right = new TreeNode(3);
  root->left->left->left = new TreeNode(9);
  root->left->right->left = new TreeNode(1);
  root->left->right->right = new TreeNode(4);
  root->right->right->right = new TreeNode(5);
  cout << sumEvenGrandparent(root) << endl;
  return 0;
}