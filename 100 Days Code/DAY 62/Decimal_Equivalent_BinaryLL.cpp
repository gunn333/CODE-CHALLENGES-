//! Decimal Equivalent of Binary Linked List (GeeksForGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/decimal-equivalent-of-binary-linked-list/1?page=3&category=Linked%20List&sortBy=submissions

#include <bits/stdc++.h>
using namespace std;

const long long unsigned int MOD = 1000000007;

struct Node {
  int data;
  Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

long long unsigned int decimalValue(Node *head) {
  string val;
  Node *node = head;

  while (node) {
    val += to_string(node->data);
    node = node->next;
  }

  long long unsigned int num = 0;
  int k = 1;

  for (int i = val.size() - 1; i >= 0; i--) {
    if (val[i] - '0' == 1) {
      num = (num + k) % MOD;
    }
    k = (k * 2) % MOD;
  }

  return num % MOD;
}

int main() {
  Node *head = new Node(1);
  head->next = new Node(0);
  head->next->next = new Node(1);
  head->next->next->next = new Node(1);

  cout << decimalValue(head);

  return 0;
}