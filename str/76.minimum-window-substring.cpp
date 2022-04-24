/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (38.08%)
 * Likes:    8749
 * Dislikes: 501
 * Total Accepted:    657.4K
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
#include <map>
#include <string>

// @lc code=start
class Solution {
public:
  std::string minWindow(std::string s, std::string t) {
    int lens = s.size(), lent = t.size();
    if (lens < lent) {
      return "";
    }
    std::map<char, int> freq;
    std::map<char, int> window;

    int valid = 0;  // 标记是否找到t中全部字符串

    int start  = 0;        // 子串开始位置
    int minlen = INT_MAX;  // 子串最大长度

    for (auto it : t) {
      freq[it]++;
    }

    int left = 0, right = 0;

    while (right < lens) {
      char ch = s[right++];

      if (freq.count(ch) !=
          0) {  // 此处统计词频的时候，可能出现ch重复次数大于t中的重复次数
        window[ch]++;
        if (window[ch] == freq[ch]) {  // 只有ch相等时，才会将标记+1,
                                       // 避免出现windon[ch] > freq[ch]
          valid++;
        }
      }

      while (valid == freq.size()) {  // 满足需要的字符串
        // 含有t的全部字符串
        if (minlen > right - left) {
          minlen = right - left;
          start  = left;
        }

        char c = s[left++];
        if (window.count(c) != 0) {
          if (window[c] == freq[c]) {  // 避免出现window[c] > freq[c]
            valid--;
          }
          window[c]--;
        }
      }
    }

    if (minlen != INT_MAX) {  // 返回结果需要判断是否有效
      return s.substr(start, minlen);
    } else {
      return "";
    }
  }
};
// @lc code=end
