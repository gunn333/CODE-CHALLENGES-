//! Left View of Binary Tree (GeeksforGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *left;
  struct Node *right;

  Node(int x) {
    data = x;
    left = right = NULL;
  }
};

vector<int> leftView(Node *root) {
  vector<int> result;
  if (root == NULL) {
    return result;
  }
  queue<Node *> q;
  q.push(root);
  q.push(NULL);
  result.push_back(root->data);
  while (!q.empty()) {
    Node *front = q.front();
    q.pop();
    if (front != NULL) {
      if (front->left != NULL) {
        q.push(front->left);
      }
      if (front->right != NULL) {
        q.push(front->right);
      }
    } else {
      if (!q.empty()) {
        result.push_back(q.front()->data);
        q.push(NULL);
      }
    }
  }
  return result;
}

vector<int> rightView(Node *root) {
  vector<int> result;
  if (root == NULL) {
    return result;
  }
  queue<Node *> q;
  q.push(root);
  q.push(NULL);
  result.push_back(root->data);
  while (!q.empty()) {
    Node *front = q.front();
    q.pop();
    if (front != NULL) {
      if (front->right != NULL) {
        q.push(front->right);
      }
      if (front->left != NULL) {
        q.push(front->left);
      }
    } else {
      if (!q.empty()) {
        result.push_back(q.front()->data);
        q.push(NULL);
      }
    }
  }
  return result;
}

int main() {
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  vector<int> left = leftView(root);
  for (int i = 0; i < left.size(); i++) {
    cout << left[i] << " ";
  }
  cout << endl;

  vector<int> right = rightView(root);
  for (int i = 0; i < right.size(); i++) {
    cout << right[i] << " ";
  }
  cout << endl;

  return 0;
}