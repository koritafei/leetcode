/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (46.81%)
 * Likes:    5442
 * Dislikes: 220
 * Total Accepted:    425.7K
 * Total Submissions: 909.4K
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
    int lens = s.size(), lent = p.size();

    std::vector<int> res;
    if (lens == 0 || lent == 0 || lens < lent) {
      return res;
    }

    std::map<char, int> freq;    // p中字符串词频
    std::map<char, int> window;  // 窗口
    int                 valid = 0;
    int                 left = 0, right = 0;
    int                 start = 0;

    for (auto it : p) {
      freq[it]++;
    }

    while (right < lens) {
      char ch = s[right++];

      if (freq.count(ch)) {
        window[ch]++;
        if (window[ch] == freq[ch]) {
          valid++;
        }
      }

      // 缩小窗口
      while (right - left >= lent) {
        if (valid == freq.size()) {
          res.push_back(left);
        }
        char ca = s[left++];

        if (window.count(ca)) {
          if (window[ca] == freq[ca]) {
            valid--;
          }
          window[ca]--;
        }
      }
    }

    return res;
  }
};
// @lc code=end
