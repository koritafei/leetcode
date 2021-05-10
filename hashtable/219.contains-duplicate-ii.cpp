/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 *
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (38.67%)
 * Likes:    1247
 * Dislikes: 1355
 * Total Accepted:    322.6K
 * Total Submissions: 834.2K
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

// @lc code=start
class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    int                     len = nums.size();
    int                     ll  = std::min(len, k);
    for (int i = 0; i < ll; i++) {
      if (m.find(nums[i]) != m.end()) {
        return true;
      } else {
        m[nums[i]]++;
      }
    }

    int left = 0, right = k;
    while (right < len) {
      if (m.find(nums[right]) == m.end()) {
        m[nums[right++]]++;
      } else {
        return true;
      }
      m.erase(nums[left++]);
    }

    return false;
  }
};
// @lc code=end
