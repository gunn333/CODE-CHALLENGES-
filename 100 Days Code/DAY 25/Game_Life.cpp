//! Game of Life (LeetCode 289)

// Question Link:
// https://leetcode.com/problems/game-of-life/

#include <bits/stdc++.h>
using namespace std;
int neighbor(vector<vector<int>> &board, int r, int c) {
  if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() ||
      board[r][c] == 0) {
    return 0;
  } else {
    return 1;
  }
}

void gameOfLife(vector<vector<int>> &board) {

  int rows = board.size();
  int cols = board[0].size();

  vector<vector<int>> tempBoard = board;

  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {

      int liveNeighbors =
          neighbor(board, r - 1, c - 1) + neighbor(board, r - 1, c) +
          neighbor(board, r - 1, c + 1) + neighbor(board, r, c + 1) +
          neighbor(board, r + 1, c + 1) + neighbor(board, r + 1, c) +
          neighbor(board, r + 1, c - 1) + neighbor(board, r, c - 1);

      if (board[r][c] == 1) {
        tempBoard[r][c] = (liveNeighbors < 2 || liveNeighbors > 3) ? 0 : 1;
      } else {
        tempBoard[r][c] = (liveNeighbors == 3) ? 1 : 0;
      }
    }
  }

  board = tempBoard;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> board(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> board[i][j];
  gameOfLife(board);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cout << board[i][j] << " ";
    cout << endl;
  }
  return 0;
}