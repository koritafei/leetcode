/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (45.88%)
 * Likes:    2708
 * Dislikes: 299
 * Total Accepted:    289.1K
 * Total Submissions: 629.8K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle array, return the minimum path sum from top to bottom.
 *
 * For each step, you may move to an adjacent number of the row below. More
 * formally, if you are on index i on the current row, you may move to either
 * index i or index i + 1 on the next row.
 *
 *
 * Example 1:
 *
 *
 * Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 * Output: 11
 * Explanation: The triangle looks like:
 * ⁠  2
 * ⁠ 3 4
 * ⁠6 5 7
 * 4 1 8 3
 * The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined
 * above).
 *
 *
 * Example 2:
 *
 *
 * Input: triangle = [[-10]]
 * Output: -10
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= triangle.length <= 200
 * triangle[0].length == 1
 * triangle[i].length == triangle[i - 1].length + 1
 * -10^4 <= triangle[i][j] <= 10^4
 *
 *
 *
 * Follow up: Could you do this using only O(n) extra space, where n is the
 * total number of rows in the triangle?
 */

// @lc code=start
class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int row = triangle.size();
    if (row == 0) {
      return 0;
    }
    int col = triangle[row - 1].size();
    if (col == 0) {
      return 0;
    }
    vector<int> dp(col, -1);

    for (int i = 0; i < col; i++) {
      dp[i] = triangle[row - 1][i];
    }

    for (int i = row - 2; i >= 0; i--) {
      for (int j = 0; j <= i; j++) {
        dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
      }
    }

    return dp[0];
  }
};
// @lc code=end
