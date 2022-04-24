/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 *
 * https://leetcode.com/problems/delete-operation-for-two-strings/description/
 *
 * algorithms
 * Medium (54.10%)
 * Likes:    2339
 * Dislikes: 39
 * Total Accepted:    99.8K
 * Total Submissions: 184.2K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * Given two strings word1 and word2, return the minimum number of steps
 * required to make word1 and word2 the same.
 *
 * In one step, you can delete exactly one character in either string.
 *
 *
 * Example 1:
 *
 *
 * Input: word1 = "sea", word2 = "eat"
 * Output: 2
 * Explanation: You need one step to make "sea" to "ea" and another step to
 * make "eat" to "ea".
 *
 *
 * Example 2:
 *
 *
 * Input: word1 = "leetcode", word2 = "etco"
 * Output: 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word1.length, word2.length <= 500
 * word1 and word2 consist of only lowercase English letters.
 *
 *
 */

#include <string>
#include <vector>

// @lc code=start
class Solution {
public:
  int minDistance(std::string word1, std::string word2) {
    int len1 = word1.length();
    int len2 = word2.length();

    int lcs = LCS(word1, word2, len1, len2);

    return len1 - lcs + len2 - lcs;
  }

private:
  int LCS(std::string word1, std::string word2, int len1, int len2) {
    std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1, 0));

    for (int i = 1; i <= len1; i++) {
      for (int j = 1; j <= len2; j++) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[len1][len2];
  }
};
// @lc code=end
