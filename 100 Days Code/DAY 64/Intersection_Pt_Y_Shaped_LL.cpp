//! Intersection Point in Y Shaped Linked Lists (GeeeksforGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1?page=1&category=Linked%20List&sortBy=submissions

/*
1. Go through all the nodes of first LL and make the next pointer of each node
to point itself.

2. Go thorugh all the nodes of second LL, if a node points to itself, it is the
intersection.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *next;
};

int intersectPoint(Node *head1, Node *head2) {
  Node *curr = head1;
  while (curr) {
    if (curr->next == NULL)
      break;
    Node *temp = curr;
    curr = curr->next;
    temp->next = temp;
  }

  curr = head2;
  while (curr->next) {
    if (curr->next == curr)
      return curr->data;
    curr = curr->next;
  }

  return -1;
}

int main() {
  Node *newNode;
  Node *head1 = new Node();
  head1->data = 10;

  Node *head2 = new Node();
  head2->data = 3;

  newNode = new Node();
  newNode->data = 6;
  head2->next = newNode;

  newNode = new Node();
  newNode->data = 9;
  head2->next->next = newNode;

  newNode = new Node();
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next = newNode;

  newNode = new Node();
  newNode->data = 30;
  head1->next->next = newNode;

  head1->next->next->next = NULL;

  cout << intersectPoint(head1, head2) << endl;

  return 0;
}
