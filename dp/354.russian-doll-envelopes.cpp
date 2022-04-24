/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 *
 * https://leetcode.com/problems/russian-doll-envelopes/description/
 *
 * algorithms
 * Hard (39.36%)
 * Likes:    2677
 * Dislikes: 66
 * Total Accepted:    125.9K
 * Total Submissions: 319.9K
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
    // 宽度升序排序，宽度相同时，按照高度降序
    std::sort(envelopes.begin(),
              envelopes.end(),
              [](std::vector<int> &s1, const std::vector<int> &s2) {
                if (s1[0] == s2[0]) {
                  return s1[1] > s2[1];
                }
                return s1[0] < s2[0];
              });
    int len = envelopes.size();

    // base case 每个字符串都可以看做单独的一个上升子序列
    std::vector<int> dp = std::vector<int>(len, 1);

    std::vector<int> height;
    for (int i = 0; i < len; i++) {
      height.push_back(envelopes[i][1]);
    }

    // 计算dp数组
    for (int i = 1; i < len; i++) {
      for (int j = 0; j < i; j++) {
        if (height[j] < height[i]) {
          dp[i] = std::max(dp[i], dp[j] + 1);
        }
      }
    }

    int res = 0;
    for (auto it : dp) {
      res = res > it ? res : it;
    }

    return res;
  }
};
// @lc code=end
