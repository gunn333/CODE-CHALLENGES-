//! Count Nodes Of a Linked List (GeeksForGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/count-nodes-of-linked-list/1?page=1&category=Linked%20List&sortBy=submissions

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

int getCount(struct Node *head) {
  int count = 0;

  struct Node *temp = head;
  while (temp != NULL) {
    temp = temp->next;
    count++;
  }
  return count;
}

int main() {
  Node *head = new Node(10);
  head->next = new Node(20);
  head->next->next = new Node(30);
  head->next->next->next = new Node(40);
  cout << getCount(head);
  return 0;
}