/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (57.62%)
 * Likes:    2086
 * Dislikes: 80
 * Total Accepted:    350.7K
 * Total Submissions: 608.2K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 *
 * You may return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1, k = 1
 * Output: [[1]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 20
 * 1 <= k <= n
 *
 *
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    combine(n, k, 1);
    return res;
  }

private:
  void combine(int n, int k, int start) {
    if (path.size() == k) {
      res.push_back(path);
      return;
    }

    for (int i = start; i <= n; i++) {
      path.push_back(i);
      combine(n, k, i + 1);
      path.pop_back();
    }
  }

  vector<vector<int>> res;
  vector<int>         path;
};
// @lc code=end
