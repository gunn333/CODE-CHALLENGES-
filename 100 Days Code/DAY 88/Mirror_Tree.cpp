//! Mirror Tree (GeeksforGeeks)

// Question Link:
// https://practice.geeksforgeeks.org/problems/mirror-tree/1

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

void mirror(Node *node) {
  if (node == NULL)
    return;
  else {
    // temp will store the left child of the node
    Node *temp;
    // Recursively call the mirror function for the left and right child of the
    // node
    mirror(node->left);
    mirror(node->right);
    // Swap the left and right child of the node
    temp = node->left;
    node->left = node->right;
    node->right = temp;
  }
}

int main() {
  Node *root = new Node(1);
  root->left = new Node(3);
  root->right = new Node(2);
  root->right->left = new Node(5);
  root->right->right = new Node(4);

  mirror(root);

  return 0;
}