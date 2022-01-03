/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (54.98%)
 * Likes:    4582
 * Dislikes: 136
 * Total Accepted:    319.8K
 * Total Submissions: 580.5K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n x n
 * chessboard such that no two queens attack each other.
 *
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * You may return the answer in any order.
 *
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space,
 * respectively.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4
 * Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: [["Q"]]
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
  std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::string> board(n, std::string(n, '.'));
    backtrace(board, n, 0);

    return res;
  }

private:
  void backtrace(std::vector<std::string> &board, int row, int x) {
    if (x == row) {
      res.push_back(board);
      return;
    }

    for (int i = 0; i < row; i++) {
      if (!isValid(board, row, x, i)) {
        continue;
      }

      board[x][i] = 'Q';
      backtrace(board, row, x + 1);
      board[x][i] = '.';
    }
  }

  bool isValid(std::vector<std::string> &board, int row, int x, int y) {
    for (int i = 0; i < row; i++) {
      // 同一行
      if ('Q' == board[x][i]) {
        return false;
      }

      // 同一列
      if ('Q' == board[i][y]) {
        return false;
      }
    }

    // 左上角
    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
      if ('Q' == board[i][j]) {
        return false;
      }
    }

    // 右上角
    for (int i = x - 1, j = y + 1; i >= 0 && j < row; i--, j++) {
      if ('Q' == board[i][j]) {
        return false;
      }
    }

    return true;
  }

  std::vector<std::vector<std::string>> res;
};
// @lc code=end
