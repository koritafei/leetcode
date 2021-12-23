/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 *
 * https://leetcode.com/problems/set-mismatch/description/
 *
 * algorithms
 * Easy (41.09%)
 * Likes:    1518
 * Dislikes: 505
 * Total Accepted:    148.3K
 * Total Submissions: 361K
 * Testcase Example:  '[1,2,2,4]'
 *
 * You have a set of integers s, which originally contains all the numbers from
 * 1 to n. Unfortunately, due to some error, one of the numbers in s got
 * duplicated to another number in the set, which results in repetition of one
 * number and loss of another number.
 *
 * You are given an integer array nums representing the data status of this set
 * after the error.
 *
 * Find the number that occurs twice and the number that is missing and return
 * them in the form of an array.
 *
 *
 * Example 1:
 * Input: nums = [1,2,2,4]
 * Output: [2,3]
 * Example 2:
 * Input: nums = [1,1]
 * Output: [1,2]
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 10^4
 * 1 <= nums[i] <= 10^4
 *
 *
 */

#include <climits>
#include <cmath>
#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<int> findErrorNums(std::vector<int>& nums) {
    std::vector<int> res;
    int              dup     = INT_MIN;
    int              missing = INT_MIN;
    int              len     = nums.size();
    for (int i = 0; i < len; i++) {
      int index = abs(nums[i]) - 1;
      if (nums[index] < 0) {
        dup = abs(nums[i]);
      } else {
        nums[index] *= -1;
      }
    }

    for (int i = 0; i < len; i++) {
      if (nums[i] > 0) {
        missing = i + 1;
      }
    }

    if (dup == INT_MIN) {
      return res;
    } else {
      res.push_back(dup), res.push_back(missing);
      return res;
    }
    return res;
  }
};
// @lc code=end
