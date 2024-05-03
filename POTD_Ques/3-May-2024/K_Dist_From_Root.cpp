//! K Distance from Root (GeekForGeeks)

// Question Link :
// https://www.geeksforgeeks.org/problems/k-distance-from-root/1

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

vector<int> Kdistance(struct Node *root, int k) {
  // ans is used to store the answer
  vector<int> ans;

  if (root == NULL) {
    // If the root is NULL then return the empty vector ans
    return ans;
  }
  // If k is 0 then push the root data to the ans vector and return the ans
  // vector
  if (k == 0) {
    ans.push_back(root->data);
    return ans;
  }
  queue<Node *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty()) {
    Node *front = q.front();
    q.pop();
    // If front is NULL means we have traversed all the nodes of the current
    // level
    if (front == NULL) {
      // Decrement k because we have traversed one level
      /*
      We decrement the value of k. This is because each time we encounter a
      NULL node, it signifies the end of a level in the tree. So, we decrement k
      to keep track of how many levels we have traversed.
      */
      k--;
      // If k is 0 means we have reached the kth level
      if (k == 0) {
        break;
      }
      // Push NULL to the queue to mark the end of the level and to keep track
      // of the levels
      q.push(NULL);
    } else {
      if (front->left)
        q.push(front->left);
      if (front->right)
        q.push(front->right);
    }
  }

  while (!q.empty()) {
    Node *front = q.front();
    q.pop();
    ans.push_back(front->data);
  }
  return ans;
}

int main() {
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(8);

  vector<int> ans = Kdistance(root, 2);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}