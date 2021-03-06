/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (46.21%)
 * Likes:    19717
 * Dislikes: 692
 * Total Accepted:    4M
 * Total Submissions: 8.5M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers nums and an integer target, return indices of the
 * two numbers such that they add up to target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 * You can return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Output: Because nums[0] + nums[1] == 9, we return [0, 1].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 10^3
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * Only one valid answer exists.
 *
 *
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int         len = nums.size();
    vector<int> res;
    if (len < 2) {
      return res;
    }

    std::map<int, int> m;

    for (int i = 0; i < len; i++) {
      int sub = target - nums[i];
      if (m.find(sub) != m.end()) {
        res.push_back(m[sub]);
        res.push_back(i);
        return res;
      } else {
        m[nums[i]] = i;
      }
    }

    return res;
  }
};
// @lc code=end

int main(int argc, char** argv) {
  Solution    solution;
  vector<int> in     = {2, 7, 11, 15};
  int         target = 9;
  auto        res    = solution.twoSum(in, target);
  for (auto item : res) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}
