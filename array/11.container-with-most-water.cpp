/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (52.82%)
 * Likes:    8846
 * Dislikes: 684
 * Total Accepted:    893.1K
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which,
 * together with the x-axis forms a container, such that the container contains
 * the most water.
 *
 * Notice that you may not slant the container.
 *
 *
 * Example 1:
 *
 *
 * Input: height = [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * Explanation: The above vertical lines are represented by array
 * [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the
 * container can contain is 49.
 *
 *
 * Example 2:
 *
 *
 * Input: height = [1,1]
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: height = [4,3,2,1,4]
 * Output: 16
 *
 *
 * Example 4:
 *
 *
 * Input: height = [1,2,1]
 * Output: 2
 *
 *
 *
 * Constraints:
 *
 *
 * n == height.length
 * 2 <= n <= 10^5
 * 0 <= height[i] <= 10^4
 *
 *
 */

#include <iostream>
#include <vector>

// @lc code=start
class Solution {
public:
  int maxArea(std::vector<int>& height) {
    int len     = height.size();
    int maxArea = 0;
    int h       = 0;
    int i = 0, j = len - 1;

    while (i < j) {
      h       = std::min(height[i], height[j]);
      maxArea = std::max(maxArea, (j - i) * h);
      while (height[i] <= h && i < j) {
        i++;
      }
      while (height[j] <= h && i < j) {
        j--;
      }
    }

    return maxArea;
  }
};
// @lc code=end

int main(int argc, char** argv) {
  Solution         solution;
  std::vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  std::cout << solution.maxArea(nums) << std::endl;  // 49
  nums = {1, 1};
  std::cout << solution.maxArea(nums) << std::endl;  // 1
  nums = {4, 3, 2, 1, 4};
  std::cout << solution.maxArea(nums) << std::endl;  // 16
  nums = {1, 2, 1};
  std::cout << solution.maxArea(nums) << std::endl;  // 2
}