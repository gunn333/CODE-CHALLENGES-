//! Add One Row to Tree (LeetCode 623)

// Question Link:
// https://leetcode.com/problems/add-one-row-to-tree/

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

TreeNode *addOneRow(TreeNode *root, int val, int depth) {
  // depth is 1 based index
  // if depth is 1, then it means we have to add a new root node with value val
  // and the current root node as its left child
  if (depth == 1) {
    TreeNode *newRoot = new TreeNode(val);
    newRoot->left = root;
    return newRoot;
  }

  queue<TreeNode *> q;
  q.push(root);
  q.push(NULL);
  int currDepth = 0;
  while (!q.empty()) {
    int qSize = q.size();
    currDepth++;
    // qSize-- true for all nodes except the last NULL node
    // so we have to check for the last NULL node
    while (qSize--) {
      // pop the front node from the queue
      TreeNode *front = q.front();
      // pop the front node from the queue because we have already stored it in
      // front
      q.pop();

      // if the current depth = NULL node, then skip this iteration
      if (front == NULL) {
        continue;
      }

      // if the current depth != required depth - 1, then push the left and
      // right child of the current node into the queue
      if (currDepth != depth - 1) {
        if (front->left) {
          q.push(front->left);
        }
        if (front->right) {
          q.push(front->right);
        }
      } else {
        // if the current depth = required depth - 1, then add a new node with
        // value val as the left child of the current node and add a new node
        // with value val as the right child of the current node

        // newLeft will be the left child of the current node and newRight will
        // be the right child of the current node
        TreeNode *newLeft = new TreeNode(val);
        newLeft->left = front->left;
        // front->left will be the left child of the newLeft node and
        // front->left will be the left child of the current node
        front->left = newLeft;
        TreeNode *newRight = new TreeNode(val);
        newRight->right = front->right;
        front->right = newRight;
      }
    }

    // if the queue is not empty, then push a NULL node into the queue
    if (!q.empty()) {
      q.push(NULL);
    }
  }

  return root;
}

int main() {
  // root = [4,2,6,3,1,5]
  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(2);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(1);
  root->right->left = new TreeNode(5);

  // add a new row with value 1 at depth 2
  // root = [4,1,1,2,null,null,6,3,1,5]
  root = addOneRow(root, 1, 2);

  return 0;
}