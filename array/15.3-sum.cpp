/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (29.85%)
 * Likes:    14082
 * Dislikes: 1359
 * Total Accepted:    1.6M
 * Total Submissions: 5.3M
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
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::vector<std::vector<int>> res;
    threeSum(nums, res, 0);
    return res;
  }

private:
  void threeSum(std::vector<int> &             nums,
                std::vector<std::vector<int>> &res,
                int                            target) {
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
      int left = i + 1, right = nums.size() - 1;
      int t = target - nums[i];
      while (left < right) {
        int sum = nums[left] + nums[right];
        int t1 = nums[left], t2 = nums[right];
        if (sum == t) {
          std::vector<int> tmp;
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
        } else if (sum < t) {
          while (left < right && t1 == nums[left]) {
            left++;
          }
        } else {
          while (left < right && nums[right] == t2) {
            right--;
          }
        }
      }
      while (i + 1 < nums.size() - 1 && nums[i] == nums[i + 1]) {
        i++;
      }
    }
  }
};
// @lc code=end
