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
  void backtrace(std::vector<std::string> &board, int n, int row) {
    if (row == n) {
      res.push_back(board);  // 存在一个结果
      return;
    }

    for (int i = 0; i < n; i++) {
      if (!isValid(board, n, row, i)) {
        continue;
      }

      // 做选择
      board[row][i] = 'Q';

      backtrace(board, n, row + 1);
      // 撤销选择
      board[row][i] = '.';
    }
  }

  bool isValid(std::vector<std::string> &board, int n, int row, int col) {
    for (int i = 0; i < n; i++) {
      // 同一行是否存在Q
      if ('Q' == board[row][i]) {
        return false;
      }

      // 同一列是否存在Q
      if ('Q' == board[i][col]) {
        return false;
      }
    }

    // 左上角
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
      if ('Q' == board[i][j]) {
        return false;
      }
    }

    // 右上角
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
      if ('Q' == board[i][j]) {
        return false;
      }
    }

    return true;
  }

  std::vector<std::vector<std::string>> res;
};
// @lc code=end
