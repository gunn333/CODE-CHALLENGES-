//! Cousins in Binary Tree (LeetCode 993)

// Question Link:
// https://leetcode.com/problems/cousins-in-binary-tree/

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

bool isCousins(TreeNode *root, int x, int y) {
  if (root == NULL) {
    return false;
  }
  queue<TreeNode *> q;
  q.push(root);
  q.push(NULL);
  // x_found and y_found are used to check if x and y are present in the same
  // level or not and if they are present in the tree or not
  bool x_found = false;
  bool y_found = false;

  while (!q.empty()) {
    TreeNode *front = q.front();
    q.pop();
    if (front != NULL) {
      // if x or y is found then mark it as true
      if (front->val == x) {
        x_found = true;
      }
      if (front->val == y) {
        y_found = true;
      }
      if (front->left != NULL) {
        q.push(front->left);
      }
      if (front->right != NULL) {
        q.push(front->right);
      }
      // if x and y are children of the same parent then return false
      if (front->left != NULL && front->right != NULL) {
        // front->left->val == x means x is the left child of front and
        // front->right->val == y means y is the right child of front
        if ((front->left->val == x && front->right->val == y) ||
            (front->left->val == y && front->right->val == x)) {
          return false;
        }
      }
    } else {
      // if x and y are found in the same level then return true
      if (x_found && y_found) {
        return true;
      }
      // if NULL is encountered then push NULL to mark the end of a level
      if (!q.empty()) {
        q.push(NULL);
      }
      // reset x_found and y_found for the next level
      x_found = false;
      y_found = false;
    }
  }
  return false;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->right->right = new TreeNode(5);
  cout << isCousins(root, 4, 5) << endl; // Output: true
  return 0;
}
