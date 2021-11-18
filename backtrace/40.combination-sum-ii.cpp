/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (51.55%)
 * Likes:    3895
 * Dislikes: 105
 * Total Accepted:    475.8K
 * Total Submissions: 921.9K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sum to target.
 *
 * Each number in candidates may only be used once in the combination.
 *
 * Note: The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * Output:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,5,2,1,2], target = 5
 * Output:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 *
 *
 */

#include <algorithm>
#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates,
                                                int               target) {
    std::sort(candidates.begin(), candidates.end());
    sum = 0;
    backtrace(candidates, 0, target, sum);
    return res;
  }

private:
  void backtrace(std::vector<int> &nums, int index, int target, int &sum) {
    if (target < sum) {
      return;
    }

    if (target == sum) {
      res.push_back(subset);
      return;
    }

    for (int i = index; i < nums.size(); i++) {
      // 去重
      if (i > index && nums[i] == nums[i - 1]) {
        continue;
      }

      if (sum + nums[i] > target) {
        // 当前和大于target, 不做处理
        continue;
      } else {
        // 加入结果集
        sum += nums[i];
        // 做选择
        subset.push_back(nums[i]);
        backtrace(nums, i + 1, target, sum);

        // 撤销选择
        sum -= nums[i];
        subset.pop_back();
      }
    }
  }

  std::vector<int>              subset;  // 走过的路径
  int                           sum;     // 路径中所有元素之和
  std::vector<std::vector<int>> res;     // 结果集
};
// @lc code=end
