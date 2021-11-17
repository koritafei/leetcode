/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.50%)
 * Likes:    9781
 * Dislikes: 383
 * Total Accepted:    1.8M
 * Total Submissions: 4.4M
 * Testcase Example:  '"()"'
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 *
 * An input string is valid if:
 *
 *
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: s = "()"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s = "()[]{}"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: s = "(]"
 * Output: false
 *
 *
 * Example 4:
 *
 *
 * Input: s = "([)]"
 * Output: false
 *
 *
 * Example 5:
 *
 *
 * Input: s = "{[]}"
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of parentheses only '()[]{}'.
 *
 *
 */

#include <stack>
#include <string>

// @lc code=start
class Solution {
public:
  bool isValid(std::string s) {
    std::stack<char> st;
    for (auto ch : s) {
      if (ch == '(' || ch == '{' || ch == '[') {
        st.push(ch);
      } else {
        if (st.size() && leftOf(ch) == st.top()) {
          st.pop();
        } else {
          return false;
        }
      }
    }

    return st.empty();
  }

private:
  char leftOf(char ch) {
    if (ch == ')') {
      return '(';
    } else if (ch == '}') {
      return '{';
    } else {
      return '[';
    }
  }
};
// @lc code=end
