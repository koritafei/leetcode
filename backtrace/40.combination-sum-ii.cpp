/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (50.22%)
 * Likes:    2553
 * Dislikes: 86
 * Total Accepted:    393.6K
 * Total Submissions: 783.4K
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

// @lc code=start
class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    visited = vector<bool>(candidates.size(), false);
    combinationSum(candidates, target, 0);
    return res;
  }

private:
  void combinationSum(vector<int>& candidates, int target, int index) {
    if (target == 0) {
      res.push_back(path);
      return;
    }

    for (int i = index; i < candidates.size(); i++) {
      if (!visited[i] && candidates[i] <= target) {
        if (i > 0 && candidates[i] == candidates[i - 1] && !visited[i - 1]) {
          continue;
        }
        visited[i] = true;
        path.push_back(candidates[i]);
        combinationSum(candidates, target - candidates[i], i + 1);
        path.pop_back();
        visited[i] = false;
      }
    }
  }

  vector<vector<int>> res;
  vector<int>         path;
  vector<bool>        visited;
};
// @lc code=end
