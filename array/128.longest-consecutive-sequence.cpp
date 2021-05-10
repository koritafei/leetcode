/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (46.06%)
 * Likes:    4753
 * Dislikes: 233
 * Total Accepted:    380.3K
 * Total Submissions: 820.8K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers nums, return the length of the longest
 * consecutive elements sequence.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 *
 *
 *
 * Follow up: Could you implement the O(n) solution?
 */

#include <iostream>
#include <unordered_set>
#include <vector>

// @lc code=start
class Solution {
public:
  int longestConsecutive(std::vector<int>& nums) {
    int len = nums.size();
    if (len <= 1) {
      return len;
    }
    std::unordered_set<int> s;
    for (auto item : nums) {
      s.insert(item);
    }

    int lengthest = 0;

    for (auto item : nums) {
      int length = 1;
      for (int j = item - 1; s.find(j) != s.end(); --j) {
        length++;
        s.erase(j);
      }

      for (int j = item + 1; s.find(j) != s.end(); ++j) {
        length++;
        s.erase(j);
      }
      lengthest = std::max(length, lengthest);
    }
    return lengthest;
  }
};
// @lc code=end

int main(int argc, char** argv) {
  std::vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  Solution         solution;
  std::cout << solution.longestConsecutive(nums) << std::endl;
}
