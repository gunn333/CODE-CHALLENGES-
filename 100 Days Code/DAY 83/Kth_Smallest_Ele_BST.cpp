//! Kth Smallest Element BST (LeetCode 230)

// Question Link:
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) {
    val = x;
    left = right = NULL;
  }
};

int kthSmallest(TreeNode *root, int k) {
  if (root == NULL) {
    return -1;
  }
  vector<int> array;
  queue<TreeNode *> q;
  q.push(root);
  q.push(NULL);
  while (!q.empty()) {
    TreeNode *front = q.front();
    q.pop();
    if (front != NULL) {
      array.push_back(front->val);
      if (front->left != NULL) {
        q.push(front->left);
      }
      if (front->right != NULL) {
        q.push(front->right);
      }
    } else {
      if (!q.empty()) {
        q.push(NULL);
      }
    }
  }
  sort(array.begin(), array.end());
  // kth smallest element is at k - 1 index in the sorted array
  return array[k - 1];
}

int main() {
  TreeNode *root = new TreeNode(50);
  root->left = new TreeNode(30);
  root->right = new TreeNode(70);
  root->left->left = new TreeNode(20);
  root->left->right = new TreeNode(40);
  root->right->left = new TreeNode(60);
  root->right->right = new TreeNode(80);
  cout << kthSmallest(root, 3) << endl;
  return 0;
}
