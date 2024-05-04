//! Construct Binary Tree from Inorder and Postorder Traversal (GeeeksforGeeks)

// Question Link:
// https://practice.geeksforgeeks.org/problems/construct-tree-1/1

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left, *right;

  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

Node *buildTree(int in[], int post[], int n) {
  if (n == 0)
    return NULL;

  int rootData = post[n - 1];
  Node *root = new Node(rootData);

  int rootIndex = -1;
  for (int i = 0; i < n; i++) {
    if (in[i] == rootData) {
      rootIndex = i;
      break;
    }
  }

  root->left = buildTree(in, post, rootIndex);
  root->right =
      buildTree(in + rootIndex + 1, post + rootIndex, n - rootIndex - 1);

  return root;
}

void printInorder(Node *root) {
  if (root == NULL)
    return;

  printInorder(root->left);
  cout << root->data << " ";
  printInorder(root->right);
}

int main() {
  int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
  int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
  int n = sizeof(in) / sizeof(in[0]);

  Node *root = buildTree(in, post, n);

  cout << "Inorder Traversal of the constructed tree: ";
  printInorder(root);

  return 0;
}