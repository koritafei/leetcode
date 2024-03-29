/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (41.80%)
 * Likes:    5196
 * Dislikes: 161
 * Total Accepted:    438.1K
 * Total Submissions: 1M
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

#include <climits>
#include <vector>

// @lc code=start
class Solution {
public:
  int minSubArrayLen(int target, std::vector<int>& nums) {
    int left = 0, right = 0;
    int len    = nums.size();
    int sum    = 0;
    int minlen = INT_MAX;

    while (right < len) {
      sum += nums[right++];
      while (sum >= target) {
        minlen = minlen > (right - left) ? right - left : minlen;
        sum -= nums[left++];
      }
    }

    return minlen == INT_MAX ? 0 : minlen;
  }
};
// @lc code=end
