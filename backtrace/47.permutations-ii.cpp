/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (52.47%)
 * Likes:    4069
 * Dislikes: 87
 * Total Accepted:    538.9K
 * Total Submissions: 1M
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers, nums, that might contain duplicates, return
 * all possible unique permutations in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,2]
 * Output:
 * [[1,1,2],
 * ⁠[1,2,1],
 * ⁠[2,1,1]]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3]
 * Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 8
 * -10 <= nums[i] <= 10
 *
 *
 */

#include <algorithm>
#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int len = nums.size();
    visited = std::vector<bool>(len, false);

    backtrace(nums, len);

    return res;
  }

private:
  void backtrace(std::vector<int>& nums, int len) {
    if (path.size() == len) {
      res.push_back(path);
      return;
    }

    for (int i = 0; i < len; i++) {
      // 去重
      if ((i > 0 && visited[i - 1] == false && nums[i - 1] == nums[i]) ||
          (visited[i])) {
        continue;
      }

      // 做选择
      path.push_back(nums[i]);
      visited[i] = true;
      backtrace(nums, len);
      // 撤销选择
      path.pop_back();
      visited[i] = false;
    }
  }

  std::vector<int>              path;
  std::vector<std::vector<int>> res;
  std::vector<bool>             visited;
};
// @lc code=end
