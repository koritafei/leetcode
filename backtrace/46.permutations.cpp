/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (70.26%)
 * Likes:    8257
 * Dislikes: 160
 * Total Accepted:    996.9K
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

#include <algorithm>
#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    backtrace(nums, nums.size());
    return res;
  }

private:
  void backtrace(std::vector<int>& nums, int len) {
    // 满足终止条件
    if (path.size() == len) {
      res.push_back(path);
      return;
    }

    for (int i = 0; i < len; i++) {
      // 排除已经加入的元素
      if (std::find(path.begin(), path.end(), nums[i]) != path.end()) {
        continue;
      }

      // 做选择
      path.push_back(nums[i]);
      // 递归
      backtrace(nums, len);

      // 撤销选择
      path.pop_back();
    }
  }

  std::vector<int>              path;
  std::vector<std::vector<int>> res;
};
// @lc code=end
