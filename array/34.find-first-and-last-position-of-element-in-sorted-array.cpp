/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (37.35%)
 * Likes:    5155
 * Dislikes: 197
 * Total Accepted:    666.4K
 * Total Submissions: 1.8M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 *
 * If target is not found in the array, return [-1, -1].
 *
 * Follow up: Could you write an algorithm with O(log n) runtime complexity?
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

// @lc code=start
class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result(2, -1);
    int         len  = nums.size();
    int         left = 0, right = len - 1;
    while (left <= right) {
      int middle = (right - left) / 2 + left;
      if (nums[middle] == target) {
        // find first and last index
        int l = middle - 1;
        int r = middle + 1;
        while (l >= 0 && nums[l] == target) {
          l--;
        }

        while (r < len && nums[r] == target) {
          r++;
        }
        result[0] = ++l;
        result[1] = --r;
        break;
      } else if (nums[middle] > target) {
        right = middle - 1;
      } else {
        left = middle + 1;
      }
    }

    return result;
  }
};
// @lc code=end
