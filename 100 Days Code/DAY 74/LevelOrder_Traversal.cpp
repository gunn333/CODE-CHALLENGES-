//! Level Order Traversal (LeetCode 102)

// Question Link:
// https://leetcode.com/problems/binary-tree-level-order-traversal/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode *root) {
  if (root == NULL) {
    return {};
  }
  vector<vector<int>> result;
  queue<TreeNode *> q;
  q.push(root);
  // Push a nullptr to mark the end of the first level
  q.push(NULL);

  // Continue until the queue has only the nullptr left
  while (q.size() > 1) {
    // levelNodes will store the nodes of the current level
    vector<int> levelNodes;

    /* q.front() will be nullptr if the current level has been traversed
       completely Continue until the current level has been traversed completely
       */
    while (q.front() != NULL) {
      TreeNode *front = q.front();
      // Remove the front node from the queue because it has been visited now
      // and push its children
      q.pop();

      // Push the value of the current node to levelNodes
      levelNodes.push_back(front->val);

      if (front->left != NULL) {
        q.push(front->left);
      }

      if (front->right != NULL) {
        q.push(front->right);
      }
    }

    // Push the nodes of the current level to the result
    result.push_back(levelNodes);

    // After the current level has been traversed completely, remove the nullptr
    // from the queue and push a nullptr to mark the end of the next level
    q.pop();
    q.push(nullptr);
  }
  
  return result;
}

int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  vector<vector<int>> result = levelOrder(root);

  for (auto level : result) {
    for (int node : level) {
      cout << node << " ";
    }
    cout << endl;
  }

  return 0;
}