//! Smallest String Starting From Leaf (LeetCode 988)

// Question Link:
// https://leetcode.com/problems/smallest-string-starting-from-leaf/

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int val;
  Node *left, *right;
  Node(int x) {
    val = x;
    left = right = NULL;
  }
};

string smallestFromLeaf(Node *root, string str = "") {
  if (root == NULL) {
    return str;
  }
  // str is a string that stores the path from root to leaf
  // char('a' + root->val) converts the integer value of root->val to a
  // character
  // str = char('a' + root->val) + str; appends the character to the front of
  // the string
  // str += string(1, 'a' + root->val) creates a string of length 1 with the
  // root->val character
  // char('a' + root->val) + str is equivalent to string(1, 'a' + root->val) +
  str += string(1, 'a' + root->val);
  // If the current node is a leaf node, return the string
  if (root->left == NULL && root->right == NULL) {
    return str;
  }
  // If the current node has both left and right children, return the minimum of
  // the left and right subtrees
  if (root->left != NULL && root->right != NULL) {
    return min(smallestFromLeaf(root->left, str),
               smallestFromLeaf(root->right, str));
  }
  // If the current node has only a right child, return the right subtree
  if (root->left == NULL) {
    return smallestFromLeaf(root->right, str);
  }
  // If the current node has only a left child, return the left subtree
  return smallestFromLeaf(root->left, str);
}

int main() {
  Node *root = new Node(25);
  root->left = new Node(1);
  root->right = new Node(3);
  root->left->left = new Node(1);
  root->left->right = new Node(3);
  root->right->left = new Node(0);
  root->right->right = new Node(2);
  cout << smallestFromLeaf(root) << endl;
  return 0;
}