/*
 * @lc app=leetcode id=391 lang=cpp
 *
 * [391] Perfect Rectangle
 *
 * https://leetcode.com/problems/perfect-rectangle/description/
 *
 * algorithms
 * Hard (31.69%)
 * Likes:    539
 * Dislikes: 92
 * Total Accepted:    32.2K
 * Total Submissions: 101.4K
 * Testcase Example:  '[[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]'
 *
 * Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] represents
 * an axis-aligned rectangle. The bottom-left point of the rectangle is (xi,
 * yi) and the top-right point of it is (ai, bi).
 *
 * Return true if all the rectangles together form an exact cover of a
 * rectangular region.
 *
 *
 * Example 1:
 *
 *
 * Input: rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
 * Output: true
 * Explanation: All 5 rectangles together form an exact cover of a rectangular
 * region.
 *
 *
 * Example 2:
 *
 *
 * Input: rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
 * Output: false
 * Explanation: Because there is a gap between the two rectangular regions.
 *
 *
 * Example 3:
 *
 *
 * Input: rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[3,2,4,4]]
 * Output: false
 * Explanation: Because there is a gap in the top center.
 *
 *
 * Example 4:
 *
 *
 * Input: rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
 * Output: false
 * Explanation: Because two of the rectangles overlap with each other.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= rectangles.length <= 2 * 10^4
 * rectangles[i].length == 4
 * -10^5 <= xi, yi, ai, bi <= 10^5
 *
 *
 */

#include <climits>
#include <set>
#include <vector>

// @lc code=start
class Solution {
public:
  bool isRectangleCover(std::vector<std::vector<int>>& rectangles) {
    int                           len = rectangles.size();
    std::set<std::pair<int, int>> set;
    long long                     sumArea = 0;
    int rx = INT_MIN, ry = INT_MIN, lx = INT_MAX, ly = INT_MAX;
    for (int i = 0; i < len; i++) {
      int leftx = rectangles[i][0], lefty = rectangles[i][1];
      int rightx = rectangles[i][2], righty = rectangles[i][3];
      sumArea += (long long)((rightx - leftx)) * (long long)((righty - lefty));
      std::vector<std::pair<int, int>> tmp{std::make_pair(leftx, righty),
                                           std::make_pair(leftx, lefty),
                                           std::make_pair(rightx, righty),
                                           std::make_pair(rightx, lefty)};
      lx = std::min(lx, leftx);
      ly = std::min(ly, lefty);
      rx = std::max(rx, rightx);
      ry = std::max(ry, righty);

      for (auto& it : tmp) {
        if (set.find(it) != set.end()) {
          set.erase(it);
        } else {
          set.insert(it);
        }
      }
    }

    if (set.size() != 4) {
      return false;
    }

    std::vector<std::pair<int, int>> tmp{std::make_pair(lx, ly),
                                         std::make_pair(lx, ry),
                                         std::make_pair(rx, ly),
                                         std::make_pair(rx, ry)};
    for (auto& it : tmp) {
      if (set.find(it) == set.end()) {
        return false;
      }
    }

    if (rx == INT_MIN || ry == INT_MIN || lx == INT_MAX || ly == INT_MAX) {
      return false;
    }

    long long bArea = (long long)((rx - lx)) * (long long)((ry - ly));

    if (bArea != sumArea) {
      return false;
    }

    return true;
  }
};
// @lc code=end
