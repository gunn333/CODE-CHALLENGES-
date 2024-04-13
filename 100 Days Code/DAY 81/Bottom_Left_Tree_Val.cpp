//! Find Bottom Left Tree Value (Leetcode 513)

// Question Link:
// https://leetcode.com/problems/find-bottom-left-tree-value/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int findBottomLeftValue(TreeNode *root) {
  queue<TreeNode *> q;
  q.push(root);
  q.push(NULL);
  // We will keep on popping the elements from the queue until it becomes empty
  // res will store the value of the leftmost node at the last level
  int res = 0;
  while (!q.empty()) {
    TreeNode *front = q.front();
    q.pop();
    // If front is NULL then we will push NULL in the queue and if the queue is
    // not empty then we will update the value of res
    if (front == NULL) {
      if (!q.empty()) {
        q.push(NULL);
      }
    } else {
      // We will update the value of res
      res = front->val;
      if (front->right) {
        q.push(front->right);
      }
      if (front->left) {
        q.push(front->left);
      }
    }
  }
  return res;
}

int main() {
  // Let's create the tree
  TreeNode *root = new TreeNode(2);
  root->left = new TreeNode(1);
  root->right = new TreeNode(3);

  cout << findBottomLeftValue(root) << endl;
  return 0;
}