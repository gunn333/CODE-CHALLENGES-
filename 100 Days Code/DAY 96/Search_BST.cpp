//! Search in a Binary Search Tree (LeetCode #700)

// Question Link:
// https://leetcode.com/problems/search-in-a-binary-search-tree/

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int val;
  Node *left;
  Node *right;

  Node(int x) {
    val = x;
    left = right = NULL;
  }
};

Node *searchBST(Node *root, int val) {
  // If the root is NULL, then return NULL
  if (root == NULL) {
    return NULL;
  }
  // If the root val is equal to the value, then return the root
  if (root->val == val) {
    return root;
  }
  // If the root val is less than the value, then search in the right subtree
  if (root->val < val) {
    return searchBST(root->right, val);
  }
  // If the root val is greater than the value, then search in the left subtree
  return searchBST(root->left, val);
}

int main() {
  Node *root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(7);
  root->left->left = new Node(1);
  root->left->right = new Node(3);

  int val = 2;
  Node *res = searchBST(root, val);
  if (res) {
    cout << res->val << endl;
  } else {
    cout << "Not Found" << endl;
  }

  return 0;
}