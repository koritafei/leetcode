/*
 * @lc app=leetcode id=1631 lang=cpp
 *
 * [1631] Path With Minimum Effort
 *
 * https://leetcode.com/problems/path-with-minimum-effort/description/
 *
 * algorithms
 * Medium (51.25%)
 * Likes:    1759
 * Dislikes: 86
 * Total Accepted:    62.9K
 * Total Submissions: 122.7K
 * Testcase Example:  '[[1,2,2],[3,8,2],[5,3,5]]'
 *
 * You are a hiker preparing for an upcoming hike. You are given heights, a 2D
 * array of size rows x columns, where heights[row][col] represents the height
 * of cell (row, col). You are situated in the top-left cell, (0, 0), and you
 * hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e.,
 * 0-indexed). You can move up, down, left, or right, and you wish to find a
 * route that requires the minimum effort.
 *
 * A route's effort is the maximum absolute difference in heights between two
 * consecutive cells of the route.
 *
 * Return the minimum effort required to travel from the top-left cell to the
 * bottom-right cell.
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
 * Output: 2
 * Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2
 * in consecutive cells.
 * This is better than the route of [1,2,2,2,5], where the maximum absolute
 * difference is 3.
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
 * Output: 1
 * Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1
 * in consecutive cells, which is better than route [1,3,5,3,5].
 *
 *
 * Example 3:
 *
 *
 * Input: heights =
 * [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
 * Output: 0
 * Explanation: This route does not require any effort.
 *
 *
 *
 * Constraints:
 *
 *
 * rows == heights.length
 * columns == heights[i].length
 * 1 <= rows, columns <= 100
 * 1 <= heights[i][j] <= 10^6
 *
 */

#include <algorithm>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
// @lc code=start
class Solution {
public:
  int minimumEffortPath(std::vector<std::vector<int>>& heights) {
    int row = heights.size(), col = heights[0].size();

    std::vector<std::vector<int>> dp =
        std::vector<std::vector<int>>(row, std::vector<int>(col, INT_MAX));

    std::priority_queue<state, std::vector<state>, greator> hp;
    hp.push(state(0, 0, 0));
    dp[0][0] = 0;

    while (hp.size()) {
      state curr = hp.top();
      hp.pop();
      int x = curr.x;
      int y = curr.y;
      int w = curr.w;

      if (x == row - 1 && y == col - 1) {
        return w;
      }

      if (w > dp[x][y]) {
        continue;
      }

      std::vector<std::pair<int, int>> edge = adj(row, col, x, y);
      for (auto iter : edge) {
        int dx     = iter.first;
        int dy     = iter.second;
        int w      = heights[dx][dy];
        int weight = std::max(dp[x][y], abs(heights[x][y] - w));
        if (weight < dp[dx][dy]) {
          dp[dx][dy] = weight;
          hp.push(state(dx, dy, weight));
        }
      }
    }

    return -1;
  }

private:
  std::vector<std::pair<int, int>> adj(int row, int col, int x, int y) {
    std::vector<std::pair<int, int>> result;
    for (auto iter : dir) {
      int dx = x + iter[0];
      int dy = y + iter[1];
      if (isInArea(row, col, dx, dy)) {
        result.push_back(std::make_pair(dx, dy));
      }
    }

    return result;
  }

  bool isInArea(int row, int col, int x, int y) {
    return x >= 0 && x < row && y >= 0 && y < col;
  }

  struct state {
    int x, y;
    int w;
    state(int x, int y, int w) : x(x), y(y), w(w) {
    }
  };

  struct greator {
    bool operator()(const state& state1, const state& state2) {
      return state1.w > state2.w;
    }
  };

  const std::vector<std::vector<int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
};
// @lc code=end
