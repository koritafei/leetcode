/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 *
 * https://leetcode.com/problems/contains-duplicate-iii/description/
 *
 * algorithms
 * Medium (21.34%)
 * Likes:    1529
 * Dislikes: 1616
 * Total Accepted:    166.9K
 * Total Submissions: 781.9K
 * Testcase Example:  '[1,2,3,1]\n3\n0'
 *
 * Given an integer array nums and two integers k and t, return true if there
 * are two distinct indices i and j in the array such that abs(nums[i] -
 * nums[j]) <= t and abs(i - j) <= k.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3,1], k = 3, t = 0
 * Output: true
 * Example 2:
 * Input: nums = [1,0,1,1], k = 1, t = 2
 * Output: true
 * Example 3:
 * Input: nums = [1,5,9,1,5,9], k = 2, t = 3
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 2 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * 0 <= k <= 10^4
 * 0 <= t <= 2^31 - 1
 *
 *
 */

// @lc code=start
class Solution {
public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if (nums.size() < 2 || k == 0) return false;
    set<long> windows;
    int       l = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i - l > k) {
        windows.erase(nums[l++]);
      }
      auto it = windows.lower_bound((long)nums[i] - (long)t);
      if (it != windows.end() && *it <= ((long)nums[i] + (long)t)) return true;
      windows.insert(nums[i]);  // not found
    }
    return false;
  }
};
// @lc code=end
