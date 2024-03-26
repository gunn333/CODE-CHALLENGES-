//! Segregate Even and Odd Nodes in a Linked List (GeeksForGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1?page=2&category=Linked%20List&sortBy=submissions

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

Node *divide(int N, Node *head) {
  vector<int> ans;
  Node *temp = head;
  while (temp) {
    if (temp->data % 2 == 0) {
      ans.push_back(temp->data);
    }
    temp = temp->next;
  }
  temp = head;
  while (temp) {
    if (temp->data % 2 != 0) {
      ans.push_back(temp->data);
    }
    temp = temp->next;
  }
  temp = head;
  int i = 0;
  while (temp) {
    temp->data = ans[i++];
    temp = temp->next;
  }

  return head;
}

int main() {
  Node *head = new Node(17);
  head->next = new Node(15);
  head->next->next = new Node(8);
  head->next->next->next = new Node(9);
  head->next->next->next->next = new Node(2);
  head->next->next->next->next->next = new Node(4);
  head->next->next->next->next->next->next = new Node(6);
  head->next->next->next->next->next->next->next = new Node(7);
  head->next->next->next->next->next->next->next->next = new Node(10);

  Node *result = divide(8, head);
  while (result != NULL) {
    cout << result->data << " ";
    result = result->next;
  }
  return 0;
}