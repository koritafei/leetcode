/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (59.79%)
 * Likes:    7354
 * Dislikes: 205
 * Total Accepted:    1.4M
 * Total Submissions: 2.3M
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an integer array nums, move all 0's to the end of it while maintaining
 * the relative order of the non-zero elements.
 *
 * Note that you must do this in-place without making a copy of the array.
 *
 *
 * Example 1:
 * Input: nums = [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * Example 2:
 * Input: nums = [0]
 * Output: [0]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 *
 *
 *
 * Follow up: Could you minimize the total number of operations done?
 */

#include <vector>

// @lc code=start
class Solution {
public:
  void moveZeroes(std::vector<int>& nums) {
    int len = nums.size();
    if (1 == len) {
      return;
    }

    int slow = -1, fast = 0;
    while (fast < len) {
      if (nums[fast] != 0) {
        std::swap(nums[++slow], nums[fast]);
      }
      fast++;
    }
  }
};
// @lc code=end
