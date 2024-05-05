//! Vertical Sum (GeeksforGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/vertical-sum/1

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left, *right;
  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

vector<int> verticalSum(Node *root) {
  // map to store the vertical sum
  map<int, int> mp;
  // queue to store the nodes
  queue<pair<Node *, int>> q;
  // pushing the root node and horizontal distance
  q.push({root, 0});
  while (!q.empty()) {
    // getting the front element
    pair<Node *, int> front = q.front();
    q.pop();
    // getting the node and horizontal distance
    Node *node = front.first;
    int hd = front.second;
    // adding the node data to the horizontal distance
    mp[hd] += node->data;
    // if left child is present then push it to the queue
    if (node->left) {
      q.push({node->left, hd - 1});
    }
    // if right child is present then push it to the queue
    if (node->right) {
      q.push({node->right, hd + 1});
    }
  }
  // vector to store the vertical sum
  vector<int> ans;
  // iterating over the map and storing the vertical sum
  // auto means the type of x is automatically deduced
  // auto x : mp means for each x in mp do the following
  // auto is basically used to avoid writing the type of x explicitly which is
  // map<int, int>::iterator
  for (auto x : mp) {
    ans.push_back(x.second);
  }
  return ans;
}

int main() {
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);
  root->right->right = new Node(7);
  vector<int> res = verticalSum(root);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  return 0;
}
