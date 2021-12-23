/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (53.70%)
 * Likes:    4028
 * Dislikes: 650
 * Total Accepted:    625.6K
 * Total Submissions: 1.2M
 * Testcase Example:
 * '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 *
 *
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9
 * without repetition.
 *
 *
 * Note:
 *
 *
 * A Sudoku board (partially filled) could be valid but is not necessarily
 * solvable.
 * Only the filled cells need to be validated according to the mentioned
 * rules.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: board =
 * [["5","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: board =
 * [["8","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner
 * being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
 * is invalid.
 *
 *
 *
 * Constraints:
 *
 *
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit 1-9 or '.'.
 *
 *
 */

#include <set>
#include <vector>

// @lc code=start
class Solution {
public:
  bool isValidSudoku(std::vector<std::vector<char>>& board) {
    int                         row = board.size(), col = board[0].size();
    std::vector<std::set<char>> rowSet(row);
    std::vector<std::set<char>> colSet(row);
    std::vector<std::set<char>> boardSet(row);

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if ('.' == board[i][j]) {
          continue;
        }

        if (rowSet[i].find(board[i][j]) == rowSet[i].end()) {
          rowSet[i].insert(board[i][j]);
        } else {
          return false;
        }

        if (colSet[j].find(board[i][j]) == colSet[j].end()) {
          colSet[j].insert(board[i][j]);
        } else {
          return false;
        }

        int k = int(i / 3.0) * 3 + int(j / 3.0);
        if (boardSet[k].find(board[i][j]) == boardSet[k].end()) {
          boardSet[k].insert(board[i][j]);
        } else {
          return false;
        }
      }
    }

    return true;
  }
};
// @lc code=end
