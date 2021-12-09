/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (36.78%)
 * Likes:    4933
 * Dislikes: 593
 * Total Accepted:    511.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers, return an array of all the unique
 * quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 *
 *
 * 0 <= a, b, c, d < n
 * a, b, c, and d are distinct.
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 *
 *
 * You may return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,0,-1,0,-2,2], target = 0
 * Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,2,2,2,2], target = 8
 * Output: [[2,2,2,2]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 200
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 *
 *
 */

#include <algorithm>
#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int>> res;
    int                           len = nums.size();

    for (int i = 0; i < len;) {
      int tmp1 = target - nums[i];
      for (int j = i + 1; j < len;) {
        int tmp2 = tmp1 - nums[j];

        int left = j + 1, right = len - 1;
        while (left < right) {
          int sum = nums[left] + nums[right];
          if (sum < tmp2) {
            while (left + 1 < right && nums[left + 1] == nums[left]) {
              left++;
            }
            left++;
          } else if (sum > tmp2) {
            while (right - 1 > left && nums[right - 1] == nums[right]) {
              right--;
            }
            right--;
          } else {
            res.push_back(
                std::vector<int>{nums[i], nums[j], nums[left], nums[right]});
            while (right - 1 > left && nums[right - 1] == nums[right]) {
              right--;
            }
            right--;
            while (left + 1 < right && nums[left + 1] == nums[left]) {
              left++;
            }
            left++;
          }
        }

        while (j + 1 < len && nums[j] == nums[j + 1]) {
          j++;
        }
        j++;
      }

      while (i + 1 < len && nums[i] == nums[i + 1]) {
        i++;
      }
      i++;
    }

    return res;
  }
};
// @lc code=end
