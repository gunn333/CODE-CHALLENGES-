class Solution {
		boolean[][] visited;

		public boolean exist(char[][] board, String word) {
			int rows = board.length;
			if ((rows == 0) || (word.length() == 0)) {
				return false;
			}
			int cols = board[0].length;
			visited = new boolean[rows][cols];
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					if ((board[i][j] == word.charAt(0))) {
						if (searchByDFS(board, i, j, word, 0)) {
							return true;
						}
					}
				}
			}
			return false;
		}

		private boolean searchByDFS(char[][] board, int i, int j, String word, int curr) {
			if (curr == word.length()) {
				return true;  // if recursion has reached to the point that we have traversed the whole string, then simply return true as the string is found on the board.
			}
			if ((i < 0) || (j < 0) || (i >= board.length) || (j >= board[0].length) || visited[i][j]
					|| (board[i][j] != word.charAt(curr))) {
				return false;
			}
			visited[i][j] = true;
			boolean result = searchByDFS(board, i + 1, j, word, curr + 1)
					|| searchByDFS(board, i - 1, j, word, curr + 1) || searchByDFS(board, i, j + 1, word, curr + 1)
					|| searchByDFS(board, i, j - 1, word, curr + 1);
			visited[i][j] = false;  // done to erase the writing on visited graph so that it might be used in other places
			return result;
		}
	}
