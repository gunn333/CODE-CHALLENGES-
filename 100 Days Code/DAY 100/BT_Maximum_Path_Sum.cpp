//! Binary Maximum Path Sum (LeetCode 124)

// Question Link:
// https://leetcode.com/problems/binary-tree-maximum-path-sum/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) {
    val = x;
    left = right = NULL;
  }
};

int maxSum = INT_MIN;

int maxPath(TreeNode *root) {
  if (!root) {
    return 0;
  }

  int left = maxPath(root->left);
  int right = maxPath(root->right);
  int toRet = max(root->val + left + right,
                  max(left + root->val, max(right + root->val, root->val)));
  maxSum = max(maxSum, toRet);
  return max(root->val, max(root->val + left, root->val + right));
}

int maxPathSum(TreeNode *root) {
  maxPath(root);
  return maxSum;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  cout << maxPathSum(root) << endl;
  return 0;
}
