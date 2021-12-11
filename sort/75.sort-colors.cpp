/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (53.11%)
 * Likes:    7882
 * Dislikes: 360
 * Total Accepted:    858.8K
 * Total Submissions: 1.6M
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array nums with n objects colored red, white, or blue, sort them
 * in-place so that objects of the same color are adjacent, with the colors in
 * the order red, white, and blue.
 *
 * We will use the integers 0, 1, and 2 to represent the color red, white, and
 * blue, respectively.
 *
 * You must solve this problem without using the library's sort function.
 *
 *
 * Example 1:
 * Input: nums = [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * Example 2:
 * Input: nums = [2,0,1]
 * Output: [0,1,2]
 * Example 3:
 * Input: nums = [0]
 * Output: [0]
 * Example 4:
 * Input: nums = [1]
 * Output: [1]
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= n <= 300
 * nums[i] is 0, 1, or 2.
 *
 *
 *
 * Follow up: Could you come up with a one-pass algorithm using only constant
 * extra space?
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  void sortColors(std::vector<int>& nums) {
    int zero = -1, twoindex = nums.size();
    int index = 0;
    while (index < twoindex) {
      if (nums[index] == 0) {
        std::swap(nums[index++],
                  nums[++zero]);  // 此时已经确定nums[++zero] == 1
      } else if (nums[index] == 2) {
        std::swap(nums[index], nums[--twoindex]);  // nums[--twoindex]的值不确定
      } else {
        index++;
      }
    }
  }
};
// @lc code=end
