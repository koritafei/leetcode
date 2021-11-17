/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 *
 * https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
 *
 * algorithms
 * Medium (45.82%)
 * Likes:    4047
 * Dislikes: 235
 * Total Accepted:    170K
 * Total Submissions: 370.8K
 * Testcase Example:  '[4,3,2,3,5,2,1]\n4'
 *
 * Given an integer array nums and an integer k, return true if it is possible
 * to divide this array into k non-empty subsets whose sums are all equal.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [4,3,2,3,5,2,1], k = 4
 * Output: true
 * Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3),
 * (2,3) with equal sums.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,4], k = 3
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= nums.length <= 16
 * 1 <= nums[i] <= 10^4
 * The frequency of each element is in the range [1, 4].
 *
 *
 */

#include <algorithm>
#include <vector>

// @lc code=start
class Solution {
public:
  bool canPartitionKSubsets(std::vector<int> &nums, int k) {
    int len = nums.size();
    if (len < k) {
      return false;
    }

    std::sort(nums.begin(), nums.end(), [](int a, int b) {
      return a > b;
    });

    int sum = 0;
    for (auto iter : nums) {
      sum += iter;
    }
    if (sum % k != 0) {
      return false;  // 不能等分成k份
    }

    // 桶的集合
    std::vector<int> bucket = std::vector<int>(k, 0);
    // 每个桶中的和
    int target = sum / k;

    return backtrack(nums, nums.size(), 0, target, bucket);
  }

private:
  // 递归枚举nums中的每个数字
  bool backtrack(std::vector<int> &nums,
                 int               len,
                 int               index,
                 int               target,
                 std::vector<int> &bucket) {
    if (index == len) {
      // 数组遍历完成，判断每个bucket中值是否为target
      for (auto iter : bucket) {
        if (iter != target) {
          return false;
        }
      }

      return true;
    }

    // 遍历桶
    for (int i = 0; i < bucket.size(); i++) {
      // 桶装满了，continue
      if (nums[index] + bucket[i] > target) {
        continue;
      }

      // 放入桶中
      bucket[i] += nums[index];
      if (backtrack(nums, len, index + 1, target, bucket)) {
        return true;
      }
      // 回溯
      bucket[i] -= nums[index];
    }

    // nums[index]放入哪个桶中都不行
    return false;
  }
};
// @lc code=end
