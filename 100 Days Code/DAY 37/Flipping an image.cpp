//! Flipping an image (Leetcode 832)

// Question Link:
// https://leetcode.com/problems/flipping-an-image/description/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image) {
  for (int i = 0; i < image.size(); i++) {
    reverse(image[i].begin(), image[i].end());
    for (int j = 0; j < image[i].size(); j++) {
      if (image[i][j] == 1) {
        image[i][j] = 0;
      } else {
        image[i][j] = 1;
      }
    }
  }
  return image;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> image(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> image[i][j];
    }
  }
  vector<vector<int>> result = flipAndInvertImage(image);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}