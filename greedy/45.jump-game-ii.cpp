/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Medium (35.11%)
 * Likes:    6288
 * Dislikes: 239
 * Total Accepted:    477.2K
 * Total Submissions: 1.4M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers nums, you are initially positioned
 * at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that
 * position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * You can assume that you can always reach the last index.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2. Jump
 * 1 step from index 0 to 1, then 3 steps to the last index.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,3,0,1,4]
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * 0 <= nums[i] <= 1000
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  int jump(std::vector<int>& nums) {
    int len = nums.size();
    int end = 0, fastest = 0;
    int jumps = 0;

    for (int i = 0; i < len - 1; i++) {
      fastest = std::max(fastest, i + nums[i]);
      if (end == i) {
        end = fastest;
        jumps++;
      }
    }

    return jumps;
  }
};
// @lc code=end
