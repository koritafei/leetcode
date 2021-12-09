/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (30.08%)
 * Likes:    14659
 * Dislikes: 1404
 * Total Accepted:    1.6M
 * Total Submissions: 5.4M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an integer array nums, return all the triplets [nums[i], nums[j],
 * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
 * nums[k] == 0.
 *
 * Notice that the solution set must not contain duplicate triplets.
 *
 *
 * Example 1:
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Example 2:
 * Input: nums = []
 * Output: []
 * Example 3:
 * Input: nums = [0]
 * Output: []
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 *
 *
 */

#include <algorithm>
#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int                           len = nums.size();
    std::vector<std::vector<int>> res;

    int i = 0;
    while (i < len) {
      int target = -nums[i];
      int left = i + 1, right = len - 1;
      while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum < target) {
          // 跳过重复部分
          while (left + 1 < right && nums[left] == nums[left + 1]) {
            left++;
          }
          left++;
        } else if (sum > target) {
          while (right - 1 > left && nums[right] == nums[right - 1]) {
            right--;
          }
          right--;
        } else {
          res.push_back(std::vector<int>{nums[i], nums[left], nums[right]});
          while (right - 1 > left && nums[right] == nums[right - 1]) {
            right--;
          }
          while (left + 1 < right && nums[left] == nums[left + 1]) {
            left++;
          }
          left++;
          right--;
        }
      }

      // 跳过i重复的部分
      while (i + 1 < len && nums[i] == nums[i + 1]) {
        i++;
      }
      i++;
    }

    return res;
  }
};
// @lc code=end
