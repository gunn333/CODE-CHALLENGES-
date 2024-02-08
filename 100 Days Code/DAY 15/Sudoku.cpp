//! Valid Sudoku LeetCode - 36

// Question Link:
// https://leetcode.com/problems/valid-sudoku/

//! Sudoku

/*
RULES:
1. 9x9 grid
2. 1-9 numbers honge 9x9 grid me
3. it has 3x3 subgrids
4. i need to place these numbers in such a way these numbers should not repeat
in any row, column or subgrid
5. It is like N queen problem

mujhe sare solutions tak nahi jana , mujhe ek solution chahiye

APPROACH:
1. main ek ek krke cell ko bhadate jaungi jabtak main last column tak nahi
pahuchti
2. now change the row
3. Har cell mein mujhe jake check krna hai ki kya for i = 1 to 9, kya main yaha
place kr skti hu
4. Place krne ke liye mujhe check krna hoga ki kya yeh row, column and subgrid
mein same digit exist toh nahi krta
*/

#include <iostream>
#include <vector>
using namespace std;
bool isValidSudoku(vector<vector<char>> &board) {
  int row[9][9] = {0};
  int col[9][9] = {0};
  int subgrid[3][3][9] = {0};
  //   Traverse the board
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      // Agar cell me koi digit hai toh
      if (board[i][j] != '.') {
        // us cell ke string digit ko int me convert krdiya
        int num = board[i][j] - '1';
        /*
        agar row, column or subgrid me yeh digit already exist krta hai toh
        row[i][num] means ith row me num exist krta hai
        col[j][num] means jth column me num exist krta hai
        subgrid[i/3][j/3][num] means i/3th row and j/3th column me num exist
        And if any of these is true then return false because then digit will be
        repeated
        */
        if (row[i][num] || col[j][num] || subgrid[i / 3][j / 3][num]) {
          return false;
        }
        // Agar nahi exist krta toh usko mark krdo exist krne ke liye
        row[i][num] = 1;
        col[j][num] = 1;
        subgrid[i / 3][j / 3][num] = 1;
      }
    }
  }
  return true;
}
int main() {
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  cout << isValidSudoku(board);
  return 0;
}
