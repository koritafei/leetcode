/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (66.75%)
 * Likes:    5588
 * Dislikes: 129
 * Total Accepted:    775.3K
 * Total Submissions: 1.2M
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

// @lc code=start
class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    int len = nums.size();
    visited = vector<bool>(len + 1, false);
    permute(nums, 0);
    return result;
  }

private:
  void permute(vector<int>& nums, int index) {
    if (index == nums.size()) {
      result.push_back(path);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (visited[i] == false) {
        path.push_back(nums[i]);
        visited[i] = true;
        permute(nums, index + 1);
        path.pop_back();
        visited[i] = false;
      }
    }

    return;
  }

  vector<vector<int>> result;
  vector<int>         path;
  vector<bool>        visited;
};
// @lc code=end
