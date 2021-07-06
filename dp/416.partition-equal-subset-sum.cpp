/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (45.25%)
 * Likes:    4762
 * Dislikes: 94
 * Total Accepted:    302.8K
 * Total Submissions: 669.1K
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array nums containing only positive integers, find if the
 * array can be partitioned into two subsets such that the sum of elements in
 * both subsets is equal.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,5,11,5]
 * Output: true
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,5]
 * Output: false
 * Explanation: The array cannot be partitioned into equal sum subsets.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= 100
 *
 *
 */

#include <iostream>
#include <vector>

// @lc code=start
class Solution {
public:
  bool canPartition(std::vector<int>& nums) {
    int len = nums.size();
    int sum = 0;

    for (auto item : nums) {
      sum += item;
    }

    if (0 != sum % 2) {
      return false;
    }

    sum /= 2;

    std::vector<std::vector<bool>> dp =
        std::vector<std::vector<bool>>(len + 1,
                                       std::vector<bool>(sum + 1, false));
    for (int i = 0; i <= len; i++) {
      dp[i][0] = true;
    }

    for (int i = 1; i <= len; i++) {
      for (int j = 1; j <= sum; j++) {
        if (j - nums[i - 1] < 0) {
          dp[i][j] = dp[i - 1][j];
        } else {
          // 载入或不载入
          dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i - 1]];
        }
      }
    }

    return dp[len][sum];
  }
};
// @lc code=end

int main(int argc, char** argv) {
  Solution         solution;
  std::vector<int> nums = {1, 5, 11, 5};
  std::cout << solution.canPartition(nums) << std::endl;
  nums = {1, 2, 3, 5};
  std::cout << solution.canPartition(nums) << std::endl;
}
