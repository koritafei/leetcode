/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (43.35%)
 * Likes:    3573
 * Dislikes: 80
 * Total Accepted:    350.9K
 * Total Submissions: 809.5K
 * Testcase Example:
 '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n'
 + '5'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 *
 *
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 *
 *
 * Example:
 *
 * Consider the following matrix:
 *
 *
 * [
 * ⁠ [1,   4,  7, 11, 15],
 * ⁠ [2,   5,  8, 12, 19],
 * ⁠ [3,   6,  9, 16, 22],
 * ⁠ [10, 13, 14, 17, 24],
 * ⁠ [18, 21, 23, 26, 30]
 * ]
 *
 *
 * Given target = 5, return true.
 *
 * Given target = 20, return false.
 *
 */
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    if (0 == row) {
      return false;
    }
    int col = matrix[0].size();
    if (0 == col) {
      return false;
    }
    int r = row - 1, c = 0;
    while (r >= 0 && c < col) {
      if (matrix[r][c] < target) {
        c++;
      } else if (matrix[r][c] > target) {
        r--;
      } else {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end

int main(int argc, char** argv) {
  Solution            sol;
  vector<vector<int>> m      = {{1, 4, 7, 11, 15},
                           {2, 5, 8, 12, 19},
                           {3, 6, 9, 16, 22},
                           {10, 13, 14, 17, 24},
                           {18, 21, 23, 26, 30}};
  int                 target = 5;
  cout << sol.searchMatrix(m, target) << endl;
}