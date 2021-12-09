/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 *
 * https://leetcode.com/problems/is-subsequence/description/
 *
 * algorithms
 * Easy (50.02%)
 * Likes:    3374
 * Dislikes: 261
 * Total Accepted:    362.9K
 * Total Submissions: 725.5K
 * Testcase Example:  '"abc"\n"ahbgdc"'
 *
 * Given two strings s and t, return true if s is a subsequence of t, or false
 * otherwise.
 *
 * A subsequence of a string is a new string that is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (i.e., "ace" is a
 * subsequence of "abcde" while "aec" is not).
 *
 *
 * Example 1:
 * Input: s = "abc", t = "ahbgdc"
 * Output: true
 * Example 2:
 * Input: s = "axc", t = "ahbgdc"
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 0 <= s.length <= 100
 * 0 <= t.length <= 10^4
 * s and t consist only of lowercase English letters.
 *
 *
 *
 * Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k
 * >= 10^9, and you want to check one by one to see if t has its subsequence.
 * In this scenario, how would you change your code?
 */

#include <map>
#include <string>
#include <vector>

// @lc code=start
class Solution {
public:
  bool isSubsequence(std::string s, std::string t) {
    std::map<char, std::vector<int>> map;

    for (int i = 0; i < t.size(); i++) {
      map[t[i]].push_back(i);
    }
    int j = 0;

    for (int i = 0; i < s.size(); i++) {
      char ch = s[i];
      if (map.count(ch) == 0) {
        return false;
      }

      int pos = left_bound(map[ch], j);
      if (pos == map[ch].size()) {
        return false;
      }

      j = map[ch][pos] + 1;
    }

    return true;
  }

private:
  // 查找第一个比当前大的值
  int left_bound(std::vector<int> &nums, int tar) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] < tar) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return left;
  }
};
// @lc code=end
