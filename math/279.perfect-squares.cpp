/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (49.01%)
 * Likes:    4088
 * Dislikes: 231
 * Total Accepted:    382.2K
 * Total Submissions: 779.6K
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

// @lc code=start
class Solution {
public:
  int numSquares(int n) {
    queue<pair<int, int>> q;
    q.push(make_pair(n, 0));
    vector<bool> visited(n + 1, false);
    visited[n] = true;

    while (q.size()) {
      int num  = q.front().first;
      int step = q.front().second;
      q.pop();
      if (num == 0) {
        return step;
      }

      for (int i = 0; num - i * i >= 0; i++) {
        if (!visited[num - i * i]) {
          q.push(make_pair(num - i * i, step + 1));
          visited[num - i * i] = true;
        }
      }
    }

    return -1;
  }
};
// @lc code=end
