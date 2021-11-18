/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (61.37%)
 * Likes:    7374
 * Dislikes: 418
 * Total Accepted:    1.1M
 * Total Submissions: 1.8M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Given an integer array nums and an integer k, return the k^th largest
 * element in the array.
 *
 * Note that it is the k^th largest element in the sorted order, not the k^th
 * distinct element.
 *
 *
 * Example 1:
 * Input: nums = [3,2,1,5,6,4], k = 2
 * Output: 5
 * Example 2:
 * Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
 * Output: 4
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  int findKthLargest(std::vector<int>& nums, int k) {
    int left = 0, right = nums.size() - 1;
    k--;
    while (left <= right) {
      int p = partation(nums, left, right);
      if (k == p) {
        return nums[p];
      } else if (p < k) {
        left = p + 1;
      } else {
        right = p - 1;
      }
    }

    return -1;
  }

private:
  int partation(std::vector<int>& nums, int left, int right) {
    if (left == right) {
      return left;
    }

    int key = nums[left];
    int low = left, high = right + 1;

    while (true) {
      while (nums[++low] > key) {
        if (low == right) {
          break;
        }
      }

      while (nums[--high] < key) {
        if (high == left) {
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
};
// @lc code=end
