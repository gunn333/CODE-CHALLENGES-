//! Check for Children Sum Property in a Binary Tree (GeeksForGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/children-sum-parent/1?page=2&category=Tree,Binary%20Search%20Tree&sortBy=submissions

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

int isSumProperty(Node *root) {
  if (root == NULL) {
    return 1;
  }
  if (root->left == NULL && root->right == NULL) {
    return 1;
  }
  int sum = 0;
  if (root->left != NULL) {
    sum += root->left->data;
  }
  if (root->right != NULL) {
    sum += root->right->data;
  }
  return (root->data == sum && isSumProperty(root->left) &&
          isSumProperty(root->right));
}

int main() {
  Node *root = new Node(20);
  root->left = new Node(8);
  root->right = new Node(12);
  root->right->left = new Node(3);
  root->right->right = new Node(9);
  cout << isSumProperty(root) << endl;
  return 0;
}