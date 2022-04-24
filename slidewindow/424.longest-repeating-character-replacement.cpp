/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 *
 * https://leetcode.com/problems/longest-repeating-character-replacement/description/
 *
 * algorithms
 * Medium (49.94%)
 * Likes:    3480
 * Dislikes: 138
 * Total Accepted:    161.9K
 * Total Submissions: 323.8K
 * Testcase Example:  '"ABAB"\n2'
 *
 * You are given a string s and an integer k. You can choose any character of
 * the string and change it to any other uppercase English character. You can
 * perform this operation at most k times.
 *
 * Return the length of the longest substring containing the same letter you
 * can get after performing the above operations.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "ABAB", k = 2
 * Output: 4
 * Explanation: Replace the two 'A's with two 'B's or vice versa.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "AABABBA", k = 1
 * Output: 4
 * Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 * The substring "BBBB" has the longest repeating letters, which is 4.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists of only uppercase English letters.
 * 0 <= k <= s.length
 *
 *
 */

#include <algorithm>
#include <string>
#include <vector>

// @lc code=start
class Solution {
public:
  int characterReplacement(std::string s, int k) {
    std::size_t maxrepeat = 0;
    std::size_t left = 0, right = 0;
    std::size_t len = s.size();

    if (0 == len) {
      return 0;
    }

    std::vector<std::size_t> map(26);

    while (right < len) {
      map[s[right] - 'A']++;
      maxrepeat = std::max(maxrepeat,
                           map[s[right] - 'A']);  // 当前窗口中重复元素的最大值

      while (right - left + 1 > k + maxrepeat) {  // [left,
        // right]的元素中不重复元素个数大于k时，需要收缩窗口
        map[s[left++] - 'A']--;
      }

      right++;
    }

    return right - left;
  }
};
// @lc code=end
