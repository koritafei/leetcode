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
    int         len = s.size();
    std::string res;
    for (int i = 0; i < len; i++) {
      std::string left  = palindrome(s, i, i);
      std::string right = palindrome(s, i, i + 1);

      res = res.length() > left.length() ? res : left;
      res = res.length() > right.length() ? res : right;
    }

    return res;
  }

private:
  std::string palindrome(std::string &s, int i, int j) {
    for (; i >= 0 && j < s.size();) {
      if (s[i] == s[j]) {
        i--;
        j++;
      } else {
        break;
      }
    }

    return s.substr(i + 1, j - i - 1);
  }
};
// @lc code=end
