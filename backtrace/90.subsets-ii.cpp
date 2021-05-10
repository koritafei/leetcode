/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (48.94%)
 * Likes:    2332
 * Dislikes: 102
 * Total Accepted:    330.5K
 * Total Submissions: 675.1K
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

// @lc code=start
class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    visited = vector<bool>(nums.size(), false);
    subsetsWithDup(nums, 0);
    return result;
  }

private:
  void subsetsWithDup(vector<int>& nums, int index) {
    result.push_back(path);

    for (int i = index; i < nums.size(); i++) {
      if (!visited[i]) {
        if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
          continue;
        }
        visited[i] = true;
        path.push_back(nums[i]);
        subsetsWithDup(nums, i + 1);
        path.pop_back();
        visited[i] = false;
      }
    }
  }

  vector<vector<int>> result;
  vector<int>         path;
  vector<bool>        visited;
};
// @lc code=end
