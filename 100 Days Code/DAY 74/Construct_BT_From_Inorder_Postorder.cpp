//! Construct Binary Tree from Inorder and Postorder Traversal (LeetCode 106)

// Question Link:
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int start,
                    int end, int &idx) {
  if (start > end)
    return nullptr;

  int curr = postorder[idx--];
  TreeNode *node = new TreeNode(curr);

  if (start == end)
    return node;

  int pos;
  for (int i = start; i <= end; i++) {
    if (inorder[i] == curr) {
      pos = i;
      break;
    }
  }

  node->right = buildTree(inorder, postorder, pos + 1, end, idx);
  node->left = buildTree(inorder, postorder, start, pos - 1, idx);

  return node;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
  int n = postorder.size();
  int idx = n - 1;
  return buildTree(inorder, postorder, 0, n - 1, idx);
}

int main() {
  vector<int> inorder = {9, 3, 15, 20, 7};
  vector<int> postorder = {9, 15, 7, 20, 3};

  TreeNode *root = buildTree(inorder, postorder);
  return 0;
}