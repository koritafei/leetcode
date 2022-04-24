/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (39.97%)
 * Likes:    10300
 * Dislikes: 286
 * Total Accepted:    1.1M
 * Total Submissions: 2.7M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in non-decreasing order, find the
 * starting and ending position of a given target value.
 *
 * If target is not found in the array, return [-1, -1].
 *
 * You must write an algorithm with O(log n) runtime complexity.
 *
 *
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * Example 3:
 * Input: nums = [], target = 0
 * Output: [-1,-1]
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums is a non-decreasing array.
 * -10^9 <= target <= 10^9
 *
 *
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    return std::vector<int>{leftBound(nums, target), rightBound(nums, target)};
  }

private:
  int leftBound(std::vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
      int middle = left + (right - left) / 2;
      if (nums[middle] >= target) {
        right = middle - 1;
      } else {
        left = middle + 1;
      }
    }

    if (left >= nums.size() || nums[left] != target) {
      return -1;
    }

    return left;
  }

  int rightBound(std::vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int middle = left + (right - left) / 2;
      if (nums[middle] <= target) {
        left = middle + 1;
      } else {
        right = middle - 1;
      }
    }

    if (right < 0 || nums[right] != target) {
      return -1;
    }

    return right;
  }
};
// @lc code=end
