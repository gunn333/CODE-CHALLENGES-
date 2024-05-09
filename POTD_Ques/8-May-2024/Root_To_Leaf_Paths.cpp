//! Root to Leaf Paths (GeeksforGeeks)

// Question Link:
// https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

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

vector<vector<int>> Paths(Node *root) {
  // This vector pair will store the paths from root to leaf
  vector<vector<int>> a;
  vector<int> ans;
  solve(root, a, ans);
  return a;
}
void solve(Node *root, vector<vector<int>> &a, vector<int> &ans) {
  if (root == NULL) {
    return;
  }
  ans.push_back(root->data);
  if (root->left == NULL and root->right == NULL) {
    a.push_back(ans);
  }
  solve(root->left, a, ans);
  solve(root->right, a, ans);
  ans.pop_back();
}

int main() {
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  vector<vector<int>> res = Paths(root);
  for (auto x : res) {
    for (auto y : x) {
      cout << y << " ";
    }
    cout << endl;
  }
  return 0;
}