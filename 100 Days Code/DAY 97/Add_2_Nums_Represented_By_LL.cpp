//! Add Two Numbers represented by Linked List (GeeeksforGeeks)

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

Node *reverse(Node *curr, Node *prev) {
  if (curr == NULL)
    return prev;

  Node *front = curr->next;
  curr->next = prev;
  return reverse(front, curr);
}
struct Node *addTwoLists(struct Node *num1, struct Node *num2) {
  num1 = reverse(num1, NULL);
  num2 = reverse(num2, NULL);
  Node *curr1 = num1;
  Node *curr2 = num2;
  Node *head = new Node(0);
  Node *tail = head;
  int carry = 0;
  while (curr1 && curr2) {
    int sum = curr1->data + curr2->data + carry;
    tail->next = new Node(sum % 10);
    tail = tail->next;
    curr1 = curr1->next;
    curr2 = curr2->next;
    carry = sum / 10;
  }
  while (curr1) {
    int sum = curr1->data + carry;
    tail->next = new Node(sum % 10);
    tail = tail->next;
    curr1 = curr1->next;
    carry = sum / 10;
  }
  while (curr2) {
    int sum = curr2->data + carry;
    tail->next = new Node(sum % 10);
    tail = tail->next;
    curr2 = curr2->next;
    carry = sum / 10;
  }
  while (carry) {
    tail->next = new Node(carry % 10);
    carry = carry / 10;
  }
  head = reverse(head->next, NULL);

  while (head->data == 0 && head->next != NULL) {
    head = head->next;
  }
  return head;
}

int main() {
  Node *head1 = new Node(1);
  head1->next = new Node(2);
  head1->next->next = new Node(3);
  Node *head2 = new Node(4);
  head2->next = new Node(5);
  head2->next->next = new Node(6);
  Node *res = addTwoLists(head1, head2);
  while (res) {
    cout << res->data << " ";
    res = res->next;
  }
  return 0;
}