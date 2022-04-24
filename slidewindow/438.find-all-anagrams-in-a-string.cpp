/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (46.76%)
 * Likes:    5454
 * Dislikes: 220
 * Total Accepted:    426.2K
 * Total Submissions: 910.3K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given two strings s and p, return an array of all the start indices of p's
 * anagrams in s. You may return the answer in any order.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "cbaebabacd", p = "abc"
 * Output: [0,6]
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "abab", p = "ab"
 * Output: [0,1,2]
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, p.length <= 3 * 10^4
 * s and p consist of lowercase English letters.
 *
 *
 */

#include <map>
#include <string>
#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<int> findAnagrams(std::string s, std::string p) {
    std::vector<int>    res;
    std::map<char, int> need, window;
    int                 right = 0, left = 0;
    int                 valid = 0;
    for (auto &ch : p) {
      need[ch]++;
    }

    while (right < s.size()) {
      char ch = s[right++];
      if (need.count(ch)) {
        window[ch]++;
        if (need[ch] == window[ch]) {
          valid++;
        }
      }

      while (right - left >= p.size()) {
        if (valid == need.size()) {
          res.push_back(left);
        }

        char c = s[left++];
        if (window.count(c)) {
          if (window[c] == need[c]) {
            valid--;
          }
          window[c]--;
        }
      }
    }

    return res;
  }
};
// @lc code=end
