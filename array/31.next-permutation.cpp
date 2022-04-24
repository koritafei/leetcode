/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (34.89%)
 * Likes:    8045
 * Dislikes: 2716
 * Total Accepted:    655.8K
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 *
 * If such an arrangement is impossible, it must rearrange it to the lowest
 * possible order (i.e., sorted in ascending order).
 *
 * The replacement must be in place and use only constant extra memory.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3]
 * Output: [1,3,2]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,2,1]
 * Output: [1,2,3]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,1,5]
 * Output: [1,5,1]
 *
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

#include <algorithm>
#include <iostream>
#include <vector>

// @lc code=start
class Solution {
public:
  void nextPermutation(std::vector<int>& nums) {
    int i = nums.size() - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
      i--;
    }

    if (i >= 0) {
      int j = nums.size() - 1;

      while (j >= 0 && nums[j] <= nums[i]) {
        j--;
      }
      std::swap(nums[j], nums[i]);
    }
    std::reverse(nums.begin() + i + 1, nums.end());
  }
};

// @lc code=end
