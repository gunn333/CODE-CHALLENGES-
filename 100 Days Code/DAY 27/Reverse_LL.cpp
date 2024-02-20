//! Reverse a linked list (GeeksforGeeks Problem)

// Question Link:
// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

#include <iostream>
using namespace std;

// Node structure
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

// Function to reverse the linked list
struct Node *reverseList(struct Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  Node *curr = reverseList(head->next);
  head->next->next = head;
  head->next = NULL;
  return curr;
}

// Function to print the linked list
void printList(struct Node *head) {
  struct Node *temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

// Driver code
int main() {
  struct Node *head = new Node(10);
  head->next = new Node(20);
  head->next->next = new Node(30);
  head->next->next->next = new Node(40);
  head->next->next->next->next = new Node(50);
  head->next->next->next->next->next = new Node(60);
  head->next->next->next->next->next->next = new Node(70);
  head->next->next->next->next->next->next->next = new Node(80);
  head->next->next->next->next->next->next->next->next = new Node(90);
  head->next->next->next->next->next->next->next->next->next = new Node(100);
  cout << "Original Linked List: ";
  printList(head);
  head = reverseList(head);
  cout << "\nReversed Linked List: ";
  printList(head);
  return 0;
}