//! Remove Every Kth Node (GeeksForGeeks)

// Question Link:
// https://leetcode.com/problems/sum-of-distances-in-tree/description/?envType=daily-question&envId=2024-04-28

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

Node *deleteK(Node *head, int K) {
  // If K is 1, then we have to delete all the nodes from the linked list
  if (K == 1) {
    return NULL;
  }
  // k is the counter to keep track of the Kth node
  int k = 0;
  // temp is the current node which is head for now
  Node *temp = head;
  // prev is the previous node of the current node
  // prev is NULL for now because there is no previous node of the head node
  Node *prev = NULL;
  // while temp is not NULL
  while (temp != NULL) {
    // nxt is the next node of the current node
    Node *nxt = temp->next;
    // increment the counter because we have moved to the next node
    k++;
    // if the counter is equal to K, then we have to delete the current node
    if (k == K) {
      // if the previous node is NULL, then the head node is to be deleted
      // prev -> next = nxt, means the next node of the head node is the new
      // head
      // delete the head node
      // k = 0, because we have to start counting from the beginning
      prev->next = nxt;
      delete (temp);
      k = 0;
    }
    // if the counter is not equal to K, then the current node is not to be
    // deleted
    prev = temp;
    // move to the next node
    temp = nxt;
  }
  // return the head node
  return head;
}

void printList(Node *head) {
  Node *temp = head;
  while (temp) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main() {
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);
  head->next->next->next->next->next = new Node(6);
  head->next->next->next->next->next->next = new Node(7);
  head->next->next->next->next->next->next->next = new Node(8);
  head->next->next->next->next->next->next->next->next = new Node(9);
  head->next->next->next->next->next->next->next->next->next = new Node(10);

  int K = 3;
  head = deleteK(head, K);
  printList(head);

  return 0;
}