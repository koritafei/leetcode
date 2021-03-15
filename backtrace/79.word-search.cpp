/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (36.93%)
 * Likes:    5332
 * Dislikes: 235
 * Total Accepted:    625.8K
 * Total Submissions: 1.7M
 * Testcase Example:
 * '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given an m x n grid of characters board and a string word, return true if
 * word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once.
 *
 * Note: There will be some test cases with a board or a word larger than
 * constraints to test if your solution is using pruning.
 *
 *
 * Example 1:
 *
 *
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCCED"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "SEE"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCB"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * m == board.length
 * n = board[i].length
 * 1 <= m, n <= 6
 * 1 <= word.length <= 15
 * board and word consists of only lowercase and uppercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
public:
  bool exist(vector<vector<char>>& board, string word) {
    int row = board.size();
    if (row == 0) {
      return false;
    }
    int col = board[0].size();
    if (col == 0) {
      return false;
    }

    visited = vector<vector<bool>>(row, vector<bool>(col, false));

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (searchBoard(board, word, 0, i, j)) {
          return true;
        }
      }
    }

    return false;
  }

private:
  bool searchBoard(vector<vector<char>>& board, string word, int index,
                   int startx, int starty) {
    if (index == word.size() - 1) {
      return board[startx][starty] == word[index];
    }

    if (board[startx][starty] == word[index]) {
      visited[startx][starty] = true;

      for (int i = 0; i < 4; i++) {
        int newx = startx + step[i][0];
        int newy = starty + step[i][1];
        if (isInEdge(newx, newy, board.size(), board[0].size()) &&
            !visited[newx][newy] &&
            searchBoard(board, word, index + 1, newx, newy)) {
          return true;
        }
      }
      visited[startx][starty] = false;
    }
    return false;
  }

  bool isInEdge(int x, int y, int row, int col) {
    return x >= 0 && x < row && y >= 0 && y < col;
  }

  vector<vector<int>>  step = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
  vector<vector<bool>> visited;
};
// @lc code=end
