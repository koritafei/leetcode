/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 *
 * https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
 *
 * algorithms
 * Medium (45.90%)
 * Likes:    4130
 * Dislikes: 242
 * Total Accepted:    173.9K
 * Total Submissions: 378.7K
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

#include <vector>

// @lc code=start
class Solution {
public:
  bool canPartitionKSubsets(std::vector<int> &nums, int k) {
    int  len = nums.size();
    long sum = 0;

    std::sort(nums.begin(), nums.end(), [](int a, int b) {
      return a > b;
    });
    for (int i = 0; i < len; i++) {
      sum += nums[i];
    }

    if (sum % k != 0) {
      return false;
    }

    long target = sum / k;

    std::vector<int> bucket = std::vector<int>(k, 0);

    return canPartitionKSubsets(nums, len, 0, target, k, bucket);
  }

private:
  bool canPartitionKSubsets(std::vector<int> &nums,
                            int               len,
                            int               index,
                            long              target,
                            int               k,
                            std::vector<int> &bucket) {
    if (len == index) {
      for (auto it : bucket) {
        if (it != target) {
          return false;
        }
      }
      return true;
    }

    for (int i = 0; i < k; i++) {
      if (nums[index] + bucket[i] > target) {
        continue;
      }

      // 加入桶
      bucket[i] += nums[index];
      if (canPartitionKSubsets(nums, len, index + 1, target, k, bucket)) {
        return true;
      }

      // 撤销选择
      bucket[i] -= nums[index];
    }

    return false;
  }
};
// @lc code=end
