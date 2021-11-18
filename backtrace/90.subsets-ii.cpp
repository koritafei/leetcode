/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (51.47%)
 * Likes:    3779
 * Dislikes: 128
 * Total Accepted:    427.4K
 * Total Submissions: 828.3K
 * Testcase Example:  '[1,2,2]'
 *
 * Given an integer array nums that may contain duplicates, return all possible
 * subsets (the power set).
 *
 * The solution set must not contain duplicate subsets. Return the solution in
 * any order.
 *
 *
 * Example 1:
 * Input: nums = [1,2,2]
 * Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 * Example 2:
 * Input: nums = [0]
 * Output: [[],[0]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 *
 *
 */

#include <algorithm>
#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    backtrack(nums, 0);
    return res;
  }

private:
  void backtrack(std::vector<int>& nums, int index) {
    res.push_back(subset);

    for (int i = index; i < nums.size(); i++) {
      // 跳过重复元素
      if (i > index && nums[i] == nums[i - 1]) {
        continue;
      }
      subset.push_back(nums[i]);  // 做选择
      backtrack(nums, i + 1);
      subset.pop_back();  // 撤销选择
    }
  }

  std::vector<int>              subset;  // 记录走过的路
  std::vector<std::vector<int>> res;     // 记录结果
};
// @lc code=end
