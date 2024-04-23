//! Print Adjacency List (GeeksforGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printGraph(int V, vector<pair<int, int>> edges) {
  // Create an adjacency list
  vector<vector<int>> adj(V);
  // Add edges to the adjacency list
  for (int i = 0; i < edges.size(); i++) {
    adj[edges[i].first].push_back(edges[i].second);
    adj[edges[i].second].push_back(edges[i].first);
  }
  return adj;
}

int main() {
  int V = 5;
  vector<pair<int, int>> edges = {{0, 1}, {0, 4}, {1, 2}, {1, 3},
                                  {1, 4}, {2, 3}, {3, 4}};
  vector<vector<int>> adj = printGraph(V, edges);
  for (int i = 0; i < adj.size(); i++) {
    cout << i;
    for (int j = 0; j < adj[i].size(); j++) {
      cout << "->" << adj[i][j];
    }
    cout << endl;
  }
  return 0;
}