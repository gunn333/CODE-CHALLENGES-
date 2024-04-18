//! Merge 2 BST's (GeeksForGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/merge-two-bst-s/1?page=3&category=Tree&sprint=94ade6723438d94ecf0c00c3937dad55&sortBy=submissions

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left, *right;

  Node(int x) {
    data = x;
    left = right = NULL;
  }
};

vector<int> merge(Node *root1, Node *root2) {
  vector<int> res;
  //  s1 and s2 vectors are used to store the inorder traversal of the 2 BST's
  vector<Node *> s1, s2;

  Node *curr1 = root1, *curr2 = root2;

  // Till both the BST's are not completely traversed
  while (curr1 != NULL || curr2 != NULL || !s1.empty() || !s2.empty()) {
    while (curr1 != NULL) {
      // Push the leftmost node of the BST
      s1.push_back(curr1);
      // Move to the left child
      curr1 = curr1->left;
    }

    while (curr2 != NULL) {
      s2.push_back(curr2);
      curr2 = curr2->left;
    }

    if (s1.empty() || (!s2.empty() && s2.back()->data <= s1.back()->data)) {
      // If the top element of the second BST is smaller than the top element of
      // the first BST
      // then push the top element of the second BST and move to the right child
      // of the second BST
      curr2 = s2.back();
      s2.pop_back();
      res.push_back(curr2->data);
      curr2 = curr2->right;
    } else {
      // If the top element of the first BST is smaller than the top element of
      // the second BST then push the top element of the first BST and move to
      // the right child of the first BST
      curr1 = s1.back();
      s1.pop_back();
      res.push_back(curr1->data);
      curr1 = curr1->right;
    }
  }
  return res;
}

int main() {
  Node *root1 = new Node(3);
  root1->left = new Node(1);
  root1->right = new Node(5);

  Node *root2 = new Node(4);
  root2->left = new Node(2);
  root2->right = new Node(6);

  vector<int> res = merge(root1, root2);

  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  return 0;
}
