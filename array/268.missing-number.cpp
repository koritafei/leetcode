/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (57.69%)
 * Likes:    4160
 * Dislikes: 2710
 * Total Accepted:    816.8K
 * Total Submissions: 1.4M
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array nums containing n distinct numbers in the range [0, n],
 * return the only number in the range that is missing from the array.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [3,0,1]
 * Output: 2
 * Explanation: n = 3 since there are 3 numbers, so all numbers are in the
 * range [0,3]. 2 is the missing number in the range since it does not appear
 * in nums.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,1]
 * Output: 2
 * Explanation: n = 2 since there are 2 numbers, so all numbers are in the
 * range [0,2]. 2 is the missing number in the range since it does not appear
 * in nums.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * Explanation: n = 9 since there are 9 numbers, so all numbers are in the
 * range [0,9]. 8 is the missing number in the range since it does not appear
 * in nums.
 *
 *
 * Example 4:
 *
 *
 * Input: nums = [0]
 * Output: 1
 * Explanation: n = 1 since there is 1 number, so all numbers are in the range
 * [0,1]. 1 is the missing number in the range since it does not appear in
 * nums.
 *
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= n <= 10^4
 * 0 <= nums[i] <= n
 * All the numbers of nums are unique.
 *
 *
 *
 * Follow up: Could you implement a solution using only O(1) extra space
 * complexity and O(n) runtime complexity?
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  int missingNumber(std::vector<int>& nums) {
    int len = nums.size();
    int res = 0;
    res ^= len;

    for (int i = 0; i < len; i++) {
      res ^= i ^ nums[i];
    }

    return res;
  }
};
// @lc code=end