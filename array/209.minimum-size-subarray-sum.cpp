/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (39.57%)
 * Likes:    3476
 * Dislikes: 138
 * Total Accepted:    340.4K
 * Total Submissions: 860K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * Given an array of positive integers nums and a positive integer target,
 * return the minimal length of a contiguous subarray [numsl, numsl+1, ...,
 * numsr-1, numsr] of which the sum is greater than or equal to target. If
 * there is no such subarray, return 0 instead.
 *
 *
 * Example 1:
 *
 *
 * Input: target = 7, nums = [2,3,1,2,4,3]
 * Output: 2
 * Explanation: The subarray [4,3] has the minimal length under the problem
 * constraint.
 *
 *
 * Example 2:
 *
 *
 * Input: target = 4, nums = [1,4,4]
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: target = 11, nums = [1,1,1,1,1,1,1,1]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= target <= 10^9
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 *
 *
 *
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution of which the time complexity is O(n log(n)).
 */

#include <iostream>
#include <vector>

// @lc code=start
class Solution {
public:
  int minSubArrayLen(int target, std::vector<int>& nums) {
    int len = nums.size();
    if (len < 1) {
      return len;
    }

    int min  = INT_MAX;
    int sum  = nums[0];
    int left = 0, right = 0;
    while (left < len && right < len) {
      if (sum < target && (++right) < len) {
        sum += nums[right];
      } else if (sum >= target) {
        min = std::min(min, right - left + 1);
        sum -= nums[left++];
      }
    }

    return min == INT_MAX ? 0 : min;
  }
};
// @lc code=end

int main(int argc, char** argv) {
  std::vector<int> nums   = {2, 3, 1, 2, 4, 3};
  int              target = 7;
  Solution         solution;
  std::cout << solution.minSubArrayLen(target, nums) << std::endl;
  nums   = {1, 4, 4};
  target = 4;
  std::cout << solution.minSubArrayLen(target, nums) << std::endl;
  nums   = {1, 1, 1, 1, 1, 1, 1, 1};
  target = 11;
  std::cout << solution.minSubArrayLen(target, nums) << std::endl;
  nums   = {1, 2, 3, 4, 5};
  target = 11;
  std::cout << solution.minSubArrayLen(target, nums) << std::endl;
}
