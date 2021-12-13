/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (64.56%)
 * Likes:    1382
 * Dislikes: 203
 * Total Accepted:    199.2K
 * Total Submissions: 308.1K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 *
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 9
 *
 *
 */

#include <string>
#include <vector>

// @lc code=start
class Solution {
public:
  int totalNQueens(int n) {
    res = 0;
    std::vector<std::string> board(n, std::string(n, '.'));
    backtrace(board, n, 0);
    return res;
  }

private:
  void backtrace(std::vector<std::string> &board, int n, int row) {
    if (row == n) {
      res++;
      return;
    }

    for (int i = 0; i < n; i++) {
      if (!isValid(board, n, row, i)) {
        continue;
      }

      board[row][i] = 'Q';
      backtrace(board, n, row + 1);
      board[row][i] = '.';
    }
  }

  bool isValid(std::vector<std::string> &board, int n, int row, int col) {
    for (int i = 0; i < n; i++) {
      if (board[i][col] == 'Q') {
        return false;
      }

      for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
          return false;
        }
      }

      for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if ('Q' == board[i][j]) {
          return false;
        }
      }
    }

    return true;
  }

  int res;
};
// @lc code=end
