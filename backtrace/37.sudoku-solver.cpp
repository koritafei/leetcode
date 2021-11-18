/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (51.49%)
 * Likes:    4005
 * Dislikes: 128
 * Total Accepted:    300.2K
 * Total Submissions: 581.1K
 * Testcase Example:
 * '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * A sudoku solution must satisfy all of the following rules:
 *
 *
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 *
 *
 * The '.' character indicates empty cells.
 *
 *
 * Example 1:
 *
 *
 * Input: board =
 * [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
 * Output:
 * [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
 * Explanation: The input board is shown above and the only valid solution is
 * shown below:
 *
 *
 *
 *
 *
 * Constraints:
 *
 *
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit or '.'.
 * It is guaranteed that the input board has only one solution.
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  void solveSudoku(std::vector<std::vector<char>>& board) {
    int row = board.size(), col = 0;
    if (0 == row) {
      return;
    } else {
      col = board[0].size();
    }

    if (row != col) {
      return;
    }

    backtrace(board, row, col, 0, 0);
  }

private:
  bool backtrace(std::vector<std::vector<char>>& board,
                 int                             row,
                 int                             col,
                 int                             x,
                 int                             y) {
    if (y == col) {
      // 计算到最后一列，计算下一行
      return backtrace(board, row, col, x + 1, 0);
    }

    // 计算到最后一行，得到一个结果
    if (x == row) {
      return true;
    }

    // 对每个位置进行穷举
    for (int i = x; i < row; i++) {
      for (int j = y; j < col; j++) {
        if ('.' != board[i][j]) {
          // 如果有预设数字，遍历下一列
          return backtrace(board, row, col, i, j + 1);
        }

        // 非预设数字
        for (char ch = '1'; ch <= '9'; ch++) {
          // 当前选中解无效，继续
          if (!isValid(board, row, col, i, j, ch)) {
            continue;
          }

          // 做选择
          board[i][j] = ch;
          if (backtrace(board, row, col, i, j + 1)) {  // 找到可行解，返回
            return true;
          }

          // 撤销选择
          board[i][j] = '.';
        }

        return false;  // 穷举完所有选择，则直接放回
      }
    }

    return false;  // 没有可行解
  }

  // 判断所填数字是否合法
  bool isValid(std::vector<std::vector<char>>& board,
               int                             row,
               int                             col,
               int                             x,
               int                             y,
               char                            ch) {
    for (int i = 0; i < row; i++) {
      // 同一行是否有相同字符
      if (ch == board[x][i]) {
        return false;
      }
      // 同一列是否有相同字符
      if (ch == board[i][y]) {
        return false;
      }

      // 临近3*3的方格是否有相同字符
      if (ch == board[(x / 3) * 3 + i / 3][(y / 3) * 3 + i % 3]) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
