/*
 * @lc app=leetcode id=1312 lang=cpp
 *
 * [1312] Minimum Insertion Steps to Make a String Palindrome
 *
 * https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
 *
 * algorithms
 * Hard (61.97%)
 * Likes:    1265
 * Dislikes: 22
 * Total Accepted:    35.8K
 * Total Submissions: 57.8K
 * Testcase Example:  '"zzazz"'
 *
 * Given a string s. In one step you can insert any character at any index of
 * the string.
 *
 * Return the minimum number of steps to make s palindrome.
 *
 * A Palindrome String is one that reads the same backward as well as
 * forward.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "zzazz"
 * Output: 0
 * Explanation: The string "zzazz" is already palindrome we don't need any
 * insertions.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "mbadm"
 * Output: 2
 * Explanation: String can be "mbdadbm" or "mdbabdm".
 *
 *
 * Example 3:
 *
 *
 * Input: s = "leetcode"
 * Output: 5
 * Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 *
 *
 * Example 4:
 *
 *
 * Input: s = "g"
 * Output: 0
 *
 *
 * Example 5:
 *
 *
 * Input: s = "no"
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 500
 * All characters of s are lower case English letters.
 *
 *
 */

#include <string>
#include <vector>

// @lc code=start
class Solution {
public:
  int minInsertions(std::string s) {
    int len = s.size();
    if (1 >= len) {
      return 0;
    }

    std::vector<std::vector<int>> dp =
        std::vector<std::vector<int>>(len + 1, std::vector<int>(len + 1, 0));

    // 计算dp数组
    for (int i = len - 2; i >= 0; i--) {
      for (int j = i + 1; j < len; j++) {
        if (s[i] == s[j]) {
          dp[i][j] = dp[i + 1][j - 1];
        } else {
          dp[i][j] = 1 + std::min(dp[i][j - 1], dp[i + 1][j]);
        }
      }
    }

    return dp[0][len - 1];
  }
};
// @lc code=end
