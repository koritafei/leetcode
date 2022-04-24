/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (38.05%)
 * Likes:    8759
 * Dislikes: 501
 * Total Accepted:    658.2K
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
#include <map>
#include <string>

// @lc code=start
class Solution {
public:
  std::string minWindow(std::string s, std::string t) {
    std::map<char, int> need, window;
    for (auto &ch : t) {
      need[ch]++;
    }
    int lens = s.size();
    int left = 0, right = 0;
    int valid = 0;
    int start = 0, len = INT_MAX;  // 子串起点与长度
    while (right < lens) {
      char ch = s[right++];
      if (need.find(ch) != need.end()) {
        window[ch]++;
        if (need[ch] == window[ch]) {
          valid++;
        }
      }

      while (valid == need.size()) {
        if (right - left < len) {
          len   = right - left;
          start = left;
        }

        char c = s[left++];

        if (window.find(c) != window.end()) {
          if (window[c] == need[c]) {
            valid--;
          }
          window[c]--;
        }
      }
    }

    return len == INT_MAX ? "" : s.substr(start, len);
  }
};
// @lc code=end
