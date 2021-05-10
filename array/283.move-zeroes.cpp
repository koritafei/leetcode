/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (58.59%)
 * Likes:    5175
 * Dislikes: 162
 * Total Accepted:    1.1M
 * Total Submissions: 1.8M
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an integer array nums, move all 0's to the end of it while maintaining
 * the relative order of the non-zero elements.
 *
 * Note that you must do this in-place without making a copy of the array.
 *
 *
 * Example 1:
 * Input: nums = [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * Example 2:
 * Input: nums = [0]
 * Output: [0]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 *
 *
 *
 * Follow up: Could you minimize the total number of operations done?
 */

#include <iostream>
#include <vector>

// @lc code=start
class Solution {
public:
  void moveZeroes(std::vector<int>& nums) {
    int len = nums.size();
    if (len < 2) {
      return;
    }
    int k = 0;
    for (int i = 0; i < len; i++) {
      if (nums[i] != 0) {
        nums[k++] = nums[i];
      }
    }

    while (k < len) {
      nums[k++] = 0;
    }
  }
};
// @lc code=end

int main(int argc, char** argv) {
  std::vector<int> nums = {0, 1, 0, 3, 12};
  Solution         solution;
  for (auto item : nums) {
    std::cout << item << "";
  }
  std::cout << std::endl;
  solution.moveZeroes(nums);
  for (auto item : nums) {
    std::cout << item << "";
  }
  std::cout << std::endl;
}
