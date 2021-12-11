/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 *
 * https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/
 *
 * algorithms
 * Medium (77.40%)
 * Likes:    1891
 * Dislikes: 105
 * Total Accepted:    154.5K
 * Total Submissions: 199.5K
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
    int need = 0;
    int res  = 0;

    int len = s.size();

    for (int i = 0; i < len; i++) {
      if (s[i] == '(') {
        need++;
      } else {
        need--;
        if (-1 == need) {
          res++;
          need = 0;
        }
      }
    }

    return need + res;
  }
};
// @lc code=end
