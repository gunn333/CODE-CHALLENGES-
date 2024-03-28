//! Add 1 to a number represented as a linked list (geeeksforgeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1?page=1&category=Linked%20List&sortBy=submissions

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

Node *add(int &carry, Node *&head) {

  // stop at tail to add 1
  if (head->next == NULL) {
    int sum = head->data + 1;
    int digit = sum % 10;
    carry = sum / 10;

    head->data = digit;

    return head;
  }

  // with this we will traverse backwards
  add(carry, head->next);

  // add logic for special cases
  // like 493,  999, 9482
  if (carry != 0) {
    int sum = head->data + 1;
    int digit = sum % 10;
    carry = sum / 10;
    head->data = digit;
  }

  return head;
}

Node *addOne(Node *head) {
  // return head of list after adding one
  int carry = 0;
  Node *ans = add(carry, head);

  // new node for case : 9, 99, 999 ans so on
  if (ans->data == 0) {
    Node *newNode = new Node(1);
    newNode->next = ans;
    ans = newNode;
  }

  return ans;
}

int main() {
  Node *head = new Node(9);
  head->next = new Node(9);
  head->next->next = new Node(9);

  Node *ans = addOne(head);

  while (ans) {
    cout << ans->data << " ";
    ans = ans->next;
  }

  return 0;
}