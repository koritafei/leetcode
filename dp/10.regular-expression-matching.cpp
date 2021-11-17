/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (28.00%)
 * Likes:    7023
 * Dislikes: 960
 * Total Accepted:    608.7K
 * Total Submissions: 2.2M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string s and a pattern p, implement regular expression
 * matching with support for '.' and '*' where:
 *
 *
 * '.' Matches any single character.​​​​
 * '*' Matches zero or more of the preceding element.
 *
 *
 * The matching should cover the entire input string (not partial).
 *
 *
 * Example 1:
 *
 *
 * Input: s = "aa", p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "aa", p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 *
 *
 * Example 3:
 *
 *
 * Input: s = "ab", p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 *
 *
 * Example 4:
 *
 *
 * Input: s = "aab", p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore,
 * it matches "aab".
 *
 *
 * Example 5:
 *
 *
 * Input: s = "mississippi", p = "mis*is*p*."
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 20
 * 1 <= p.length <= 30
 * s contains only lowercase English letters.
 * p contains only lowercase English letters, '.', and '*'.
 * It is guaranteed for each appearance of the character '*', there will be a
 * previous valid character to match.
 *
 *
 */

#include <map>
#include <string>

// @lc code=start
class Solution {
public:
  bool isMatch(std::string s, std::string p) {
    return dp(s, 0, p, 0);
  }

private:
  bool dp(std::string s, int i, std::string t, int j) {
    int m = s.size();
    int n = t.size();

    if (j >= n) {  // p走完，计算s是否已经遍历完成
      return i == m;
    }

    if (i >= m) {
      // s遍历完成，需要判断p余下部分是否能够匹配空串，如果能够匹配空串余下长度一定为2的倍数
      if (1 == (n - j) % 2) {
        return false;
      }

      // 判断余下部分是否能够匹配空串
      for (; j < n - 1; j += 2) {
        if (t[j + 1] != '*') {
          return false;
        }
      }

      return true;
    }

    // 计算memo数组
    // 记录<i,j>消除重复子问题
    std::string key = std::to_string(i) + ',' + std::to_string(j);
    if (memo.count(key)) {
      return memo[key];
    }

    bool res = false;

    if (s[i] == t[j] || t[j] == '.') {
      if (j < n - 1 && t[j + 1] == '*') {
        // 通配符匹配0~多次
        res = dp(s, i, t, j + 2) || dp(s, i + 1, t, j);
      } else {
        res = dp(s, i + 1, t, j + 1);
      }
    } else {
      if (j < n - 1 && t[j + 1] == '*') {
        // 通配符匹配0次
        res = dp(s, i, t, j + 2);
      } else {
        return false;
      }
    }

    // 结果计入备忘录
    memo[key] = res;

    return res;
  }

  std::map<std::string, bool> memo;
};
// @lc code=end
