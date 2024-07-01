/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (34.51%)
 * Likes:    38747
 * Dislikes: 1805
 * Total Accepted:    5.5M
 * Total Submissions: 15.9M
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
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 *
 *
 */

// @lc code=start
class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    int                      left = 0, right = 0;
    std::unordered_map<char,int> hash_map;
    int                      ans = 0;

    while (right < s.size()) {
      if (hash_map.find(s[right]) == hash_map.end()) {
        /// 加入
        hash_map[s[right]] = right;
      } else {
        ans             = std::max(ans, hash_map[right] - left + 1);
        hash_map[right] = right;
        left            = hash_map[right];
      }
      right++;
    }

    return ans;
  }
};
// @lc code=end
