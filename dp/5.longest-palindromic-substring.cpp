/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (31.39%)
 * Likes:    14136
 * Dislikes: 834
 * Total Accepted:    1.5M
 * Total Submissions: 4.9M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, return the longest palindromic substring in s.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "cbbd"
 * Output: "bb"
 *
 *
 * Example 3:
 *
 *
 * Input: s = "a"
 * Output: "a"
 *
 *
 * Example 4:
 *
 *
 * Input: s = "ac"
 * Output: "a"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s consist of only digits and English letters.
 *
 *
 */

#include <iostream>

// @lc code=start
class Solution {
public:
  std::string longestPalindrome(std::string s) {
    int         len = s.length();
    std::string res;
    for (int i = 0; i < len; i++) {
      std::string t1 = palindrome(s, i, i);
      std::string t2 = palindrome(s, i, i + 1);
      res            = (res.length() > t1.length() ? res : t1);
      res            = (res.length() > t2.length() ? res : t2);
    }

    return res;
  }

private:
  // 中心法判断回文串
  std::string palindrome(std::string &s, int lo, int hi) {
    while (lo >= 0 && hi < s.size() && s[lo] == s[hi]) {
      lo--;
      hi++;
    }

    // 返回以s[lo]和s[hi]为中心的回文串
    return s.substr(lo + 1, hi - lo - 1);
  }
};
// @lc code=end
