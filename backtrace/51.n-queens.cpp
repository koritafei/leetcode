/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (54.59%)
 * Likes:    4425
 * Dislikes: 134
 * Total Accepted:    314.5K
 * Total Submissions: 574.1K
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
    track = std::vector<std::string>(n, std::string(n, '.'));
    backtrace(n, n, 0);
    return res;
  }

private:
  void backtrace(int row, int col, int x) {
    if (x == row) {
      // 计算到最后一行，得到一个结果
      res.push_back(track);
      return;
    }

    for (int i = 0; i < col; i++) {
      if (!isValid(track, row, col, x, i)) {
        continue;
      }

      // 做选择
      track[x][i] = 'Q';
      backtrace(row, col, x + 1);  // 下一行
      // 撤销选择
      track[x][i] = '.';
    }
  }

  bool isValid(std::vector<std::string> &board,
               int                       row,
               int                       col,
               int                       x,
               int                       y) {
    for (int i = 0; i < row; i++) {
      // 同一列
      if ('Q' == board[i][y]) {
        return false;
      }
    }

    // 左上方
    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
      if ('Q' == board[i][j]) {
        return false;
      }
    }

    // 右上方
    for (int i = x - 1, j = y + 1; i >= 0 && j < col; i--, j++) {
      if ('Q' == board[i][j]) {
        return false;
      }
    }
    return true;
  }

  std::vector<std::vector<std::string>> res;    // 结果集
  std::vector<std::string>              track;  // 当前结果集
};
// @lc code=end
