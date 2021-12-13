/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (68.60%)
 * Likes:    10729
 * Dislikes: 420
 * Total Accepted:    919.7K
 * Total Submissions: 1.3M
 * Testcase Example:  '3'
 *
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 *
 * Example 1:
 * Input: n = 3
 * Output: ["((()))","(()())","(())()","()(())","()()()"]
 * Example 2:
 * Input: n = 1
 * Output: ["()"]
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 8
 *
 *
 */

#include <string>
#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> res;
    std::string              path;
    if (n == 0) {
      return res;
    }
    backtrace(n, n, path, res);

    return res;
  }

private:
  void backtrace(int                       left,
                 int                       right,
                 std::string              &path,
                 std::vector<std::string> &res) {
    if (left > right) {
      return;
    }

    if (left < 0 || right < 0) {
      return;
    }

    if (left == 0 && right == 0) {
      res.push_back(path);
      return;
    }

    // 做选择
    path.push_back('(');
    backtrace(left - 1, right, path, res);
    // 撤销选择
    path.pop_back();

    // 做选择
    path.push_back(')');
    backtrace(left, right - 1, path, res);
    path.pop_back();
  }
};
// @lc code=end
