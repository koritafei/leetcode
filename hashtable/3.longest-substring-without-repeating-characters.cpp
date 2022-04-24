/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (32.39%)
 * Likes:    18558
 * Dislikes: 852
 * Total Accepted:    2.6M
 * Total Submissions: 8.2M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string s, find the length of the longest substring without repeating
 * characters.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not
 * a substring.
 *
 *
 * Example 4:
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
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 *
 *
 */

#include <iostream>
#include <unordered_map>

// @lc code=start
class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    std::unordered_map<char, int> window;
    int                           res   = 0;
    int                           right = 0, left = 0;

    while (right < s.size()) {
      char c = s[right++];
      window[c]++;

      while (window[c] > 1) {
        char d = s[left++];
        window[d]--;
      }

      res = res < right - left ? right - left : res;
    }

    return res;
  }
};
// @lc code=end
