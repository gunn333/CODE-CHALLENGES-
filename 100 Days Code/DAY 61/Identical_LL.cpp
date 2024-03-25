//! Identical Linked List (GeeksForGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/identical-linked-lists/1?page=2&category=Linked%20List&sortBy=submissions

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

bool areIdentical(struct Node *head1, struct Node *head2) {
  Node *temp1 = head1;
  Node *temp2 = head2;

  while (temp1 != NULL && temp2 != NULL) {
    if (temp1->data != temp2->data) {
      return false;
    }
    temp1 = temp1->next;
    temp2 = temp2->next;
  }
  if (temp1 != NULL || temp2 != NULL) {
    return false;
  } else {
    return true;
  }
}

int main() {
  Node *head1 = new Node(1);
  head1->next = new Node(2);
  head1->next->next = new Node(3);
  head1->next->next->next = new Node(4);

  Node *head2 = new Node(1);
  head2->next = new Node(2);
  head2->next->next = new Node(3);
  head2->next->next->next = new Node(4);

  cout << areIdentical(head1, head2);

  return 0;
}