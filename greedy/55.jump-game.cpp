/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (36.79%)
 * Likes:    8741
 * Dislikes: 517
 * Total Accepted:    812.6K
 * Total Submissions: 2.2M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * You are given an integer array nums. You are initially positioned at the
 * array's first index, and each element in the array represents your maximum
 * jump length at that position.
 *
 * Return true if you can reach the last index, or false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its maximum
 * jump length is 0, which makes it impossible to reach the last index.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 10^5
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  bool canJump(std::vector<int>& nums) {
    int len = nums.size();
    if (1 >= len) {
      return true;
    }

    int fastest = 0;
    for (int i = 0; i < len; i++) {
      if (fastest < i) {  // 遇到0，无法向前
        return false;
      }
      fastest = std::max(fastest, i + nums[i]);
    }

    return true;
  }
};
// @lc code=end
