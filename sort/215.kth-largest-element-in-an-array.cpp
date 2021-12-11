/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (61.79%)
 * Likes:    7554
 * Dislikes: 426
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
    return findKthLargest(nums, left, right, k);
  }

private:
  int findKthLargest(std::vector<int>& nums, int left, int right, int k) {
    int p = partation(nums, left, right);
    if (p == k - 1) {
      return nums[p];
    } else if (p > k - 1) {
      return findKthLargest(nums, left, p - 1, k);
    } else {
      return findKthLargest(nums, p + 1, right, k);
    }
  }

  int partation(std::vector<int>& nums, int left, int right) {
    if (left >= right) {
      return left;
    }

    int key = nums[left];
    int low = left, hight = right + 1;
    while (low <= hight) {
      while (nums[++low] > key) {
        if (low >= right) {
          break;
        }
      }

      while (nums[--hight] < key) {
        if (hight <= left) {
          break;
        }
      }

      if (low >= hight) {
        break;
      }

      std::swap(nums[low], nums[hight]);
    }

    std::swap(nums[left], nums[hight]);

    return hight;
  }
};
// @lc code=end
