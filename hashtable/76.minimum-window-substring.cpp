/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (36.05%)
 * Likes:    6188
 * Dislikes: 419
 * Total Accepted:    507.2K
 * Total Submissions: 1.4M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given two strings s and t, return the minimum window in s which will contain
 * all the characters in t. If there is no such window in s that covers all
 * characters in t, return the empty string "".
 *
 * Note that If there is such a window, it is guaranteed that there will always
 * be only one unique minimum window in s.
 *
 *
 * Example 1:
 * Input: s = "ADOBECODEBANC", t = "ABC"
 * Output: "BANC"
 * Example 2:
 * Input: s = "a", t = "a"
 * Output: "a"
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, t.length <= 10^5
 * s and t consist of English letters.
 *
 *
 *
 * Follow up: Could you find an algorithm that runs in O(n) time?
 */

#include <iostream>
#include <vector>

// @lc code=start
class Solution {
public:
  std::string minWindow(std::string s, std::string t) {
    int len1 = s.length();
    int len2 = t.length();
    if (len1 < len2 || len1 < 0 || len2 < 0) {
      return "";
    }
    std::vector<int> v(128, 0);
    for (char c : t) {
      v[c]++;
    }

    int begin = 0;
    int end   = 0;
    int head  = 0;
    int count = len2, len = INT_MAX;
    while (end < len1) {
      if (v[s[end++]]-- > 0) {
        --count;
      }

      while (!count) {
        if (end - begin < len) {
          len = end - (head = begin);
        }

        if (v[s[begin++]]++ == 0) {
          ++count;
        }
      }
    }

    return len == INT_MAX ? "" : s.substr(head, len);
  }
};
// @lc code=end
