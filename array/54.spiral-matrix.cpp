/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (39.63%)
 * Likes:    5634
 * Dislikes: 745
 * Total Accepted:    626.7K
 * Total Submissions: 1.6M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,2,3,6,9,8,7,4,5]
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 *
 *
 *
 * Constraints:
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 10
 * -100 <= matrix[i][j] <= 100
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    std::vector<int> ans;

    int row = matrix.size(), col = matrix[0].size();
    int beginx = 0;  // 标记最左侧列的列号，也表示第一行开始
    int endx = col - 1;  // 标记最右侧列的列号，也表示第一行结束，
    int beginy = 0;        // 标记最上面一行的行号
    int endy   = row - 1;  // 标记最下面一行的行号

    while (true) {
      // 遍历第一行
      for (int i = beginx; i <= endx; i++) {
        ans.push_back(matrix[beginy][i]);
      }
      beginy++;  // 下一行
      if (beginy > endy) {
        break;
      }

      // 遍历最后一列
      for (int i = beginy; i <= endy; i++) {
        ans.push_back(matrix[i][endx]);
      }
      endx--;
      if (beginx > endx) {
        break;
      }

      // 最后一行
      for (int i = endx; i >= beginx; i--) {
        ans.push_back(matrix[endy][i]);
      }
      endy--;
      if (beginy > endy) {
        break;
      }

      // 第一列
      for (int i = endy; i >= beginy; i--) {
        ans.push_back(matrix[i][beginx]);
      }
      beginx++;
      if (beginx > endx) {
        break;
      }
    }

    return ans;
  }
};
// @lc code=end
