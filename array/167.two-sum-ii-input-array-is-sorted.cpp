/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 *
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (55.70%)
 * Likes:    2434
 * Dislikes: 696
 * Total Accepted:    536.6K
 * Total Submissions: 963.3K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers numbers that is already sorted in ascending
 * order, find two numbers such that they add up to a specific target number.
 *
 * Return the indices of the two numbers (1-indexed) as an integer array answer
 * of size 2, where 1 <= answer[0] < answer[1] <= numbers.length.
 *
 * You may assume that each input would have exactly one solution and you may
 * not use the same element twice.
 *
 *
 * Example 1:
 *
 *
 * Input: numbers = [2,7,11,15], target = 9
 * Output: [1,2]
 * Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
 *
 *
 * Example 2:
 *
 *
 * Input: numbers = [2,3,4], target = 6
 * Output: [1,3]
 *
 *
 * Example 3:
 *
 *
 * Input: numbers = [-1,0], target = -1
 * Output: [1,2]
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= numbers.length <= 3 * 10^4
 * -1000 <= numbers[i] <= 1000
 * numbers is sorted in increasing order.
 * -1000 <= target <= 1000
 * Only one valid answer exists.
 *
 *
 */

#include <iostream>
#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    std::vector<int> res;
    int              len = numbers.size();
    if (len < 2) {
      return res;
    }

    int left = 0, right = len - 1;
    while (left < right) {
      int sum = numbers[left] + numbers[right];
      if (sum == target) {
        res.push_back(left + 1);
        res.push_back(right + 1);
        return res;
      } else if (sum < target) {
        left++;
      } else {
        right--;
      }
    }

    return res;
  }
};
// @lc code=end

int main(int argc, char** argv) {
  std::vector<int> nums   = {2, 7, 11, 15};
  int              target = 9;
  Solution         solution;

  auto res = solution.twoSum(nums, target);
  for (auto item : res) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}
