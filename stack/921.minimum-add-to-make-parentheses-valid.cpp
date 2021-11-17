/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 *
 * https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/
 *
 * algorithms
 * Medium (76.96%)
 * Likes:    1828
 * Dislikes: 104
 * Total Accepted:    147K
 * Total Submissions: 190.6K
 * Testcase Example:  '"())"'
 *
 * A parentheses string is valid if and only if:
 *
 *
 * It is the empty string,
 * It can be written as AB (A concatenated with B), where A and B are valid
 * strings, or
 * It can be written as (A), where A is a valid string.
 *
 *
 * You are given a parentheses string s. In one move, you can insert a
 * parenthesis at any position of the string.
 *
 *
 * For example, if s = "()))", you can insert an opening parenthesis to be
 * "(()))" or a closing parenthesis to be "())))".
 *
 *
 * Return the minimum number of moves required to make s valid.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "())"
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: s = "((("
 * Output: 3
 *
 *
 * Example 3:
 *
 *
 * Input: s = "()"
 * Output: 0
 *
 *
 * Example 4:
 *
 *
 * Input: s = "()))(("
 * Output: 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s[i] is either '(' or ')'.
 *
 *
 */

#include <string>

// @lc code=start
class Solution {
public:
  int minAddToMakeValid(std::string s) {
    int res = 0, need = 0;
    for (auto ch : s) {
      if (ch == '(') {
        need++;  // 需要一个右括号
      }
      if (ch == ')') {
        need--;  // 减少一个有括号需求
        if (need == -1) {
          need = 0;
          res++;
        }
      }
    }
    return res + need;
  }
};
// @lc code=end
