/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (46.25%)
 * Likes:    2968
 * Dislikes: 166
 * Total Accepted:    560.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-1,2,1,-4], target = 1
 * Output: 2
 * Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 =
 * 2).
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= nums.length <= 10^3
 * -10^3 <= nums[i] <= 10^3
 * -10^4 <= target <= 10^4
 *
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    int len = nums.size();
    int sum = 0;
    if (len < 3) {
      return sum;
    }

    int diff = INT32_MAX;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < len - 2; i++) {
      int left  = i + 1;
      int right = len - 1;
      while (left < right) {
        int closest = nums[left] + nums[right] + nums[i];
        int t       = abs(closest - target);
        if (diff > t) {
          diff = t;
          sum  = closest;
        } else if (t == 0) {
          return closest;
        }

        if (closest < target) {
          left++;
        }
        if (closest > target) {
          right--;
        }
      }

      while (i < len - 2 && nums[i] == nums[i + 1]) {
        i++;
      }
    }

    return sum;
  }
};
// @lc code=end

int main(int argc, char** argv) {
  Solution    solution;
  vector<int> nums   = {-1, 2, 1, -4};
  int         target = 1;
  std::cout << solution.threeSumClosest(nums, target) << std::endl;
}
