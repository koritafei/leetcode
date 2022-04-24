/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (44.38%)
 * Likes:    3503
 * Dislikes: 93
 * Total Accepted:    241.9K
 * Total Submissions: 545K
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

#include <string>
#include <unordered_map>

// @lc code=start
class Solution {
public:
  bool checkInclusion(std::string s1, std::string s2) {
    std::unordered_map<char, int> need, window;
    for (auto c : s1) {
      need[c]++;
    }
    int left = 0, right = 0;
    int valid = 0;
    while (right < s2.size()) {
      char c = s2[right++];
      if (need.count(c)) {
        window[c]++;
        if (window[c] == need[c]) {
          valid++;
        }
      }

      while (s1.size() <= right - left) {
        if (valid == need.size()) {
          return true;
        }

        char d = s2[left++];
        if (window.count(d)) {
          if (window[d] == need[d]) {
            valid--;
          }
          window[d]--;
        }
      }
    }

    return false;
  }
};
// @lc code=end
