/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 *
 * https://leetcode.com/problems/minimum-falling-path-sum/description/
 *
 * algorithms
 * Medium (65.88%)
 * Likes:    1706
 * Dislikes: 88
 * Total Accepted:    94.8K
 * Total Submissions: 143.8K
 * Testcase Example:  '[[2,1,3],[6,5,4],[7,8,9]]'
 *
 * Given an n x n array of integers matrix, return the minimum sum of any
 * falling path through matrix.
 *
 * A falling path starts at any element in the first row and chooses the
 * element in the next row that is either directly below or diagonally
 * left/right. Specifically, the next element from position (row, col) will be
 * (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
 * Output: 13
 * Explanation: There are two falling paths with a minimum sum as shown.
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[-19,57],[-40,-5]]
 * Output: -59
 * Explanation: The falling path with a minimum sum is shown.
 *
 *
 *
 * Constraints:
 *
 *
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 100
 * -100 <= matrix[i][j] <= 100
 *
 *
 */

#include <climits>
#include <vector>

// @lc code=start
class Solution {
public:
  int minFallingPathSum(std::vector<std::vector<int>>& matrix) {
    int row = matrix.size(), col = 0;
    if (row != 0) {
      col = matrix[0].size();
    } else {
      return 0;
    }

    std::vector<std::vector<int>> memo =
        std::vector<std::vector<int>>(row + 1, std::vector<int>(col, 0));
    // base case
    for (int i = 0; i < col; i++) {
      memo[0][i] = matrix[0][i];
    }

    // dp 数组计算
    for (int i = 1; i < row; i++) {
      for (int j = 0; j < col; j++) {
        int min    = getMin(i, j, row, col, memo);
        memo[i][j] = min + matrix[i][j];
      }
    }

    // 查找最小值，在最后一行
    int res = INT_MAX;
    for (int i = 0; i < col; i++) {
      res = res < memo[row - 1][i] ? res : memo[row - 1][i];
    }

    return res;
  }

private:
  int getMin(int                            i,
             int                            j,
             int                            row,
             int                            col,
             std::vector<std::vector<int>>& memo) {
    int a = INT_MAX, b = INT_MAX, c = INT_MAX;
    if (isInArea(i - 1, j - 1, row, col)) {
      a = memo[i - 1][j - 1];
    }

    if (isInArea(i - 1, j, row, col)) {
      b = memo[i - 1][j];
    }

    if (isInArea(i - 1, j + 1, row, col)) {
      c = memo[i - 1][j + 1];
    }

    return std::min(std::min(a, b), c);
  }

  bool isInArea(int i, int j, int row, int col) {
    return i >= 0 && i < row && j >= 0 && j < col;
  }
};
// @lc code=end
