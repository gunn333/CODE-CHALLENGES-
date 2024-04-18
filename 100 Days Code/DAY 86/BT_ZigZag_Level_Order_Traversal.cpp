//! Binary Tree Zigzag Level Order Traversal (LeetCode #103)

// Question Link :
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
  // If the root is NULL, return an empty vector
  if (root == NULL) {
    return {};
  }
  vector<vector<int>> res;
  queue<TreeNode *> q;
  q.push(root);
  int level = 1;
  while (!q.empty()) {
    int levelSize = q.size();
    // Temp vector to store the elements of the current level
    vector<int> temp;
    for (int i = 0; i < levelSize; ++i) {
      TreeNode *front = q.front();
      q.pop();
      temp.push_back(front->val);
      if (front->left != NULL) {
        q.push(front->left);
      }
      if (front->right != NULL) {
        q.push(front->right);
      }
    }
    // If the level is even, reverse the temp vector
    if (level % 2 == 0) {
      reverse(temp.begin(), temp.end());
    }
    res.push_back(temp);
    level++;
  }
  return res;
}

int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);
  vector<vector<int>> res = zigzagLevelOrder(root);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}