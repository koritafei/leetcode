/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (54.73%)
 * Likes:    15401
 * Dislikes: 219
 * Total Accepted:    954.9K
 * Total Submissions: 1.7M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it can trap after raining.
 *
 *
 * Example 1:
 *
 *
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array
 * [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue
 * section) are being trapped.
 *
 *
 * Example 2:
 *
 *
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 *
 *
 *
 * Constraints:
 *
 *
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  int trap(std::vector<int>& height) {
    int              len = height.size();
    std::vector<int> leftmax(len, 0);
    std::vector<int> rightmax(len, 0);
    int              ans = 0;

    leftmax[0]        = height[0];
    rightmax[len - 1] = height[len - 1];

    for (int i = 1; i < len; i++) {
      leftmax[i] = std::max(height[i], leftmax[i - 1]);
    }

    for (int i = len - 2; i >= 0; i--) {
      rightmax[i] = std::max(height[i], rightmax[i + 1]);
    }

    for (int i = 0; i < len; i++) {
      ans += std::min(leftmax[i], rightmax[i]) - height[i];
    }

    return ans;
  }
};
// @lc code=end
