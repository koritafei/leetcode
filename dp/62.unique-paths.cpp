/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 *
 * https://leetcode.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (56.11%)
 * Likes:    4716
 * Dislikes: 240
 * Total Accepted:    610K
 * Total Submissions: 1.1M
 * Testcase Example:  '3\n7'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 *
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 *
 * How many possible unique paths are there?
 *
 *
 * Example 1:
 *
 *
 * Input: m = 3, n = 7
 * Output: 28
 *
 *
 * Example 2:
 *
 *
 * Input: m = 3, n = 2
 * Output: 3
 * Explanation:
 * From the top-left corner, there are a total of 3 ways to reach the
 * bottom-right corner:
 * 1. Right -> Down -> Down
 * 2. Down -> Down -> Right
 * 3. Down -> Right -> Down
 *
 *
 * Example 3:
 *
 *
 * Input: m = 7, n = 3
 * Output: 28
 *
 *
 * Example 4:
 *
 *
 * Input: m = 3, n = 3
 * Output: 6
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= m, n <= 100
 * It's guaranteed that the answer will be less than or equal to 2 * 10^9.
 *
 *
 */

// @lc code=start
class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> res(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= n; i++) {
      res[1][i] = 1;
    }

    for (int i = 0; i <= m; i++) {
      res[i][1] = 1;
    }

    for (int i = 2; i <= m; i++) {
      for (int j = 2; j <= n; j++) {
        res[i][j] = res[i - 1][j] + res[i][j - 1];
      }
    }

    return res[m][n];
  }
};
// @lc code=end
