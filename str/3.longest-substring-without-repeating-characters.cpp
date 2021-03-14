/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (31.46%)
 * Likes:    13433
 * Dislikes: 696
 * Total Accepted:    2.1M
 * Total Submissions: 6.6M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string s, find the length of thelongest substring without repeating
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

#include <iostream>
#include <string>

// @lc code=start
class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    int length = s.length();
    if (length < 1) {
      return 0;
    }
    int freq[256] = {0};
    int lengthest = 0;
    int left = 0, right = -1;

    while (left < length) {
      if (right + 1 < length && freq[s[right + 1]] == 0) {
        freq[s[++right]]++;
      } else {
        freq[s[left++]]--;
      }

      lengthest = std::max(lengthest, right - left + 1);
    }

    return lengthest;
  }
};
// @lc code=end

int main(int argc, char **argv) {
  Solution    solution;
  std::string s = "abcabcbb";
  std::cout << solution.lengthOfLongestSubstring(s) << std::endl;
  s = "bbbbb";
  std::cout << solution.lengthOfLongestSubstring(s) << std::endl;
  s = "pwwkew";
  std::cout << solution.lengthOfLongestSubstring(s) << std::endl;
  s = "";
  std::cout << solution.lengthOfLongestSubstring(s) << std::endl;
}
