//! Validate Binary Tree (LeetCode 1361)

// Question Link:
// https://leetcode.com/problems/validate-binary-tree-nodes/description/

#include <bits/stdc++.h>
using namespace std;

bool validateBinaryTreeNodes(int n, vector<int> &leftChild,
                             vector<int> &rightChild) {
  // Indegree is the number of incoming edges to a node
  vector<int> indegree(n, 0);
  // Adjacency List is a list of nodes that are connected to a particular node
  vector<int> adjacenyList[n];
  for (int i = 0; i < n; i++) {
    if (leftChild[i] != -1) {
      adjacenyList[i].push_back(leftChild[i]);
      indegree[leftChild[i]]++;
    }
    if (rightChild[i] != -1) {
      adjacenyList[i].push_back(rightChild[i]);
      indegree[rightChild[i]]++;
    }
  }
  int root;
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (indegree[i] == 0) {
      root = i;
      count++;
    }
  }
  if (count > 1 || count < 1) {
    return false;
  }
  vector<bool> visited(n, false);
  queue<int> q;
  q.push(root);
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    if (visited[curr]) {
      return false;
    }
    visited[curr] = true;
    for (int i = 0; i < adjacenyList[curr].size(); i++) {
      q.push(adjacenyList[curr][i]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (!visited[i] || adjacenyList[i].size() > 2) {
      return false;
    }
  }
  return true;
}

int main() {
  int n = 4;
  vector<int> leftChild = {1, -1, 3, -1};
  vector<int> rightChild = {2, -1, -1, -1};
  cout << validateBinaryTreeNodes(n, leftChild, rightChild) << endl;
  return 0;
}