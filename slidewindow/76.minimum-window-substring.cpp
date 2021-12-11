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
    int                 len = s.length();
    std::map<char, int> freq, need;
    int                 valid = 0;
    int                 start = 0, minlen = INT_MAX;

    for (char ch : t) {
      freq[ch]++;
    }

    int left = 0, right = 0;
    while (right < len) {
      char ch = s[right++];
      if (freq.count(ch)) {
        need[ch]++;
        if (freq[ch] == need[ch]) {
          valid++;
        }
      }

      while (valid == freq.size()) {
        if (minlen > right - left) {
          minlen = right - left;
          start  = left;
        }
        char ch = s[left++];
        if (need.count(ch)) {
          if (need[ch] == freq[ch]) {
            valid--;
          }

          need[ch]--;
        }
      }
    }
    minlen = minlen == INT_MAX ? 0 : minlen;
    return s.substr(start, minlen);
  }
};
// @lc code=end
