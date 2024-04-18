//! Burning Tree (GeeeksforGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/burning-tree/1?page=1&category=BFS&sortBy=submissions

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = right = NULL;
  }
};
// ans is used to store the maximum distance from the target node to the leaf
// node
int ans = 0;

// this find function is used to find the target node in the tree and calculate
// the distance from the target node to the leaf node
int find(Node *root, int target, int distance) {
  if (root == NULL) {
    // distance represents the distance from the target node to the leaf node
    
    ans = max(ans, distance - 1);
    return 0;
  }
  // If the target node is found at root or the distance is greater than 0
  if (root->data == target || distance > 0) {
    find(root->left, target, distance + 1);
    find(root->right, target, distance + 1);
    return distance - 1;
  } else {
    int left = find(root->left, target, distance);
    int right = find(root->right, target, distance);
    if (left < 0) {
      ans = max(ans, -left);
      find(root->right, target, 1 - left);
      return left - 1;
    }
    if (right < 0) {
      ans = max(ans, -right);
      find(root->left, target, 1 - right);
      return right - 1;
    }
  }
  return 0;
}

int minTime(Node *root, int targetget) {
  find(root, targetget, 0);
  return ans;
}