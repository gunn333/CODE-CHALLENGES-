//! Check if all leaves are at same level in a Binary Tree (GeeksForGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/leaf-at-same-level/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left, *right;
  Node(int x) {
    data = x;
    left = right = NULL;
  }
};

bool check(Node *root) {
  if (root == NULL) {
    return true;
  }
  queue<Node *> q;
  q.push(root);
  q.push(NULL);
  // level means current level
  int level = 0;
  // leafLevel means the level of leaf node
  int leafLevel = 0;
  while (!q.empty()) {
    Node *front = q.front();
    q.pop();
    if (front != NULL) {
      // if it is a leaf node means both left and right child are NULL
      if (front->left == NULL && front->right == NULL) {
        // check if leafLevel == 0 means it is the first leaf node
        // if leafLevel != 0 means it is not the first leaf node
        if (leafLevel == 0) {
          // store the level of leaf node in leafLevel
          leafLevel = level;
        } else {
          // if level != leafLevel means leaf node is not at the same level as
          // previous leaf node
          if (level != leafLevel) {
            return false;
          }
        }
      }
      if (front->left != NULL) {
        q.push(front->left);
      }
      if (front->right != NULL) {
        q.push(front->right);
      }
    } else {
      if (!q.empty()) {
        q.push(NULL);
        level++;
      }
    }
  }
  // if all leaf nodes are at the same level
  return true;
}
