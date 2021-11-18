/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (68.47%)
 * Likes:    7530
 * Dislikes: 126
 * Total Accepted:    901.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array nums of unique elements, return all possible subsets
 * (the power set).
 *
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3]
 * Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0]
 * Output: [[],[0]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * All the numbers of nums are unique.
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    backtrace(nums, 0);

    return res;
  }

private:
  void backtrace(std::vector<int>& nums, int index) {
    res.push_back(subset);

    for (int i = index; i < nums.size(); i++) {
      // 做选择
      subset.push_back(nums[i]);
      backtrace(nums, i + 1);
      // 撤销选择
      subset.pop_back();
    }
  }

  std::vector<int>              subset;
  std::vector<std::vector<int>> res;
};
// @lc code=end
