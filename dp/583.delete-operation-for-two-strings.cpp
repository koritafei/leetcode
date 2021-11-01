/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 *
 * https://leetcode.com/problems/delete-operation-for-two-strings/description/
 *
 * algorithms
 * Medium (52.15%)
 * Likes:    1887
 * Dislikes: 38
 * Total Accepted:    85K
 * Total Submissions: 162.9K
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

#include <iostream>
#include <vector>

// @lc code=start
class Solution {
public:
  int minDistance(std::string word1, std::string word2) {
    int len = lcs(word1, word2);

    return word1.length() + word2.length() - (len << 1);
  }

private:
  int lcs(std::string word1, std::string word2) {
    int                           m = word1.size();
    int                           n = word2.size();
    std::vector<std::vector<int>> dp =
        std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[m][n];
  }
};
// @lc code=end

int main(int argc, char **argv) {
  std::string text1 = "leetcode";
  std::string text2 = "etco";
  Solution    solution;

  std::cout << solution.minDistance(text1, text2) << std::endl;
}
