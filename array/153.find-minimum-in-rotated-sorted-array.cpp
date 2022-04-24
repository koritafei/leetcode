/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (47.46%)
 * Likes:    5334
 * Dislikes: 357
 * Total Accepted:    767.7K
 * Total Submissions: 1.6M
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * Suppose an array of length n sorted in ascending order is rotated between 1
 * and n times. For example, the array nums = [0,1,2,4,5,6,7] might
 * become:
 *
 *
 * [4,5,6,7,0,1,2] if it was rotated 4 times.
 * [0,1,2,4,5,6,7] if it was rotated 7 times.
 *
 *
 * Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results
 * in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
 *
 * Given the sorted rotated array nums of unique elements, return the minimum
 * element of this array.
 *
 * You must write an algorithm that runs in O(log n) time.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [3,4,5,1,2]
 * Output: 1
 * Explanation: The original array was [1,2,3,4,5] rotated 3 times.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [4,5,6,7,0,1,2]
 * Output: 0
 * Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4
 * times.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [11,13,15,17]
 * Output: 11
 * Explanation: The original array was [11,13,15,17] and it was rotated 4
 * times.
 *
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= n <= 5000
 * -5000 <= nums[i] <= 5000
 * All the integers of nums are unique.
 * nums is sorted and rotated between 1 and n times.
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  int findMin(std::vector<int>& nums) {
    int len = nums.size();
    if (0 == len) {
      return -1;  // 不存在
    }
    int left = 0, right = nums.size() - 1;
    int mid = 0;

    while (left < right) {
      if (left == right - 1) {
        break;
      }

      if (nums[left] < nums[right]) {
        return nums[left];
      }
      int mid = left + (right - left) / 2;

      if (nums[mid] < nums[left]) {
        right = mid;
      }

      if (nums[mid] > nums[right]) {
        left = mid;
      }

      while (left < mid) {
        if (nums[left] == nums[mid]) {
          left++;
        } else if (nums[left] < nums[mid]) {
          return nums[left];
        } else {
          right = mid;
          break;
        }
      }
    }

    return std::min(nums[left], nums[right]);
  }
};
// @lc code=end
