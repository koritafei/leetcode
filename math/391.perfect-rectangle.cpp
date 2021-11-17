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
    int leftdownx = INT_MAX, leftdowny = INT_MAX;  // 组成大矩形的左下角顶点
    int rightupx = INT_MIN, rightupy = INT_MIN;  // 组成大矩形的右上角顶点

    std::set<std::pair<int, int>> set;          // 顶点集合
    int                           sumArea = 0;  // 小矩形面积和

    for (auto item : rectangles) {
      leftdownx = std::min(leftdownx, item[0]);
      leftdowny = std::min(leftdowny, item[1]);
      rightupx  = std::max(rightupx, item[2]);
      rightupy  = std::max(rightupy, item[3]);

      sumArea += (item[2] - item[0]) * (item[3] - item[1]);

      std::vector<std::pair<int, int>> points = {
          std::make_pair(item[0], item[1]),
          std::make_pair(item[0], item[3]),
          std::make_pair(item[2], item[1]),
          std::make_pair(item[2], item[3])};

      for (auto it : points) {
        if (set.count(it)) {
          set.erase(it);
        } else {
          set.insert(it);
        }
      }
    }

    int area = (rightupx - leftdownx) * (rightupy - leftdowny);
    if (area != sumArea) {
      return false;
    }

    if (set.size() != 4) {
      return false;
    }

    if (!set.count(std::make_pair(leftdownx, leftdowny))) {
      return false;
    }

    if (!set.count(std::make_pair(rightupx, rightupy))) {
      return false;
    }

    if (!set.count(std::make_pair(leftdownx, rightupy))) {
      return false;
    }

    if (!set.count(std::make_pair(rightupx, leftdowny))) {
      return false;
    }

    return true;
  }
};
// @lc code=end
