/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (52.15%)
 * Likes:    3953
 * Dislikes: 87
 * Total Accepted:    529.9K
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
      if (visited[i]) {
        continue;
      }

      if (i > 0 && !visited[i - 1] && nums[i] == nums[i - 1]) {
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

  std::vector<bool>             visited;
  std::vector<int>              track;  // 遍历路径
  std::vector<std::vector<int>> res;    // 结果集
};
// @lc code=end
