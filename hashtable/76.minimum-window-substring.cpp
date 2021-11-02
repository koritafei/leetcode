/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (37.87%)
 * Likes:    8452
 * Dislikes: 497
 * Total Accepted:    638.6K
 * Total Submissions: 1.7M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given two strings s and t of lengths m and n respectively, return the
 * minimum window substring of s such that every character in t (including
 * duplicates) is included in the window. If there is no such substring, return
 * the empty string "".
 *
 * The testcases will be generated such that the answer is unique.
 *
 * A substring is a contiguous sequence of characters within the string.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "ADOBECODEBANC", t = "ABC"
 * Output: "BANC"
 * Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C'
 * from string t.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "a", t = "a"
 * Output: "a"
 * Explanation: The entire string s is the minimum window.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "a", t = "aa"
 * Output: ""
 * Explanation: Both 'a's from t must be included in the window.
 * Since the largest window of s only has one 'a', return empty string.
 *
 *
 *
 * Constraints:
 *
 *
 * m == s.length
 * n == t.length
 * 1 <= m, n <= 10^5
 * s and t consist of uppercase and lowercase English letters.
 *
 *
 *
 * Follow up: Could you find an algorithm that runs in O(m + n) time?
 */

#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>

// @lc code=start
class Solution {
public:
  std::string minWindow(std::string s, std::string t) {
    std::unordered_map<char, int> need, windows;
    for (auto c : t) {
      need[c]++;
    }

    int left = 0, right = 0;
    int valid = 0;
    int start = 0;
    int len   = INT_MAX;
    while (right < s.size()) {
      char c = s[right++];
      if (need.count(c)) {
        windows[c]++;

        if (windows[c] == need[c]) {
          valid++;
        }
      }

      // 是否进行收缩
      while (valid == need.size()) {
        // 更新最小长度
        if (right - left < len) {
          start = left;
          len   = right - left;
        }
        char d = s[left++];
        if (windows.count(d)) {
          if (windows[d] == need[d]) {
            valid--;
          }
          windows[d]--;
        }
      }
    }

    return len == INT_MAX ? "" : s.substr(start, len);
  }
};
// @lc code=end
