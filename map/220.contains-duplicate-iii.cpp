/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 *
 * https://leetcode.com/problems/contains-duplicate-iii/description/
 *
 * algorithms
 * Medium (21.54%)
 * Likes:    1985
 * Dislikes: 1992
 * Total Accepted:    187.9K
 * Total Submissions: 872.2K
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
 * 1 <= nums.length <= 2 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * 0 <= k <= 10^4
 * 0 <= t <= 2^31 - 1
 *
 *
 */

#include <cmath>
#include <set>
#include <vector>

// @lc code=start
class Solution {
public:
  bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t) {
    std::set<long long> set;

    for (int i = 0; i < nums.size(); i++) {
      if (i > k && i - k - 1 < nums.size()) {  // 保证集合中的元素大小在k
        set.erase(nums[i - k - 1]);
      }

      auto pos = set.lower_bound((long long)nums[i] - t);
      if (pos != set.end() && *pos - nums[i] <= t) {
        return true;
      }
      set.insert(nums[i]);
    }

    return false;
  }
};
// @lc code=end
