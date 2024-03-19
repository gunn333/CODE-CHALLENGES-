//! Linked List that is sorted alternatively (GeeksforGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

void sort(Node **head) {
  if (head == nullptr) {
    return;
  }

  vector<int> result;
  //   temp = *head isliye kiya hain kyuki head ko change nhi krna hain but if
  //   we use temp = head then head will also change
  Node *temp = *head;
  while (temp != nullptr) {
    result.push_back(temp->data);
    temp = temp->next;
  }

  std::sort(result.begin(), result.end());

  temp = *head;
  for (int i = 0; i < result.size(); i++) {
    temp->data = result[i];
    temp = temp->next;
  }
}

void printList(Node *head) {
  while (head != nullptr) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}