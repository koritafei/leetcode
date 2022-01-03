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

#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
    int len = nums.size();
    visited = std::vector<bool>(len, false);
    std::sort(nums.begin(), nums.end());

    backtrace(nums, 0, len);

    return res;
  }

private:
  void backtrace(std::vector<int>& nums, int index, int len) {
    if (index == len) {
      res.push_back(path);
      return;
    }

    for (int i = 0; i < len; i++) {
      if (visited[i]) {
        continue;
      }

      if (i > 0 && !visited[i - 1] && nums[i] == nums[i - 1]) {
        continue;
      }

      visited[i] = true;
      path.push_back(nums[i]);
      backtrace(nums, index + 1, len);
      visited[i] = false;
      path.pop_back();
    }
  }

  std::vector<bool>             visited;
  std::vector<int>              path;
  std::vector<std::vector<int>> res;
};
// @lc code=end
