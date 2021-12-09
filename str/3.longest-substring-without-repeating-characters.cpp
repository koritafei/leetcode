/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (32.53%)
 * Likes:    19372
 * Dislikes: 888
 * Total Accepted:    2.7M
 * Total Submissions: 8.4M
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

#include <climits>
#include <map>
#include <string>

// @lc code=start
class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    int                 maxlen = INT_MIN;
    int                 i = 0, j = 0;
    std::map<char, int> freq;

    while (j < s.size()) {
      char ch = s[j++];
      freq[ch]++;

      while (freq[ch] > 1) {
        char c = s[i++];
        freq[c]--;
      }

      maxlen = std::max(maxlen, j - i);
    }

    return maxlen == INT_MIN ? 0 : maxlen;
  }
};
// @lc code=end
