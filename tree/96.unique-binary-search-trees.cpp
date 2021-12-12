/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (57.36%)
 * Likes:    6317
 * Dislikes: 247
 * Total Accepted:    438.7K
 * Total Submissions: 764.5K
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
    if (n == 0) {
      return 0;
    }

    memo = std::vector<std::vector<int>>(n + 1, std::vector<int>(n + 1, 0));

    return buildTree(1, n);
  }

private:
  int buildTree(int left, int right) {
    if (left > right) {
      return 1;
    }

    if (memo[left][right] != 0) {
      return memo[left][right];
    }

    int res = 0;
    for (int i = left; i <= right; i++) {
      int leftc  = buildTree(left, i - 1);
      int rightc = buildTree(i + 1, right);
      res += leftc * rightc;
    }

    memo[left][right] = res;

    return memo[left][right];
  }

private:
  std::vector<std::vector<int>> memo;
};
// @lc code=end
