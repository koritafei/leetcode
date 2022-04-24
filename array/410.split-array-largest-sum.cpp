/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 *
 * https://leetcode.com/problems/split-array-largest-sum/description/
 *
 * algorithms
 * Hard (48.74%)
 * Likes:    3736
 * Dislikes: 118
 * Total Accepted:    150.4K
 * Total Submissions: 308.5K
 * Testcase Example:  '[7,2,5,10,8]\n2'
 *
 * Given an array nums which consists of non-negative integers and an integer
 * m, you can split the array into m non-empty continuous subarrays.
 *
 * Write an algorithm to minimize the largest sum among these m subarrays.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [7,2,5,10,8], m = 2
 * Output: 18
 * Explanation:
 * There are four ways to split nums into two subarrays.
 * The best way is to split it into [7,2,5] and [10,8],
 * where the largest sum among the two subarrays is only 18.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,4,5], m = 2
 * Output: 9
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,4,4], m = 3
 * Output: 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 10^6
 * 1 <= m <= min(50, nums.length)
 *
 *
 */

#include <climits>
#include <vector>

// @lc code=start
class Solution {
public:
  int splitArray(std::vector<int>& nums, int m) {
    int left = getMax(nums), right = getSum(nums);

    while (left <= right) {
      int mid = left + (right - left) / 2;
      int n   = split(nums, mid);
      if (n == m) {
        // 收缩右边界达到搜索左边界的目的
        right = mid - 1;
      } else if (n < m) {
        // 最大上限和较大收缩右边界
        right = mid - 1;
      } else {
        // 最大下限和较小，收缩左边界
        left = mid + 1;
      }
    }
    return left;
  }

private:
  int getMax(std::vector<int>& nums) {
    int max = INT_MIN;
    for (auto item : nums) {
      max = (max > item ? max : item);
    }

    return max;
  }

  int getSum(std::vector<int>& nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
    }

    return sum;
  }

  // 当最大子数组和为sum， 最多可以分为多少组
  int split(std::vector<int>& nums, int sum) {
    int count = 1;
    int s     = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (s + nums[i] > sum) {
        count++;
        s = nums[i];
      } else {
        s += nums[i];
      }
    }
    return count;
  }
};
// @lc code=end
