/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (30.80%)
 * Likes:    6632
 * Dislikes: 233
 * Total Accepted:    436.3K
 * Total Submissions: 1.4M
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()".
 *
 *
 * Example 2:
 *
 *
 * Input: s = ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()".
 *
 *
 * Example 3:
 *
 *
 * Input: s = ""
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 3 * 10^4
 * s[i] is '(', or ')'.
 *
 *
 */

#include <stack>
#include <string>
#include <vector>

// @lc code=start
class Solution {
public:
  int longestValidParentheses(std::string s) {
    std::stack<int> stack;
    int             len    = s.size();
    int             maxlen = 0;

    std::vector<int> dp =
        std::vector<int>(len + 1, 0);  // 记录leftindex开始的最大合法字符串长度

    for (int i = 0; i < len; i++) {
      if (s[i] == '(') {
        stack.push(i);
        dp[i + 1] = 0;  // 左括号必不合法
      } else {
        if (!stack.empty()) {
          int leftindex = stack.top();
          stack.pop();
          int currlen = 1 + i - leftindex;
          dp[i + 1]   = currlen + dp[leftindex];
        } else {
          dp[i + 1] = 0;  // 没有匹配
        }
      }
    }

    for (int i = 0; i <= len; i++) {
      maxlen = maxlen > dp[i] ? maxlen : dp[i];
    }

    return maxlen;
  }
};
// @lc code=end
