//! Path Exist in Graph (Leetcode 1971)

// Question Link:
// https://leetcode.com/problems/find-if-path-exists-in-graph/

#include <bits/stdc++.h>
using namespace std;

void AddEdge(vector<int> adj[], int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

// BFS Approach
bool validPath(int n, vector<vector<int>> &edges, int start, int end) {
  vector<int> adj_list[n];
  for (int i = 0; i < edges.size(); i++) {
    // edges[i][0] -> Source Vertex (u)
    // edges[i][1] -> Destination Vertex (v)
    // Example:
    // edges[i] = {0, 3}
    // AddEdge(adj_list, edges[i][0], edges[i][1]);
    // edges[i][0] = 0
    // edges[i][1] = 3
    AddEdge(adj_list, edges[i][0], edges[i][1]);
  }
  // start -> Starting Vertex
  // end -> Ending Vertex
  queue<int> Exploration;
  vector<bool> visited(n, false);
  Exploration.push(start);
  visited[start] = true;
  while (!Exploration.empty()) {
    int frontnode = Exploration.front();
    Exploration.pop();
    for (int i = 0; i < adj_list[frontnode].size(); i++) {
      // adj_list[frontnode][i] -> Neighbour Vertex of frontnode
      // For Example:
      // 1 -> 0, 2, 3
      // adj_list[firstnode][i] = 0 when i = 0 , frontnode = 1
      // adj_list[firstnode][i] = 2 when i = 1 , frontnode = 1
      // adj_list[firstnode][i] = 3 when i = 2 , frontnode = 1
      if (!visited[adj_list[frontnode][i]]) {
        Exploration.push(adj_list[frontnode][i]);
        visited[adj_list[frontnode][i]] = true;
      }
    }
  }
  // If visited[end] is true then there is a path between start and end vertex
  // Otherwise, there is no path between start and end vertex
  return visited[end];
}

int main() {
  // n -> Number of Vertices
  // edges -> Edges between Vertices
  // start -> Starting Vertex
  // end -> Ending Vertex
  int n = 5;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
  int start = 0;
  int end = 4;
  cout << validPath(n, edges, start, end) << endl;
  return 0;
}
