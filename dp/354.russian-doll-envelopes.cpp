/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 *
 * https://leetcode.com/problems/russian-doll-envelopes/description/
 *
 * algorithms
 * Hard (39.18%)
 * Likes:    2625
 * Dislikes: 66
 * Total Accepted:    123.9K
 * Total Submissions: 315.9K
 * Testcase Example:  '[[5,4],[6,4],[6,7],[2,3]]'
 *
 * You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi]
 * represents the width and the height of an envelope.
 *
 * One envelope can fit into another if and only if both the width and height
 * of one envelope are greater than the other envelope's width and height.
 *
 * Return the maximum number of envelopes you can Russian doll (i.e., put one
 * inside the other).
 *
 * Note: You cannot rotate an envelope.
 *
 *
 * Example 1:
 *
 *
 * Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
 * Output: 3
 * Explanation: The maximum number of envelopes you can Russian doll is 3
 * ([2,3] => [5,4] => [6,7]).
 *
 *
 * Example 2:
 *
 *
 * Input: envelopes = [[1,1],[1,1],[1,1]]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= envelopes.length <= 5000
 * envelopes[i].length == 2
 * 1 <= wi, hi <= 10^4
 *
 *
 */

#include <algorithm>
#include <vector>

// @lc code=start
class Solution {
public:
  int maxEnvelopes(std::vector<std::vector<int>> &envelopes) {
    std::sort(envelopes.begin(),
              envelopes.end(),
              [](const std::vector<int> &a, const std::vector<int> &b) {
                return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
              });

    std::vector<int> height;
    for (int i = 0; i < envelopes.size(); i++) {
      height.push_back(envelopes[i][1]);
    }

    return longofLIS(height);
  }

private:
  int longofLIS(std::vector<int> &height) {
    std::vector<int> dp(height.size() + 1, 1);

    for (int i = 1; i < height.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (height[j] < height[i]) {
          dp[i] = std::max(dp[i], dp[j] + 1);
        }
      }
    }

    int max = 0;
    for (auto item : dp) {
      max = (max > item ? max : item);
    }

    return max;
  }
};
// @lc code=end
