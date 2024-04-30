//! Count BST nodes that lie in a given range (GeeeksforGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1?page=3&category=Tree&sortBy=submissions

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int x) {
    data = x;
    left = right = NULL;
  }
};

int getCount(Node *root, int l, int h) {
  if (root == NULL) {
    return 0;
  }
  // If the root data >= l and root data <= h, means the root data lies in the
  // range
  if (root->data >= l && root->data <= h) {
    // 1 is added because the root data is also included in the range
    // Count one for the current node if its value falls within the given range
    // [l, h]. Then, recursively count how many nodes in its left subtree and
    // right subtree also fall within that range. Add up all these counts
    // together to find the total number of nodes within the given range in the
    // Binary Search Tree.
    return 1 + getCount(root->left, l, h) + getCount(root->right, l, h);
    // If the root data is less than the lower limit means the root data is less
    // than the range
  } else if (root->data < l) {
    // If the current node's data is less than the lower limit, it implies that
    // all nodes in its left subtree are also less than the range [l, h].
    // Therefore, we don't need to consider the left subtree for counting. We
    // directly move to the right subtree to find nodes within the range [l, h].
    // So, the function recursively calls getCount on the right subtree with the
    // same range limits [l, h].
    return getCount(root->right, l, h);
  } else {
    // return the left subtree
    return getCount(root->left, l, h);
  }
}

int main() {
  Node *root = new Node(10);
  root->left = new Node(5);
  root->right = new Node(50);
  root->left->left = new Node(1);
  root->right->left = new Node(40);
  root->right->right = new Node(100);

  int l = 5, h = 45;
  cout << getCount(root, l, h) << endl;

  return 0;
}