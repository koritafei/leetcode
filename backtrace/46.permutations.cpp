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

#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    int len = nums.size();
    visited = std::vector<bool>(len, false);

    backtrace(nums, len, 0);

    return res;
  }

private:
  void backtrace(std::vector<int>& nums, int len, int index) {
    if (len == index) {
      res.push_back(path);
      return;
    }

    for (int i = 0; i < len; i++) {
      if (!visited[i]) {
        visited[i] = true;
        path.push_back(nums[i]);
        backtrace(nums, len, index + 1);
        path.pop_back();
        visited[i] = false;
      }
    }
  }

  std::vector<std::vector<int>> res;
  std::vector<int>              path;
  std::vector<bool>             visited;
};
// @lc code=end
