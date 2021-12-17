/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (61.15%)
 * Likes:    4265
 * Dislikes: 179
 * Total Accepted:    650.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '5'
 *
 * Given an integer numRows, return the first numRows of Pascal's triangle.
 *
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it as shown:
 *
 *
 * Example 1:
 * Input: numRows = 5
 * Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 * Example 2:
 * Input: numRows = 1
 * Output: [[1]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= numRows <= 30
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> ans;

    for (size_t i = 0; i < numRows; i++) {
      std::vector<int> rowvec(i + 1, 1);
      if (i == 0 || i == 1) {
        ans.push_back(rowvec);
        continue;
      }

      for (size_t j = 1; j < i; j++) {
        rowvec[j] = ans[i - 1][j - 1] + ans[i - 1][j];
      }

      ans.push_back(rowvec);
    }

    return ans;
  }
};
// @lc code=end
