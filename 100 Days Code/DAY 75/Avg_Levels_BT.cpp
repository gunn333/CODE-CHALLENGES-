//! Average of Levels in Binary Tree (LeetCode 637)

// Question Link:
// https://leetcode.com/problems/average-of-levels-in-binary-tree/

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

vector<double> averageOfLevels(TreeNode *root) {
  // Result mein store karenge average of all levels
  vector<double> result;
  if (root == NULL) {
    return {};
  }
  queue<TreeNode *> q;
  q.push(root);
  q.push(NULL);
  // sum mein store karenge sum of all nodes of a level
  // count mein store karenge number of nodes of a level
  double sum = 0;
  int count = 0;

  while (!q.empty()) {
    TreeNode *front = q.front();
    q.pop();

    if (front != NULL) {
      sum += front->val;
      // count the number of nodes in a level
      count++;

      if (front->left) {
        q.push(front->left);
      }
      if (front->right) {
        q.push(front->right);
      }
    } else {
      // calculate the average of a level before moving to the next level as
      // NULL is encountered
      result.push_back(sum / count);
      sum = 0;
      count = 0;
      // if queue is not empty then push NULL to mark the end of a level
      if (!q.empty()) {
        q.push(NULL);
      }
    }
  }
  return result;
}

int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  vector<double> result = averageOfLevels(root);
  for (double i : result) {
    cout << i << " ";
  }
  return 0;
}