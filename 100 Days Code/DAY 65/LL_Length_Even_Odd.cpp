//! Linked List Length Even or Odd (GeeeksforGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/linked-list-length-even-or-odd/1?page=3&category=Linked%20List&sortBy=submissions

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

int isLengthEvenOrOdd(struct Node *head) {
  if (head == NULL) {
    return 0;
  }
  struct Node *temp = head;
  int count = 0;
  while (temp != NULL) {
    count++;
    temp = temp->next;
  }

  // Length of LinkedList is Odd
  return (count % 2 != 0);
}

int main() {
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);

  cout << isLengthEvenOrOdd(head) << endl;

  return 0;
}