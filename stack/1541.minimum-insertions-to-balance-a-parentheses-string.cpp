/*
 * @lc app=leetcode id=1541 lang=cpp
 *
 * [1541] Minimum Insertions to Balance a Parentheses String
 *
 * https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/description/
 *
 * algorithms
 * Medium (47.65%)
 * Likes:    515
 * Dislikes: 105
 * Total Accepted:    21.7K
 * Total Submissions: 45.6K
 * Testcase Example:  '"(()))"'
 *
 * Given a parentheses string s containing only the characters '(' and ')'. A
 * parentheses string is balanced if:
 *
 *
 * Any left parenthesis '(' must have a corresponding two consecutive right
 * parenthesis '))'.
 * Left parenthesis '(' must go before the corresponding two consecutive right
 * parenthesis '))'.
 *
 *
 * In other words, we treat '(' as openning parenthesis and '))' as closing
 * parenthesis.
 *
 * For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))"
 * and "(()))" are not balanced.
 *
 * You can insert the characters '(' and ')' at any position of the string to
 * balance it if needed.
 *
 * Return the minimum number of insertions needed to make s balanced.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "(()))"
 * Output: 1
 * Explanation: The second '(' has two matching '))', but the first '(' has
 * only ')' matching. We need to to add one more ')' at the end of the string
 * to be "(())))" which is balanced.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "())"
 * Output: 0
 * Explanation: The string is already balanced.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "))())("
 * Output: 3
 * Explanation: Add '(' to match the first '))', Add '))' to match the last
 * '('.
 *
 *
 * Example 4:
 *
 *
 * Input: s = "(((((("
 * Output: 12
 * Explanation: Add 12 ')' to balance the string.
 *
 *
 * Example 5:
 *
 *
 * Input: s = ")))))))"
 * Output: 5
 * Explanation: Add 4 '(' at the beginning of the string and one ')' at the
 * end. The string becomes "(((())))))))".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists of '(' and ')' only.
 *
 *
 */

#include <string>

// @lc code=start
class Solution {
public:
  int minInsertions(std::string s) {
    int len  = s.size();
    int need = 0;
    int res  = 0;

    for (int i = 0; i < len; i++) {
      if (s[i] == '(') {
        need += 2;
        if (need % 2 ==
            1) {  // 对右括号需求为偶数，当为奇数时，需要增加一个结果
          res++;
          need--;
        }
      } else {
        need--;
        if (need == -1) {
          res++;
          need = 1;
        }
      }
    }

    return res + need;
  }
};
// @lc code=end
