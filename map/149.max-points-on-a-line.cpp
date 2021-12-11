/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 *
 * https://leetcode.com/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (19.41%)
 * Likes:    684
 * Dislikes: 128
 * Total Accepted:    209.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[1,1],[2,2],[3,3]]'
 *
 * Given an array of points where points[i] = [xi, yi] represents a point on
 * the X-Y plane, return the maximum number of points that lie on the same
 * straight line.
 *
 *
 * Example 1:
 *
 *
 * Input: points = [[1,1],[2,2],[3,3]]
 * Output: 3
 *
 *
 * Example 2:
 *
 *
 * Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * Output: 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= points.length <= 300
 * points[i].length == 2
 * -10^4 <= xi, yi <= 10^4
 * All the points are unique.
 *
 *
 */

#include <climits>
#include <map>
#include <vector>

// @lc code=start
class Solution {
public:
  int maxPoints(std::vector<std::vector<int>> &points) {
    int len = points.size();
    int res = 0;
    for (int i = 0; i < len; i++) {
      std::map<double, int> group;
      int                   dup = 0;
      for (int j = i; j < len; j++) {
        int dx = points[j][0] - points[i][0];
        int dy = points[j][1] - points[i][1];
        if (dx == 0 && dy == 0) {
          dup++;
        } else if (dx == 0) {
          group[INT_MAX]++;
        } else {
          group[(double)dy * 1.0 / dx]++;
        }
      }

      res = std::max(res, dup);
      for (auto it : group) {
        res = std::max(res, it.second + dup);
      }
    }

    return res;
  }
};
// @lc code=end
