/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (35.95%)
 * Likes:    7197
 * Dislikes: 637
 * Total Accepted:    944.7K
 * Total Submissions: 2.6M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * There is an integer array nums sorted in ascending order (with distinct
 * values).
 *
 * Prior to being passed to your function, nums is rotated at an unknown pivot
 * index k (0 <= k < nums.length) such that the resulting array is [nums[k],
 * nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
 * For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become
 * [4,5,6,7,0,1,2].
 *
 * Given the array nums after the rotation and an integer target, return the
 * index of target if it is in nums, or -1 if it is not in nums.
 *
 *
 * Example 1:
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * Example 2:
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * Example 3:
 * Input: nums = [1], target = 0
 * Output: -1
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 5000
 * -10^4 <= nums[i] <= 10^4
 * All values of nums are unique.
 * nums is guaranteed to be rotated at some pivot.
 * -10^4 <= target <= 10^4
 *
 *
 *
 * Follow up: Can you achieve this in O(log n) time complexity?
 */

#include <iostream>
#include <vector>

// @lc code=start
class Solution {
public:
  int search(std::vector<int>& nums, int target) {
    int len = nums.size();
    if (len == 0) {
      return -1;
    }

    int left = 0, right = len - 1;
    while (left <= right) {
      if (nums[left] == target) {
        return left;
      } else if (nums[right] == target) {
        return right;
      }
      left++;
      right--;
    }

    return -1;
  }
};
// @lc code=end

int main(int argc, char** argv) {
  Solution         solution;
  std::vector<int> nums   = {4, 5, 6, 7, 0, 1, 2};
  int              target = 0;

  std::cout << solution.search(nums, target) << std::endl;
  nums   = {4, 5, 6, 7, 0, 1, 2};
  target = 3;

  std::cout << solution.search(nums, target) << std::endl;
  nums   = {1};
  target = 0;

  std::cout << solution.search(nums, target) << std::endl;
}
