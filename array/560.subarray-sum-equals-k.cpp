/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (43.70%)
 * Likes:    9693
 * Dislikes: 319
 * Total Accepted:    602.2K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers nums and an integer k, return the total number of
 * continuous subarrays whose sum equals to k.
 *
 *
 * Example 1:
 * Input: nums = [1,1,1], k = 2
 * Output: 2
 * Example 2:
 * Input: nums = [1,2,3], k = 3
 * Output: 2
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 2 * 10^4
 * -1000 <= nums[i] <= 1000
 * -10^7 <= k <= 10^7
 *
 *
 */

#include <map>
#include <vector>

// @lc code=start
class Solution {
public:
  int subarraySum(std::vector<int>& nums, int k) {
    int                len = nums.size();
    std::map<int, int> prenums;
    prenums[0] = 1;
    int ans    = 0;
    int sum_i  = 0;
    int sum_j  = 0;
    for (int i = 0; i < len; i++) {
      sum_i += nums[i];
      sum_j = sum_i - k;
      if (prenums.count(sum_j)) {
        ans += prenums[sum_j];
      }
      prenums[sum_i]++;
    }

    return ans;
  }
};
// @lc code=end
