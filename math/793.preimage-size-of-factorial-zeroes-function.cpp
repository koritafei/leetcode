/*
 * @lc app=leetcode id=793 lang=cpp
 *
 * [793] Preimage Size of Factorial Zeroes Function
 *
 * https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/description/
 *
 * algorithms
 * Hard (41.02%)
 * Likes:    265
 * Dislikes: 65
 * Total Accepted:    10.9K
 * Total Submissions: 26.7K
 * Testcase Example:  '0'
 *
 * Let f(x) be the number of zeroes at the end of x!. Recall that x! = 1 * 2 *
 * 3 * ... * x and by convention, 0! = 1.
 *
 *
 * For example, f(3) = 0 because 3! = 6 has no zeroes at the end, while f(11) =
 * 2 because 11! = 39916800 has two zeroes at the end.
 *
 *
 * Given an integer k, return the number of non-negative integers x have the
 * property that f(x) = k.
 *
 *
 * Example 1:
 *
 *
 * Input: k = 0
 * Output: 5
 * Explanation: 0!, 1!, 2!, 3!, and 4! end with k = 0 zeroes.
 *
 *
 * Example 2:
 *
 *
 * Input: k = 5
 * Output: 0
 * Explanation: There is no x such that x! ends in k = 5 zeroes.
 *
 *
 * Example 3:
 *
 *
 * Input: k = 3
 * Output: 5
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= k <= 10^9
 *
 *
 */

#include <climits>

// @lc code=start
class Solution {
public:
  long preimageSizeFZF(long k) {
    return right_bound(k) - left_bound(k) + 1;
  }

private:
  // 查找左边界
  long left_bound(long k) {
    long left = 0, right = LONG_MAX;

    while (left < right) {
      long mid = left + (right - left) / 2;
      long tmp = trailingZeroes(mid);
      if (k == tmp) {
        right = mid;
      } else if (tmp < k) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return left;
  }

  // 查找右边界
  long right_bound(long k) {
    long left = 0, right = LONG_MAX;

    while (left < right) {
      long mid = left + (right - left) / 2;
      long tmp = trailingZeroes(mid);
      if (k == tmp) {
        left = mid + 1;
      } else if (tmp < k) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return left - 1;
  }

  long trailingZeroes(long n) {
    // 计算n的阶乘中0的个数
    long res = 0;

    for (long d = n; d / 5 > 0; d = d / 5) {
      res += d / 5;
    }

    return res;
  }
};
// @lc code=end
