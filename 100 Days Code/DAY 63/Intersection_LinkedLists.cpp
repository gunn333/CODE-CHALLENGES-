//! Intersection of Two Linked Lists (GeeksForGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1?page=2&category=Linked%20List&sortBy=submissions

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *next;

  Node(int val) {
    data = val;
    next = NULL;
  }
};

Node *findIntersection(Node *head1, Node *head2) {
  Node *out = NULL;
  Node *run = NULL;
  while (head1 != NULL and head2 != NULL) {
    if (head1->data == head2->data) {
      if (out == NULL) {
        out = new Node(head1->data);
        run = out;
      } else {
        Node *tmp = new Node(head1->data);
        run->next = tmp;
        run = run->next;
      }
      head1 = head1->next;
      head2 = head2->next;
    } else {
      if (head1->data < head2->data) {
        head1 = head1->next;
      } else {
        head2 = head2->next;
      }
    }
  }
  return out;
}

void printList(Node *head) {
  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  Node *head1 = new Node(1);
  head1->next = new Node(2);
  head1->next->next = new Node(3);
  head1->next->next->next = new Node(4);
  head1->next->next->next->next = new Node(6);

  Node *head2 = new Node(2);
  head2->next = new Node(4);
  head2->next->next = new Node(6);
  head2->next->next->next = new Node(8);

  Node *out = findIntersection(head1, head2);
  printList(out);

  return 0;
}
