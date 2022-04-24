/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (44.25%)
 * Likes:    3776
 * Dislikes: 102
 * Total Accepted:    258.9K
 * Total Submissions: 585.2K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1,
 * or false otherwise.
 *
 * In other words, return true if one of s1's permutations is the substring of
 * s2.
 *
 *
 * Example 1:
 *
 *
 * Input: s1 = "ab", s2 = "eidbaooo"
 * Output: true
 * Explanation: s2 contains one permutation of s1 ("ba").
 *
 *
 * Example 2:
 *
 *
 * Input: s1 = "ab", s2 = "eidboaoo"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s1.length, s2.length <= 10^4
 * s1 and s2 consist of lowercase English letters.
 *
 *
 */

#include <map>
#include <string>

// @lc code=start
class Solution {
public:
  bool checkInclusion(std::string s1, std::string s2) {
    std::map<char, int> need, window;
    for (auto &ch : s1) {
      need[ch]++;
    }

    int right = 0, left = 0;
    int valid = 0;

    while (right < s2.size()) {
      char ch = s2[right++];
      if (need.count(ch)) {
        window[ch]++;
        if (window[ch] == need[ch]) {
          valid++;
        }
      }

      while (s1.size() <= right - left) {
        if (valid == need.size()) {
          return true;
        }

        char c = s2[left++];
        if (window.count(c)) {
          if (window[c] == need[c]) {
            valid--;
          }

          window[c]--;
        }
      }
    }

    return false;
  }
};
// @lc code=end
