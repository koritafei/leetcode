/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (68.34%)
 * Likes:    10452
 * Dislikes: 412
 * Total Accepted:    901.2K
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
    int                      left  = n;
    int                      right = n;
    std::string              str;
    std::vector<std::string> res;  // 结果集

    backtrace(left, right, str, res);
    return res;
  }

private:
  void backtrace(int                       left,
                 int                       right,
                 std::string &             str,
                 std::vector<std::string> &res) {
    if (right < left) {
      return;
    }
    if (right < 0 || left < 0) {
      return;
    }

    if (right == 0 && left == 0) {
      res.push_back(str);
      return;
    }

    // 放入左括号
    str.push_back('(');
    backtrace(left - 1, right, str, res);
    // 撤销选择
    str.pop_back();

    // 放入右括号
    str.push_back(')');
    backtrace(left, right - 1, str, res);
    str.pop_back();
  }
};
// @lc code=end
