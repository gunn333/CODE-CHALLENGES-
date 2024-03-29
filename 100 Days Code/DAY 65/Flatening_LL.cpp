//! Flattening a Linked List (geeeksforgeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1?page=2&category=Linked%20List&sortBy=submissions

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node *bottom;

  Node(int x) {
    data = x;
    next = NULL;
    bottom = NULL;
  }
};

Node *merge(Node *root1, Node *root2) {
  if (root2 == NULL)
    return root1;
  if (root1 == NULL)
    return root2;

  Node *root3;

  if (root1->data <= root2->data) {
    root3 = root1;
    root3->bottom = merge(root1->bottom, root2);
  } else {
    root3 = root2;
    root3->bottom = merge(root1, root2->bottom);
  }

  return root3;
}
Node *flatten(Node *root) {
  Node *r1 = root;
  Node *r2 = root->next;
  while (r2) {
    r1 = merge(r1, r2);
    r2 = r2->next;
  }

  return r1;
}

int main() {
  Node *root = new Node(5);
  root->next = new Node(10);
  root->next->next = new Node(19);
  root->next->next->next = new Node(28);

  root->bottom = new Node(7);
  root->bottom->bottom = new Node(8);
  root->bottom->bottom->bottom = new Node(30);

  root->next->bottom = new Node(20);

  root->next->next->bottom = new Node(22);
  root->next->next->bottom->bottom = new Node(50);

  root->next->next->next->bottom = new Node(35);
  root->next->next->next->bottom->bottom = new Node(40);
  root->next->next->next->bottom->bottom->bottom = new Node(45);

  Node *ans = flatten(root);

  while (ans) {
    cout << ans->data << " ";
    ans = ans->bottom;
  }

  return 0;
}