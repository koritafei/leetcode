/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 *
 * https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
 *
 * algorithms
 * Medium (60.82%)
 * Likes:    1690
 * Dislikes: 60
 * Total Accepted:    55.9K
 * Total Submissions: 91.8K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * Given two strings s1 and s2, return the lowest ASCII sum of deleted
 * characters to make two strings equal.
 *
 *
 * Example 1:
 *
 *
 * Input: s1 = "sea", s2 = "eat"
 * Output: 231
 * Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to
 * the sum.
 * Deleting "t" from "eat" adds 116 to the sum.
 * At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum
 * possible to achieve this.
 *
 *
 * Example 2:
 *
 *
 * Input: s1 = "delete", s2 = "leet"
 * Output: 403
 * Explanation: Deleting "dee" from "delete" to turn the string into "let",
 * adds 100[d] + 101[e] + 101[e] to the sum.
 * Deleting "e" from "leet" adds 101[e] to the sum.
 * At the end, both strings are equal to "let", and the answer is
 * 100+101+101+101 = 403.
 * If instead we turned both strings into "lee" or "eet", we would get answers
 * of 433 or 417, which are higher.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s1.length, s2.length <= 1000
 * s1 and s2 consist of lowercase English letters.
 *
 *
 */

#include <string>
#include <vector>

// @lc code=start
class Solution {
public:
  int minimumDeleteSum(std::string s1, std::string s2) {
    int len1 = s1.length(), len2 = s2.length();
    memo =
        std::vector<std::vector<int>>(len1 + 1, std::vector<int>(len2 + 1, -1));
    return dp(s1, 0, s2, 0);
  }

private:
  int dp(std::string s1, int index1, std::string s2, int index2) {
    int res = 0;
    if (index1 == s1.length()) {
      for (; index2 < s2.length(); index2++) {
        res += s2[index2];
      }
      return res;
    }

    if (index2 == s2.length()) {
      for (; index1 < s1.length(); index1++) {
        res += s1[index1];
      }
      return res;
    }

    if (memo[index1][index2] != -1) {
      return memo[index1][index2];
    }

    if (s1[index1] == s2[index2]) {
      memo[index1][index2] = dp(s1, index1 + 1, s2, index2 + 1);
    } else {
      memo[index1][index2] =
          std::min(s2[index2] + dp(s1, index1, s2, index2 + 1),
                   s1[index1] + dp(s1, index1 + 1, s2, index2));
    }

    return memo[index1][index2];
  }

  std::vector<std::vector<int>> memo;
};
// @lc code=end
