/*
 * @lc app=leetcode id=447 lang=cpp
 *
 * [447] Number of Boomerangs
 *
 * https://leetcode.com/problems/number-of-boomerangs/description/
 *
 * algorithms
 * Medium (52.46%)
 * Likes:    454
 * Dislikes: 750
 * Total Accepted:    72.7K
 * Total Submissions: 138.6K
 * Testcase Example:  '[[0,0],[1,0],[2,0]]'
 *
 * You are given n points in the plane that are all distinct, where points[i] =
 * [xi, yi]. A boomerang is a tuple of points (i, j, k) such that the distance
 * between i and j equals the distance between i and k (the order of the tuple
 * matters).
 *
 * Return the number of boomerangs.
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
 * n == points.length
 * 1 <= n <= 500
 * points[i].length == 2
 * -10^4 <= xi, yi <= 10^4
 * All the points are unique.
 *
 *
 */

// @lc code=start
class Solution {
public:
  int numberOfBoomerangs(vector<vector<int>>& points) {
    std::vector<pair<int, int>> tmp;
    for (auto item : points) {
      tmp.push_back(pair<int, int>(item[0], item[1]));
    }

    return numberOfBoomerangs(tmp);
  }

private:
  int numberOfBoomerangs(vector<pair<int, int>>& points) {
    int res = 0;
    for (int i = 0; i < points.size(); i++) {
      unordered_map<int, int> m;
      for (int j = 0; j < points.size(); j++) {
        if (j != i) {
          m[dis(points[i], points[j])]++;
        }
      }

      for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second >= 2) {
          res += (it->second) * (it->second - 1);
        }
      }
    }
    return res;
  }

  int dis(pair<int, int>& points0, pair<int, int>& points1) {
    return (points0.first - points1.first) * (points0.first - points1.first) +
           (points0.second - points1.second) *
               (points0.second - points1.second);
  }
};
// @lc code=end
