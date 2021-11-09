/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (56.37%)
 * Likes:    6150
 * Dislikes: 243
 * Total Accepted:    429.3K
 * Total Submissions: 751.7K
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

#include <vector>

// @lc code=start
class Solution {
public:
  int numTrees(int n) {
    memo = std::vector<std::vector<int>>(n + 1, std::vector<int>(n + 1, 0));

    numTrees(1, n);

    return memo[1][n];
  }

private:
  int numTrees(int lo, int hi) {
    if (lo > hi) {
      return 1;
    }

    if (memo[lo][hi] != 0) {
      return memo[lo][hi];
    }

    int sum = 0;
    for (int i = lo; i <= hi; i++) {
      int left  = numTrees(lo, i - 1);
      int right = numTrees(i + 1, hi);
      sum += left * right;
    }

    memo[lo][hi] = sum;

    return memo[lo][hi];
  }

  std::vector<std::vector<int>> memo;
};
// @lc code=end
