/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (54.27%)
 * Likes:    14941
 * Dislikes: 212
 * Total Accepted:    927.8K
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
    int len  = height.size();
    int ans  = 0;
    int left = 0, right = len - 1;
    int left_max = height[0], right_max = height[len - 1];

    while (left <= right) {
      left_max  = std::max(left_max, height[left]);
      right_max = std::max(right_max, height[right]);

      if (left_max < right_max) {
        ans += left_max - height[left];
        left++;
      } else {
        ans += right_max - height[right];
        right--;
      }
    }

    return ans;
  }
};
// @lc code=end
