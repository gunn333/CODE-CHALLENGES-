//! Maximum Depth of N-ary Tree (LeetCode 559)

// Question Link:
// https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int val;
  vector<Node *> children;
  Node() {}
  Node(int _val) { val = _val; }
  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

int maxDepth(Node *root) {
  if (!root) {
    return NULL;
  }

  queue<Node *> q;
  q.push(root);
  q.push(NULL);

  int depth = 0;

  while (!q.empty()) {
    Node *temp = q.front();
    q.pop();

    if (!temp) {
      depth++;
      if (q.empty()) {
        break;
      } else {
        q.push(NULL);
      }
    } else {
      for (int i = 0; i < temp->children.size(); i++) {
        if (temp->children[i]) {
          q.push(temp->children[i]);
        }
      }
    }
  }
  return depth;
}

int main() {
  Node *root = new Node(1);
  root->children.push_back(new Node(3));
  root->children.push_back(new Node(2));
  root->children.push_back(new Node(4));
  root->children[0]->children.push_back(new Node(5));
  root->children[0]->children.push_back(new Node(6));

  cout << maxDepth(root) << endl;
  return 0;
}