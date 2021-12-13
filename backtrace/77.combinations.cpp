/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (61.54%)
 * Likes:    3303
 * Dislikes: 111
 * Total Accepted:    447.1K
 * Total Submissions: 724.9K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of the range [1, n].
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

#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<std::vector<int>> combine(int n, int k) {
    backtrace(n, k, 1);
    return res;
  }

private:
  void backtrace(int n, int k, int index) {
    if (path.size() == k) {
      res.push_back(path);
      return;
    }

    for (int i = index; i <= n; i++) {
      // 做选择
      path.push_back(i);
      backtrace(n, k, i + 1);
      path.pop_back();
    }
  }

  std::vector<int>              path;
  std::vector<std::vector<int>> res;
};
// @lc code=end
