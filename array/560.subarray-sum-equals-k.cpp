/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (43.77%)
 * Likes:    10033
 * Dislikes: 332
 * Total Accepted:    623.7K
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
    int len = nums.size();
    if (0 == len) {
      return 0;
    }

    std::map<int, int> map;
    map[0]  = 1;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < len; i++) {
      sum += nums[i];
      if (map.find(sum - k) != map.end()) {
        ans += map[sum - k];
      }
      map[sum]++;
    }

    return ans;
  }
};
// @lc code=end
