/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (36.69%)
 * Likes:    4737
 * Dislikes: 562
 * Total Accepted:    500.3K
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

    fourSum(nums, res, target);
    return res;
  }

private:
  void fourSum(std::vector<int>&              nums,
               std::vector<std::vector<int>>& res,
               int                            target) {
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++) {
      int t = target - nums[i];
      for (int j = i + 1; j < nums.size(); j++) {
        int a    = t - nums[j];
        int left = j + 1, right = nums.size() - 1;
        while (left < right) {
          int sum = nums[left] + nums[right];
          int t1 = nums[left], t2 = nums[right];
          if (sum == a) {
            std::vector<int> tmp;
            tmp.push_back(nums[j]);
            tmp.push_back(nums[i]);
            tmp.push_back(nums[left]);
            tmp.push_back(nums[right]);
            res.push_back(tmp);

            while (left < right && nums[left] == t1) {
              left++;
            }

            while (left < right && t2 == nums[right]) {
              right--;
            }
          } else if (sum < a) {
            while (left < right && t1 == nums[left]) {
              left++;
            }
          } else {
            while (left < right && nums[right] == t2) {
              right--;
            }
          }
        }

        while (j + 1 < nums.size() - 1 && nums[j] == nums[j + 1]) {
          j++;
        }
      }
      while (i + 1 < nums.size() - 2 && nums[i] == nums[i + 1]) {
        i++;
      }
    }
  }
};
// @lc code=end
