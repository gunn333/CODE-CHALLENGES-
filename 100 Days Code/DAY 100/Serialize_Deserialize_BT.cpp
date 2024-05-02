//! Serialize and Deserialize Binary Tree (GeeeksforGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1

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

vector<int> serialize(Node *root) {
  vector<int> A;
  if (root == NULL) {
    A.push_back(-1);
    return A;
  }
  A.push_back(root->data);
  vector<int> leftSerialized = serialize(root->left);
  vector<int> rightSerialized = serialize(root->right);
  A.insert(A.end(), leftSerialized.begin(), leftSerialized.end());
  A.insert(A.end(), rightSerialized.begin(), rightSerialized.end());
  return A;
}

Node *deSerialize(vector<int> &A) {
  if (A.size() == 0) {
    return NULL;
  }
  int val = A[0];
  A.erase(A.begin());
  if (val == -1) {
    return NULL;
  }
  Node *root = new Node(val);
  root->left = deSerialize(A);
  root->right = deSerialize(A);
  return root;
}

void inorder(Node *root) {
  if (root == NULL) {
    return;
  }
  inorder(root->left);
  cout << root->data << " ";
  inorder(root->right);
}

int main() {
  Node *root = new Node(20);
  root->left = new Node(8);
  root->right = new Node(22);
  root->left->left = new Node(4);
  root->left->right = new Node(12);
  root->left->right->left = new Node(10);
  root->left->right->right = new Node(14);
  vector<int> serialized = serialize(root);
  for (int i = 0; i < serialized.size(); i++) {
    cout << serialized[i] << " ";
  }
  cout << endl;
  Node *root2 = deSerialize(serialized);
  inorder(root2);
  return 0;
}