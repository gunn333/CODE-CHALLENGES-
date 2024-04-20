//! Leaf Under Budget (GeeksForGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/leaf-under-budget/1?page=4&category=Tree&sortBy=submissions

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

int getCount(Node *root, int k) {
  // code here
  queue<Node *> q;
  q.push(root);
  int level = 1, count = 0;
  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; ++i) {
      Node *temp = q.front();
      q.pop();
      if (temp->left == NULL && temp->right == NULL) {
        if (k >= level)
          k -= level;
        else
          return count;
        ++count;
      }
      if (temp->left)
        q.push(temp->left);
      if (temp->right)
        q.push(temp->right);
    }
    ++level;
  }
  return count;
}

int main() {
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);
  root->left->left->left = new Node(8);
  root->left->left->right = new Node(9);
  root->left->right->left = new Node(12);
  root->right->right->left = new Node(10);
  root->right->right->left->right = new Node(11);
  root->left->left->right->left = new Node(13);
  root->left->left->right->right = new Node(14);
  root->left->left->right->right->left = new Node(15);
  int k = 45;
  cout << getCount(root, k) << endl;
  return 0;
}