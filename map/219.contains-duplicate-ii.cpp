/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 *
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (40.15%)
 * Likes:    1907
 * Dislikes: 1656
 * Total Accepted:    399.7K
 * Total Submissions: 995.1K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * Given an integer array nums and an integer k, return true if there are two
 * distinct indices i and j in the array such that nums[i] == nums[j] and abs(i
 * - j) <= k.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,2,3,1,2,3], k = 2
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 0 <= k <= 10^5
 *
 *
 */

#include <cmath>
#include <map>
#include <vector>

// @lc code=start
class Solution {
public:
  bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
    int                len = nums.size();
    std::map<int, int> freq;  // <val, index>
    for (int i = 0; i < len; i++) {
      if (freq.find(nums[i]) != freq.end()) {
        // 已经存在当前值
        int j = freq[nums[i]];
        if (abs(i - j) <= k) {
          return true;
        } else {
          freq[nums[i]] = i;
        }
      } else {
        freq[nums[i]] = i;
      }
    }

    return false;
  }
};
// @lc code=end
