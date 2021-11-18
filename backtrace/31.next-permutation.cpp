/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (34.76%)
 * Likes:    7701
 * Dislikes: 2566
 * Total Accepted:    632.5K
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 *
 * If such an arrangement is not possible, it must rearrange it as the lowest
 * possible order (i.e., sorted in ascending order).
 *
 * The replacement must be in place and use only constant extra memory.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [1,3,2]
 * Example 2:
 * Input: nums = [3,2,1]
 * Output: [1,2,3]
 * Example 3:
 * Input: nums = [1,1,5]
 * Output: [1,5,1]
 * Example 4:
 * Input: nums = [1]
 * Output: [1]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 100
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  void nextPermutation(std::vector<int>& nums) {
    int n = nums.size(), i, j;
    for (i = n - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1]) {
        break;
      }
    }
    if (i < 0) {
      std::reverse(nums.begin(), nums.end());
      return;
    } else {
      for (j = n - 1; j > i; j--) {
        if (nums[j] > nums[i]) {
          break;
        }
      }
      std::swap(nums[i], nums[j]);
      std::reverse(nums.begin() + i + 1, nums.end());
      return;
    }
  }
};
// @lc code=end
