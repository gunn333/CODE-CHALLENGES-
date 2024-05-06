//! Print all nodes that don't have a sibling (GeeksforGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1

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

vector<int> noSibling(Node *node) {
  queue<Node *> q;
  vector<int> ans;
  // If the node is NULL then it means there is no node in the tree so return
  // empty vector
  if (node == NULL) {
    return ans;
  }
  // push the root node into the queue
  q.push(node);
  // Traverse the tree level by level
  while (q.empty() == false) {
    Node *front = q.front();
    q.pop();
    // if the front node has both left child but no right child then push the
    // left child data into the vector
    if (front->left != NULL) {
      if (front->right == NULL) {
        ans.push_back(front->left->data);
      }
      // push the left child into the queue again to check if it has any sibling
      // or not
      q.push(front->left);
    }
    // if the front node has both right child but no left child then push the
    // right child data into the vector
    if (front->right != NULL) {
      if (front->left == NULL) {
        ans.push_back(front->right->data);
      }
      q.push(front->right);
    }
  }
  // If the vector is empty then it means there is no node in the tree that
  // don't have a sibling so return {-1}
  if (ans.size() == 0) {
    return {-1};
  } else {
    // Sort the vector and return the vector
    sort(ans.begin(), ans.end());
    return ans;
  }
}

int main() {
  // Example 1
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->right = new Node(4);
  root->right->left = new Node(5);
  vector<int> res = noSibling(root);
  // Output: 4 5
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;

  return 0;
}