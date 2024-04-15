//! Sum Root to Leaf Numbers (LeetCode 129)

// Question Link:
// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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

int sumNumbers(TreeNode *root) { return dfs(root, 0); }

int dfs(TreeNode *root, int sum) {
  // Base case
  if (root == NULL) {
    return 0;
  }
  /*
      1
     /  \
    2   3

    sum = 0
    sum for root = 0*10 + 1 = 1
    sum for left = 1*10 + 2 = 12
    sum for right = 1*10 + 3 = 13
    sum = 12 + 13 = 25
  */
  // sum starts as 0, and each time we visit a node in the tree, we add its
  // value to sum after shifting sum to the left to make space for the new
  // digit.
  // Basically, we are building the number from the root to the leaf node then
  // return the sum of all the numbers.
  sum = sum * 10 + root->val;
  if (root->left == NULL && root->right == NULL) {
    return sum;
  }
  return dfs(root->left, sum) + dfs(root->right, sum);
}