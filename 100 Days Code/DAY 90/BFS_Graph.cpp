//! BFS of a graph (GeeksforGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
  vector<bool> visited(V, false);
  vector<int> bfs;
  queue<int> Explore;
  visited[0] = true;
  Explore.push(0);
  while (!Explore.empty()) {
    int frontnode = Explore.front();
    Explore.pop();
    bfs.push_back(frontnode);

    for (int i = 0; i < adj[frontnode].size(); i++) {
      if (!visited[adj[frontnode][i]]) {
        visited[adj[frontnode][i]] = true;
        Explore.push(adj[frontnode][i]);
      }
    }
  }
  return bfs;
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
  vector<int> bfs = bfsOfGraph(V, adj);
  for (int i = 0; i < bfs.size(); i++) {
    cout << bfs[i] << " ";
  }
  return 0;
}