//! Minimum Distance Between BST Nodes (LeetCode 783)

// Question Link:
// https://leetcode.com/problems/minimum-distance-between-bst-nodes/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDiffInBST(TreeNode *root) {
  int res = INT_MAX;
  // We need to keep track of the previous node and usko NULL isliye kiya hai
  // kyunki agar hume koi node nahi mila toh hume kuch compare nahi karna hai
  TreeNode *prev = NULL;
  // We will do inorder traversal but we can also do preorder or postorder as
  // well
  inorder(root, prev, res);
  return res;
}

void inorder(TreeNode *root, TreeNode *&prev, int &res) {
  // Base case
  if (root == NULL) {
    return;
  }
  inorder(root->left, prev, res);
  // If prev is not NULL then we will compare the difference between the current
  if (prev != NULL) {
    res = min(res, root->val - prev->val);
  }
  // prev ki value ko update kr ke hum current node ko prev mei store karaenge
  prev = root;
  // Now we will move to the right subtree of the current node
  inorder(root->right, prev, res);
}

int main() {
  // Let's create the tree
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);

  cout << minDiffInBST(root) << endl;
  return 0;
}