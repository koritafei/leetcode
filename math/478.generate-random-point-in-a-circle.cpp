/*
 * @lc app=leetcode id=478 lang=cpp
 *
 * [478] Generate Random Point in a Circle
 *
 * https://leetcode.com/problems/generate-random-point-in-a-circle/description/
 *
 * algorithms
 * Medium (39.13%)
 * Likes:    338
 * Dislikes: 641
 * Total Accepted:    31.7K
 * Total Submissions: 80.9K
 * Testcase Example:
 * '["Solution","randPoint","randPoint","randPoint"]\n[[1.0,0.0,0.0],[],[],[]]'
 *
 * Given the radius and the position of the center of a circle, implement the
 * function randPoint which generates a uniform random point inside the
 * circle.
 *
 * Implement the Solution class:
 *
 *
 * Solution(double radius, double x_center, double y_center) initializes the
 * object with the radius of the circle radius and the position of the center
 * (x_center, y_center).
 * randPoint() returns a random point inside the circle. A point on the
 * circumference of the circle is considered to be in the circle. The answer is
 * returned as an array [x, y].
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["Solution", "randPoint", "randPoint", "randPoint"]
 * [[1.0, 0.0, 0.0], [], [], []]
 * Output
 * [null, [-0.02493, -0.38077], [0.82314, 0.38945], [0.36572, 0.17248]]
 *
 * Explanation
 * Solution solution = new Solution(1.0, 0.0, 0.0);
 * solution.randPoint(); // return [-0.02493, -0.38077]
 * solution.randPoint(); // return [0.82314, 0.38945]
 * solution.randPoint(); // return [0.36572, 0.17248]
 *
 *
 *
 * Constraints:
 *
 *
 * 0 < radius <= 10^8
 * -10^7 <= x_center, y_center <= 10^7
 * At most 3 * 10^4 calls will be made to randPoint.
 *
 *
 */

#include <cmath>
#include <vector>

// @lc code=start
class Solution {
public:
  double RAD, XC, YC;
  Solution(double radius, double x_center, double y_center) {
    RAD = radius;
    XC  = x_center;
    YC  = y_center;
  }
  std::vector<double> randPoint() {
    double ang = (double)rand() / RAND_MAX * 2 * M_PI,
           hyp = sqrt((double)rand() / RAND_MAX) * RAD, adj = cos(ang) * hyp,
           opp = sin(ang) * hyp;
    return std::vector<double>{XC + adj, YC + opp};
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
// @lc code=end
