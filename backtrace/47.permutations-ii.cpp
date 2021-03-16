/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (49.53%)
 * Likes:    2811
 * Dislikes: 78
 * Total Accepted:    439.2K
 * Total Submissions: 886.2K
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

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    visited = vector<bool>(nums.size() + 1, false);
    sort(nums.begin(), nums.end());
    permuteUnique(nums, 0);
    return result;
  }

private:
  void permuteUnique(vector<int>& nums, int index) {
    if (index == nums.size()) {
      result.push_back(path);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (!visited[i]) {
        if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
          continue;
        }
        path.push_back(nums[i]);
        visited[i] = true;
        permuteUnique(nums, index + 1);
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

int main(int argc, char** argv) {
  Solution         solution;
  std::vector<int> nums = {1, 2, 2, 3};
  auto             res  = solution.permuteUnique(nums);
  for (auto item : res) {
    for (auto i : item) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
