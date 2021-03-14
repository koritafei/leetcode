/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (49.53%)
 * Likes:    4979
 * Dislikes: 284
 * Total Accepted:    642.4K
 * Total Submissions: 1.3M
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array nums with n objects colored red, white, or blue, sort them
 * in-place so that objects of the same color are adjacent, with the colors in
 * the order red, white, and blue.
 *
 * We will use the integers 0, 1, and 2 to represent the color red, white, and
 * blue, respectively.
 *
 *
 * Example 1:
 * Input: nums = [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * Example 2:
 * Input: nums = [2,0,1]
 * Output: [0,1,2]
 * Example 3:
 * Input: nums = [0]
 * Output: [0]
 * Example 4:
 * Input: nums = [1]
 * Output: [1]
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= n <= 300
 * nums[i] is 0, 1, or 2.
 *
 *
 *
 * Follow up:
 *
 *
 * Could you solve this problem without using the library's sort function?
 * Could you come up with a one-pass algorithm using only O(1) constant space?
 *
 *
 */

#include <iostream>
#include <vector>

// @lc code=start
class Solution {
public:
  void sortColors(std::vector<int>& nums) {
    int len = nums.size();
    if (len < 1) {
      return;
    }
    int zero = -1;
    int two  = len;
    for (int i = 0; i < two;) {
      if (nums[i] == 1) {
        i++;
      } else if (nums[i] == 2) {
        std::swap(nums[i], nums[--two]);
      } else {
        std::swap(nums[i++], nums[++zero]);
      }
    }
  }
};
// @lc code=end

int main(int argc, char** argv) {
  std::vector<int> nums = {2, 0, 2, 1, 1, 0};
  Solution         solution;
  for (auto item : nums) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
  solution.sortColors(nums);
  for (auto item : nums) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}
