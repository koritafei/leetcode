/*
 * @lc app=leetcode id=659 lang=cpp
 *
 * [659] Split Array into Consecutive Subsequences
 *
 * https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/
 *
 * algorithms
 * Medium (45.03%)
 * Likes:    1887
 * Dislikes: 519
 * Total Accepted:    63.6K
 * Total Submissions: 141.1K
 * Testcase Example:  '[1,2,3,3,4,5]'
 *
 * You are given an integer array nums that is sorted in non-decreasing order.
 *
 * Determine if it is possible to split nums into one or more subsequences such
 * that both of the following conditions are true:
 *
 *
 * Each subsequence is a consecutive increasing sequence (i.e. each integer is
 * exactly one more than the previous integer).
 * All subsequences have a length of 3 or more.
 *
 *
 * Return true if you can split nums according to the above conditions, or
 * false otherwise.
 *
 * A subsequence of an array is a new array that is formed from the original
 * array by deleting some (can be none) of the elements without disturbing the
 * relative positions of the remaining elements. (i.e., [1,3,5] is a
 * subsequence of [1,2,3,4,5] while [1,3,2] is not).
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,3,4,5]
 * Output: true
 * Explanation: nums can be split into the following subsequences:
 * [1,2,3,3,4,5] --> 1, 2, 3
 * [1,2,3,3,4,5] --> 3, 4, 5
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,3,4,4,5,5]
 * Output: true
 * Explanation: nums can be split into the following subsequences:
 * [1,2,3,3,4,4,5,5] --> 1, 2, 3, 4, 5
 * [1,2,3,3,4,4,5,5] --> 3, 4, 5
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,2,3,4,4,5]
 * Output: false
 * Explanation: It is impossible to split nums into consecutive increasing
 * subsequences of length 3 or more.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^4
 * -1000 <= nums[i] <= 1000
 * nums is sorted in non-decreasing order.
 *
 *
 */

#include <unordered_map>
#include <vector>

// @lc code=start
class Solution {
public:
  bool isPossible(std::vector<int>& nums) {
    std::unordered_map<int, int> freq;
    std::unordered_map<int, int> need;

    // 统计元素出现频率
    for (auto item : nums) {
      freq[item]++;
    }

    for (auto v : nums) {
      if (0 == freq[v]) {
        // 已被用到其他对列
        continue;
      }

      // 首先判断v是否可以接到其他对列之后
      if (need.count(v) && need[v] > 0) {
        // v 可以接到之前某个序列之后
        freq[v]--;
        // 对v的需求减1
        need[v]--;
        // v+1的需求加1
        need[v + 1]++;
      } else if (freq[v] > 0 && freq[v + 1] > 0 && freq[v + 2] > 0) {
        // 将v作为一个新的队列开始
        freq[v]--;
        freq[v + 1]--;
        freq[v + 2]--;

        // 对v+3的需求加1
        need[v + 3]++;
      } else {
        // 两种情况都不符合，返回false
        return false;
      }
    }

    return true;
  }
};
// @lc code=end
