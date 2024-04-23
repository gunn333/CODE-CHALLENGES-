//! DFS of a graph (GeeksforGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

#include <bits/stdc++.h>
using namespace std;

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
  vector<bool> visited(V, false);
  vector<int> dfs;

  // Helper function to perform DFS
  // [&] is used to capture all the variables used in the lambda function by
  // reference and not by value
  // [&] (int node) is the lambda function that takes an integer node as an
  // argument and returns void as the return type
  function<void(int)> dfsHelper = [&](int node) {
    // Mark the current node as visited
    visited[node] = true;
    // Add the current node to the DFS traversal
    dfs.push_back(node);
    // Traverse all the adjacent nodes of the current node
    for (int i = 0; i < adj[node].size(); i++) {
      // If the adjacent node is not visited, recursively call the DFS helper
      if (!visited[adj[node][i]]) {
        dfsHelper(adj[node][i]);
      }
    }
  };

  // Traverse all the nodes of the graph
  for (int i = 0; i < V; i++) {
    // If the node is not visited, call the DFS helper
    if (!visited[i]) {
      dfsHelper(i);
    }
  }
  // Return the DFS traversal
  return dfs;
}

int main() {
  int V = 4;
  vector<int> adj[V];
  adj[0].push_back(1);
  adj[0].push_back(2);
  adj[1].push_back(2);
  adj[2].push_back(0);
  adj[2].push_back(3);
  adj[3].push_back(3);
  vector<int> dfs = dfsOfGraph(V, adj);
  for (int i = 0; i < dfs.size(); i++) {
    cout << dfs[i] << " ";
  }
  return 0;
}