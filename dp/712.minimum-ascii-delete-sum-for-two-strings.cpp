/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 *
 * https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
 *
 * algorithms
 * Medium (59.98%)
 * Likes:    1432
 * Dislikes: 57
 * Total Accepted:    48.9K
 * Total Submissions: 81.6K
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

#include <iostream>
#include <vector>

// @lc code=start
class Solution {
public:
  int minimumDeleteSum(std::string s1, std::string s2) {
    int                            m = s1.length();
    int                            n = s2.length();
    std::vector<std::vector<int> > dp =
        std::vector<std::vector<int> >(m + 1, std::vector<int>(n + 1, -1));
    return memo(s1, s2, 0, 0, dp);
  }

private:
  int memo(std::string                     s1,
           std::string                     s2,
           int                             i,
           int                             j,
           std::vector<std::vector<int> >& dp) {
    int res = 0;
    if (s1.length() == i) {
      for (; j < s2.length(); j++) {
        res += s2[j];
      }
      return res;
    }

    if (s2.length() == j) {
      for (; i < s1.length(); i++) {
        res += s1[i];
      }
      return res;
    }

    if (-1 != dp[i][j]) {
      return dp[i][j];
    }

    if (s1[i] == s2[j]) {
      dp[i][j] = memo(s1, s2, i + 1, j + 1, dp);
    } else {
      dp[i][j] = std::min(s1[i] + memo(s1, s2, i + 1, j, dp),
                          s2[j] + memo(s1, s2, i, j + 1, dp));
    }

    return dp[i][j];
  }
};
// @lc code=end

int main(int argc, char** argv) {
  std::string s1 = "delete";
  std::string s2 = "leet";
  Solution    solution;
  std::cout << solution.minimumDeleteSum(s1, s2) << std::endl;
}
