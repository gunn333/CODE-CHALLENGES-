//! Delete without Head Pointer
//! (https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1)

#include <bits/stdc++.h>

struct Node {
  int data;
  Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

using namespace std;

void deleteNode(Node *del_node) {
  Node *temp = del_node->next;
  del_node->data = temp->data;
  del_node->next = temp->next;
  delete (temp);
}

int main() {
  Node *head = new Node(10);
  head->next = new Node(20);
  head->next->next = new Node(30);
  head->next->next->next = new Node(40);
  Node *del_node = head->next;
  deleteNode(del_node);
  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
  return 0;
}