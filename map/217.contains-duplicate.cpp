/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (59.30%)
 * Likes:    3103
 * Dislikes: 901
 * Total Accepted:    1.1M
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,2,3,1]'
 *
 * Given an integer array nums, return true if any value appears at least twice
 * in the array, and return false if every element is distinct.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3,1]
 * Output: true
 * Example 2:
 * Input: nums = [1,2,3,4]
 * Output: false
 * Example 3:
 * Input: nums = [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */

#include <set>
#include <vector>

// @lc code=start
class Solution {
public:
  bool containsDuplicate(std::vector<int>& nums) {
    std::set<int> freq;
    int           len = nums.size();
    for (int i = 0; i < len; i++) {
      if (freq.find(nums[i]) != freq.end()) {
        return true;
      } else {
        freq.insert(nums[i]);
      }
    }

    return false;
  }
};
// @lc code=end
