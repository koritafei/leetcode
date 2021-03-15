/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (65.27%)
 * Likes:    5391
 * Dislikes: 109
 * Total Accepted:    733.8K
 * Total Submissions: 1.1M
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

// @lc code=start
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    visited = vector<bool>(nums.size(), false);
    subsets(nums, 0);
    return result;
  }

private:
  void subsets(vector<int>& nums, int index) {
    result.push_back(path);

    for (int i = index; i < nums.size(); i++) {
      if (!visited[i]) {
        path.push_back(nums[i]);
        visited[i] = true;
        subsets(nums, i + 1);
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
