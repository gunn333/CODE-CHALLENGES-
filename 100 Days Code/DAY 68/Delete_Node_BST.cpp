//! Delete Node in a BST (leetcode 450)

// Question Link:
// https://leetcode.com/problems/delete-node-in-a-bst/

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *deleteNode(TreeNode *root, int key) {
  // If root is NULL, return NULL
  if (root == NULL)
    return NULL;
  // key ki value agar root->val se choti hai to left me jayega
  if (key < root->val) {
    root->left = deleteNode(root->left, key);
  }
  // key ki value agar root->val se badi hai to right me jayega
  else if (key > root->val) {
    root->right = deleteNode(root->right, key);
  }
  // agar key ki value root->val ke barabar hai
  else {
    //* Single child cases
    // if left child is NULL, then delete the root and return right child which
    // is stored in temp
    if (root->left == NULL) {
      TreeNode *temp = root->right;
      delete root;
      return temp;
    }
    // if right child is NULL, then delete the root and return left child which
    // is stored in temp
    else if (root->right == NULL) {
      TreeNode *temp = root->left;
      delete root;
      return temp;
    }
    //* Two child cases
    // if both children are present, then find the inorder successor of the root
    // node which is the leftmost node of the right subtree and replace the root
    // node with the inorder successor
    TreeNode *temp = root->left;
    // idhar temp ko leftmost node tak le jayenge
    // leftmost node is the node with the minimum value in the right subtree of
    // the root
    while (temp->right != NULL) {
      temp = temp->right;
    }
    // root ki value ko temp ki value se replace karenge because temp is the
    // leftmost node of the right subtree of the root node
    root->val = temp->val;
    // delete the leftmost node of the right subtree of the root node
    root->left = deleteNode(root->left, temp->val);
  }
  // return the root node
  return root;
}

int main() {
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(3);
  root->right = new TreeNode(6);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(7);

  root = deleteNode(root, 3);

  return 0;
}