/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (61.08%)
 * Likes:    3203
 * Dislikes: 109
 * Total Accepted:    437.1K
 * Total Submissions: 712.9K
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
    if (subset.size() == k) {
      // 满足条件加入结果集
      res.push_back(subset);
      return;
    }

    for (int i = index; i <= n; i++) {
      // 做选择
      subset.push_back(i);
      backtrace(n, k, i + 1);
      // 撤销选择
      subset.pop_back();
    }
  }

  std::vector<int>              subset;  // 遍历路径
  std::vector<std::vector<int>> res;     // 结果集
};
// @lc code=end
