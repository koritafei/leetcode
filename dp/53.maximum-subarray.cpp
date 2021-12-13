/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (49.17%)
 * Likes:    16683
 * Dislikes: 782
 * Total Accepted:    1.9M
 * Total Submissions: 3.9M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 *
 * A subarray is a contiguous part of an array.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1]
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [5,4,-1,7,8]
 * Output: 23
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 *
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution using the divide and conquer approach, which is more subtle.
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  int maxSubArray(std::vector<int>& nums) {
    int len = nums.size();
    if (len == 0) {
      return 0;
    }

    std::vector<int> dp = std::vector<int>(len + 1, 0);
    // base case
    dp[0] = nums[0];

    for (int i = 1; i < len; i++) {
      dp[i] = std::max(nums[i], dp[i - 1] + nums[i]);
    }

    int max = INT_MIN;

    for (int i = 0; i < len; i++) {
      max = max < dp[i] ? dp[i] : max;
    }

    return max;
  }
};
// @lc code=end
