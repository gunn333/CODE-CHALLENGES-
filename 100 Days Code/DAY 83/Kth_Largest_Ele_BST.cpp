//! Kth Largest Element in a BST (GeeksForGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1?page=2&category=Tree,Binary%20Search%20Tree&sortBy=submissions

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

int kthLargest(Node *root, int k) {
  if (root == NULL) {
    return -1;
  }
  vector<int> array;
  queue<Node *> q;
  q.push(root);
  q.push(NULL);
  while (!q.empty()) {
    Node *front = q.front();
    q.pop();
    if (front != NULL) {
      array.push_back(front->data);
      if (front->left != NULL) {
        q.push(front->left);
      }
      if (front->right != NULL) {
        q.push(front->right);
      }
    } else {
      if (!q.empty()) {
        q.push(NULL);
      }
    }
  }
  sort(array.begin(), array.end());
  return array[array.size() - k];
}

int main() {
  Node *root = new Node(50);
  root->left = new Node(30);
  root->right = new Node(70);
  root->left->left = new Node(20);
  root->left->right = new Node(40);
  root->right->left = new Node(60);
  root->right->right = new Node(80);
  cout << kthLargest(root, 3) << endl;
  return 0;
}