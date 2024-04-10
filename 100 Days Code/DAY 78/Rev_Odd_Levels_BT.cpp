//! Reverse Odd Levels of a Binary Tree (LeetCode 2415)

// Question Link:
// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/

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

TreeNode *reverseOddLevels(TreeNode *root) {
  if (root == NULL) {
    return NULL;
  }
  queue<TreeNode *> q;
  //   Store the values of the nodes at each level.
  vector<int> levelValues;
  q.push(root);
  int level = 0;

  while (!q.empty()) {
    //  Store the size of the current level.
    int levelSize = q.size();
    // Store the values of the nodes at the current level.
    vector<int> tempValues;
    for (int i = 0; i < levelSize; ++i) {
      TreeNode *front = q.front();
      q.pop();
      // If the level is odd, reverse the values of the nodes.
      if (level % 2 != 0) {
        // front->val means the value of the current node.
        // levelSize - i - 1 means the index of the node in the current level.
        // levelValues[levelSize - i - 1] gives the value of the node at that
        // index.(levelSize - i - 1) is the reverse index of the current node.
        front->val = levelValues[levelSize - i - 1];
      }
      // Push the left and right children of the current node.
      if (front->left != NULL) {
        q.push(front->left);
        tempValues.push_back(front->left->val);
      }
      if (front->right != NULL) {
        q.push(front->right);
        tempValues.push_back(front->right->val);
      }
    }
    // Store the values of the nodes at the current level.
    levelValues = tempValues;
    level++;
  }
  return root;
}

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  TreeNode *newRoot = reverseOddLevels(root);
  return 0;
}