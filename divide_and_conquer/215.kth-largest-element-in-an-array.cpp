/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (58.57%)
 * Likes:    5269
 * Dislikes: 339
 * Total Accepted:    847.8K
 * Total Submissions: 1.4M
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

#include <iostream>
#include <vector>

// @lc code=start
class Solution {
public:
  int findKthLargest(std::vector<int>& nums, int k) {
    // print(nums);
    return findKthLargest(nums, k, 0, nums.size() - 1);
  }

private:
  int findKthLargest(std::vector<int>& nums, int k, int left, int right) {
    int start = left;
    int end   = right;
    int key   = nums[left];
    while (left < right) {
      while (left < right && nums[right] <= key) {
        right--;
      }
      if (left < right) {
        std::swap(nums[left++], nums[right]);
      }

      while (left < right && nums[left] > key) {
        left++;
      }
      if (left < right) {
        std::swap(nums[left], nums[right--]);
      }
    }
    nums[left] = key;
    // print(nums);
    if (right == (k - 1)) {
      return nums[right];
    } else if (right < k) {
      return findKthLargest(nums, k, left + 1, end);
    } else {
      return findKthLargest(nums, k, start, left);
    }
    return -1;
  }

  void print(std::vector<int>& nums) {
    for (auto item : nums) {
      std::cout << item << " ";
    }

    std::cout << std::endl;
  }
};
// @lc code=end

int main(int argc, char** argv) {
  std::vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  int              k    = 1;
  Solution         solution;
  std::cout << solution.findKthLargest(nums, k) << std::endl;
}
