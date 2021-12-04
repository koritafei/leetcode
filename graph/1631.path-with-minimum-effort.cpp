/*
 * @lc app=leetcode id=1631 lang=cpp
 *
 * [1631] Path With Minimum Effort
 *
 * https://leetcode.com/problems/path-with-minimum-effort/description/
 *
 * algorithms
 * Medium (51.25%)
 * Likes:    1744
 * Dislikes: 85
 * Total Accepted:    62K
 * Total Submissions: 120.9K
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

#include <climits>
#include <cmath>
#include <list>
#include <queue>
#include <vector>

// @lc code=start
class Solution {
public:
  int minimumEffortPath(std::vector<std::vector<int>> &heights) {
    int row = heights.size();
    if (0 == row) {
      return 0;
    }
    int col = heights[0].size();

    std::vector<std::vector<int>> effortTo =
        std::vector<std::vector<int>>(row, std::vector<int>(col, INT_MAX));

    std::priority_queue<state, std::vector<state>, greator> hp;
    hp.push(state(0, 0, 0));
    effortTo[0][0] = 0;

    while (hp.size()) {
      state cursate = hp.top();
      hp.pop();

      if (cursate.x == row - 1 && cursate.y == col - 1) {
        // 到达末尾
        return cursate.distfromstart;
      }

      if (effortTo[cursate.x][cursate.y] < cursate.distfromstart) {
        continue;
      }

      for (auto item : adj(cursate.x, cursate.y, row, col)) {
        // 计算从curstate.x,curstate.y 到 item.first, item.second的消耗
        int dist = std::max(effortTo[cursate.x][cursate.y],
                            abs(heights[item.first][item.second] -
                                heights[cursate.x][cursate.y]));

        if (dist < effortTo[item.first][item.second]) {
          effortTo[item.first][item.second] = dist;
          hp.push(state(item.first, item.second, dist));
        }
      }
    }

    return -1;
  }

private:
  std::list<std::pair<int, int>> adj(int x, int y, int row, int col) {
    std::list<std::pair<int, int>> neightors;
    for (auto item : dir) {
      int dx = x + item[0];
      int dy = y + item[1];

      if (isInArea(dx, dy, row, col)) {
        neightors.push_back(std::make_pair(dx, dy));
      }
    }

    return neightors;
  }

  bool isInArea(int x, int y, int row, int col) {
    return x >= 0 && x < row && y >= 0 && y < col;
  }

  struct state {
    int x, y;           // 二维平面中图的坐标
    int distfromstart;  // 从起点到达当前节点的最小距离

    state(int x, int y, int dis) : x(x), y(y), distfromstart(dis) {
    }
  };

  struct greator {
    bool operator()(const state &s1, const state &s2) {
      return s1.distfromstart > s2.distfromstart;
    }
  };

  const std::vector<std::vector<int>> dir = {{-1, 0},
                                             {1, 0},
                                             {0, -1},
                                             {0, 1}};  // 运动方向数组
};
// @lc code=end
