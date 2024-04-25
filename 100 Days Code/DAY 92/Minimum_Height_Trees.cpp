//! Minimum Height Trees (LeetCode 310)

// Question Link:
// https://leetcode.com/problems/minimum-height-trees/

#include <bits/stdc++.h>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<pair<int, int>> &edges) {
  // vector<unordered_set<int>> means a vector of sets (unordered)
  // adj(n) is adjacency list of the graph
  vector<unordered_set<int>> adj(n);
  // Create adjacency list from edges
  // p : edges means pair of edges (u, v)
  for (pair<int, int> p : edges) {
    // adj[p.first] means the first element of the pair
    // adj[p.second] means the second element of the pair
    adj[p.first].insert(p.second);
    adj[p.second].insert(p.first);
  }

  // Corner case
  // current vector is used to store the leaf nodes
  vector<int> current;
  // If there is only one node in the graph
  if (n == 1) {
    // Push the 0th node in the current vector
    current.push_back(0);
    // Return the current vector
    return current;
  }
  // Create first leaf layer
  for (int i = 0; i < adj.size(); ++i) {
    if (adj[i].size() == 1) {
      current.push_back(i);
    }
  }
  // BFS the graph
  while (true) {
    vector<int> next;
    for (int node : current) {
      for (int neighbor : adj[node]) {
        adj[neighbor].erase(node);
        if (adj[neighbor].size() == 1)
          next.push_back(neighbor);
      }
    }
    if (next.empty())
      return current;
    current = next;
  }
}
