//! Reverse Level Order Traversal (GeeksForGeeks)

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left, *right;
};

vector<int> reverseLevelOrder(Node *root) {
  // v will store the reverse level order traversal
  vector<int> v;
  queue<Node *> q;
  q.push(root);
  while (!q.empty()) {
    Node *front = q.front();
    q.pop();
    v.push_back(front->data);
    if (front->right) {
      q.push(front->right);
    }
    if (front->left) {
      q.push(front->left);
    }
  }
  reverse(v.begin(), v.end());
  return v;
}

Node *newNode(int data) {
  Node *temp = new Node;
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

int main() {
  Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);

  vector<int> v = reverseLevelOrder(root);
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  return 0;
}