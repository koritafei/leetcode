/*
 * @lc app=leetcode id=447 lang=cpp
 *
 * [447] Number of Boomerangs
 *
 * https://leetcode.com/problems/number-of-boomerangs/description/
 *
 * algorithms
 * Medium (53.23%)
 * Likes:    518
 * Dislikes: 813
 * Total Accepted:    78.3K
 * Total Submissions: 146.9K
 * Testcase Example:  '[[0,0],[1,0],[2,0]]'
 *
 * You are given n points in the plane that are all distinct, where points[i] =
 * [xi, yi]. A boomerang is a tuple of points (i, j, k) such that the distance
 * between i and j equals the distance between i and k (the order of the tuple
 * matters).
 *
 * Return the number of boomerangs.
 *
 *
 * Example 1:
 *
 *
 * Input: points = [[0,0],[1,0],[2,0]]
 * Output: 2
 * Explanation: The two boomerangs are [[1,0],[0,0],[2,0]] and
 * [[1,0],[2,0],[0,0]].
 *
 *
 * Example 2:
 *
 *
 * Input: points = [[1,1],[2,2],[3,3]]
 * Output: 2
 *
 *
 * Example 3:
 *
 *
 * Input: points = [[1,1]]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * n == points.length
 * 1 <= n <= 500
 * points[i].length == 2
 * -10^4 <= xi, yi <= 10^4
 * All the points are unique.
 *
 *
 */

#include <map>
#include <set>
#include <vector>

// @lc code=start
class Solution {
public:
  int numberOfBoomerangs(std::vector<std::vector<int>>& points) {
    int res = 0;

    for (int i = 0; i < points.size(); i++) {
      std::map<long, int> disResult;

      for (int j = 0; j < points.size(); j++) {
        if (j == i) {
          continue;
        }

        int dis = distance(points[i], points[j]);
        disResult[dis]++;
      }

      for (auto& p : disResult) {
        if (p.second > 1) {
          res += p.second * (p.second - 1);
        }
      }
    }

    return res;
  }

private:
  long distance(std::vector<int>& s1, std::vector<int>& s2) {
    return (s2[0] - s1[0]) * (s2[0] - s1[0]) +
           (s2[1] - s1[1]) * (s2[1] - s1[1]);
  }
};
// @lc code=end
