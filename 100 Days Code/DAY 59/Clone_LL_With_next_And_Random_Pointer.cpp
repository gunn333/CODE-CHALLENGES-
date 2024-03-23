//! Clone a Linked List with next and random pointer (GeeksForGeeks)

// Question Link:
// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node *arb;
  Node(int x) {
    data = x;
    next = arb = NULL;
  }
};

Node *copyList(Node *head) {
  Node *original = head;
  while (original != nullptr) {
    Node *dup = new Node(original->data);
    dup->next = original->next;
    original->next = dup;
    original = original->next->next;
  }
  original = head;
  while (original != nullptr) {
    Node *dup = original->next;
    if (original->arb != nullptr) {
      dup->arb = original->arb->next;
    }
    original = original->next->next;
  }
  original = head;
  Node *clonehead = head->next;
  Node *clone = clonehead;

  while (original != nullptr) {
    original->next = clone->next;
    original = original->next;

    if (original != nullptr) {
      clone->next = original->next;
      clone = clone->next;
    }
  }
  return clonehead;
}

int main() {
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);

  head->arb = head->next->next;
  head->next->arb = head;
  head->next->next->arb = head->next->next->next->next;
  head->next->next->next->arb = head->next->next->next->next;
  head->next->next->next->next->arb = head->next;

  Node *clone = copyList(head);
  while (clone != nullptr) {
    cout << "Data: " << clone->data << ", ";
    cout << "Arb: " << clone->arb->data << endl;
    clone = clone->next;
  }
  return 0;
}