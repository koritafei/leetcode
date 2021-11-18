/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (69.91%)
 * Likes:    8056
 * Dislikes: 158
 * Total Accepted:    976.8K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an array nums of distinct integers, return all the possible
 * permutations. You can return the answer in any order.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * Example 2:
 * Input: nums = [0,1]
 * Output: [[0,1],[1,0]]
 * Example 3:
 * Input: nums = [1]
 * Output: [[1]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * All the integers of nums are unique.
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    int len = nums.size();
    visited = std::vector<bool>(len + 1, false);
    backtrace(nums, len);
    return res;
  }

private:
  void backtrace(std::vector<int>& nums, int len) {
    if (track.size() == len) {
      res.push_back(track);
      return;
    }

    for (int i = 0; i < len; i++) {
      // 是否已遍历过，如果已遍历过，继续循环
      if (visited[i]) {
        continue;
      }

      // 做选择
      visited[i] = true;
      track.push_back(nums[i]);
      backtrace(nums, len);
      // 撤销选择
      visited[i] = false;
      track.pop_back();
    }
  }

  std::vector<int>              track;    // 遍历路径
  std::vector<std::vector<int>> res;      // 遍历结果集
  std::vector<bool>             visited;  // 是否遍历过标记
};
// @lc code=end
