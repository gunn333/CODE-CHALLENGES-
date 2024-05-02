//! Arrange Consonants and Vowels (GeeeksforGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/arrange-consonants-and-vowels/1

#include <bits/stdc++.h>
using namespace std;

struct Node {
  char data;
  struct Node *next;

  Node(char x) {
    data = x;
    next = NULL;
  }
};

void display(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    cout << temp->data;
    temp = temp->next;
  }
  cout << endl;
}

struct Node *arrangeCV(Node *head) {
  // vowels will store the vowels
  // v is the head of the vowels for traversal
  Node *vowels = new Node('v');
  // consonants will store the consonants
  // c is the head of the consonants for traversal
  Node *consonants = new Node('c');

  Node *v = vowels;
  Node *c = consonants;

  // Traverse the linked list
  while (head != NULL) {
    // If the character is a vowel
    if (head->data == 'a' || head->data == 'e' || head->data == 'i' ||
        head->data == 'o' || head->data == 'u') {
      // Add the head(ie. the vowel) to the vowels linked list
      v->next = head;
      // Move the v to the next node
      v = v->next;
    }
    // If the character is a consonant
    else {
      // Add the head(ie. the consonant) to the consonants linked list
      c->next = head;
      // Move the c to the next node
      c = c->next;
    }
    // Move the head to the next node for traversal of the linked list
    head = head->next;
  }
  // Add NULL to the end of the consonants marking the end of the linked list
  c->next = NULL;
  // v->next ko consonants->next pe point kara do making the vowels linked list
  // to link with the consonants linked list in the end
  v->next = consonants->next;
  // Return the next of the vowels linked list
  return vowels->next;
}

int main() {
  // Small test case
  Node *head = new Node('a');
  head->next = new Node('b');
  head->next->next = new Node('c');
  head->next->next->next = new Node('d');
  head->next->next->next->next = new Node('e');
  head->next->next->next->next->next = new Node('f');

  cout << "Original Linked List: ";
  display(head);
  cout << "Linked List after arranging vowels and consonants: ";
  display(arrangeCV(head));
  return 0;
}