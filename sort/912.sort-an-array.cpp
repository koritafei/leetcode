/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 *
 * https://leetcode.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (62.31%)
 * Likes:    1603
 * Dislikes: 470
 * Total Accepted:    217.5K
 * Total Submissions: 349.2K
 * Testcase Example:  '[5,2,3,1]'
 *
 * Given an array of integers nums, sort the array in ascending order.
 *
 *
 * Example 1:
 * Input: nums = [5,2,3,1]
 * Output: [1,2,3,5]
 * Example 2:
 * Input: nums = [5,1,1,2,0,0]
 * Output: [0,0,1,1,2,5]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 5 * 10^4
 * -5 * 10^4 <= nums[i] <= 5 * 10^4
 *
 *
 */

#include <cmath>
#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<int> sortArray(std::vector<int>& nums) {
    rand(nums, 0, nums.size() - 1);
    quickSort(nums, 0, nums.size() - 1);
    return nums;
  }

private:
  void quickSort(std::vector<int>& nums, int left, int right) {
    if (left >= right) {
      return;
    }

    int pos = partation(nums, left, right);
    quickSort(nums, left, pos - 1);
    quickSort(nums, pos + 1, right);
  }

  int partation(std::vector<int>& nums, int left, int right) {
    if (left >= right) {
      return left;
    }

    int key = nums[left];
    int low = left, high = right + 1;
    while (low < high) {
      while (nums[++low] < key) {
        if (low >= right) {
          break;
        }
      }

      while (nums[--high] > key) {
        if (high <= left) {
          break;
        }
      }

      if (low >= high) {
        break;
      }

      std::swap(nums[low], nums[high]);
    }

    std::swap(nums[left], nums[high]);

    return high;
  }

  void rand(std::vector<int>& nums, int left, int right) {
    int count = right - left;
    while (count--) {
      int index = ::rand() % nums.size();
      if (index >= left && index <= right) {
        std::swap(nums[left], nums[index]);
      }
    }
  }
};
// @lc code=end
