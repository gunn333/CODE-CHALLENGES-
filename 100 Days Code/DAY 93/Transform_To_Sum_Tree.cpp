//! Transform to Sum Tree (GeeksForGeeks)

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left, *right;
};

int toSumTree(Node *node) {
  // Base case
  if (node == NULL)
    return 0;

  // old_val mei current node ka data store kraya jisse hume left aur right
  // subtree ka sum nikalne mei help mile
  int old_val = node->data;

  // Recursively call for left and right subtrees and store the sum in
  // node->data
  node->data = toSumTree(node->left) + toSumTree(node->right);

  // Return the sum of nodes rooted under the current node
  return node->data + old_val;
}

int main() {
  Node *root = new Node();
  root->data = 10;
  root->left = new Node();
  root->right = new Node();
  root->left->data = -2;
  root->right->data = 6;
  root->left->left = new Node();
  root->left->right = new Node();
  root->right->left = new Node();
  root->right->right = new Node();
  root->left->left->data = 8;
  root->left->right->data = -4;
  root->right->left->data = 7;
  root->right->right->data = 5;

  toSumTree(root);

  // Print inorder traversal of the converted tree to test result of toSumTree()
  // function
  cout << "Inorder Traversal of the resultant tree is: ";
  cout << root->data << " " << root->left->data << " " << root->right->data
       << " " << root->left->left->data << " " << root->left->right->data << " "
       << root->right->left->data << " " << root->right->right->data << endl;

  return 0;
}