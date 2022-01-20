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
    int len = nums.size();
    rand(nums, len);
    quicksort(nums, 0, len - 1);
    return nums;
  }

private:
  // 将数组乱序， 保证快排的效率
  void rand(std::vector<int>& nums, int len) {
    for (int i = 0; i < len; i++) {
      int index = ::rand() % len;
      if (index > i) {
        std::swap(nums[i], nums[index]);
      }
    }
  }

  int partation(std::vector<int>& vec, int left, int right) {
    if (left >= right) {
      return left;
    }

    int key = vec[left];
    int low = left, high = right + 1;
    while (low <= high) {
      while (key > vec[++low]) {
        if (low >= right) {
          break;
        }
      }

      while (key < vec[--high]) {
        if (high <= left) {
          break;
        }
      }

      if (low >= high) {
        break;
      }

      std::swap(vec[low], vec[high]);
    }

    std::swap(vec[left], vec[high]);
    return high;
  }

  void quicksort(std::vector<int>& nums, int left, int right) {
    if (left >= right) {
      return;
    }

    int index = partation(nums, left, right);
    quicksort(nums, left, index - 1);
    quicksort(nums, index + 1, right);
  }
};
// @lc code=end
