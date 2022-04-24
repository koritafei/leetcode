/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (51.25%)
 * Likes:    5905
 * Dislikes: 271
 * Total Accepted:    480.2K
 * Total Submissions: 936.7K
 * Testcase Example:  '12'
 *
 * Given an integer n, return the least number of perfect square numbers that
 * sum to n.
 *
 * A perfect square is an integer that is the square of an integer; in other
 * words, it is the product of some integer with itself. For example, 1, 4, 9,
 * and 16 are perfect squares while 3 and 11 are not.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 12
 * Output: 3
 * Explanation: 12 = 4 + 4 + 4.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 10^4
 *
 *
 */

#include <queue>

// @lc code=start
class Solution {
public:
  int numSquares(int n) {
    std::queue<std::pair<int, int>> que;
    que.push(std::make_pair(n, 0));
    std::vector<bool> visited = std::vector<bool>(n + 1, false);
    while (que.size()) {
      std::pair<int, int> pair = que.front();
      que.pop();
      int nums = pair.first;
      int step = pair.second;

      if (0 == nums) {
        return step;
      }

      for (int i = 0;; i++) {
        int a = nums - i * i;
        if (a < 0) {
          break;
        }

        if (a == 0) {
          return step + 1;
        }
        if (visited[a] == false) {
          que.push(std::make_pair(a, step + 1));
          visited[a] = true;
        }
      }
    }

    return -1;
  }
};
// @lc code=end
