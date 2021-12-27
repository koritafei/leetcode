/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (57.45%)
 * Likes:    6394
 * Dislikes: 253
 * Total Accepted:    442K
 * Total Submissions: 769.2K
 * Testcase Example:  '3'
 *
 * Given an integer n, return the number of structurally unique BST's (binary
 * search trees) which has exactly n nodes of unique values from 1 to n.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3
 * Output: 5
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 19
 *
 *
 */

// @lc code=start
#include <vector>
class Solution {
public:
  int numTrees(int n) {
    std::vector<std::vector<int>> memo(n + 1, std::vector<int>(n + 1, -1));

    return numTrees(1, n, memo);
  }

private:
  int numTrees(int start, int end, std::vector<std::vector<int>> &memo) {
    if (start >= end) {
      return 1;
    }
    if (memo[start][end] != -1) {
      return memo[start][end];
    }

    int res = 0;
    for (int i = start; i <= end; i++) {
      int left  = numTrees(start, i - 1, memo);
      int right = numTrees(i + 1, end, memo);
      res += left * right;
    }

    memo[start][end] = res;

    return res;
  }
};
// @lc code=end
