/*
 * @lc app=leetcode id=793 lang=cpp
 *
 * [793] Preimage Size of Factorial Zeroes Function
 *
 * https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/description/
 *
 * algorithms
 * Hard (41.11%)
 * Likes:    266
 * Dislikes: 65
 * Total Accepted:    11.1K
 * Total Submissions: 27K
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

// @lc code=start

#include <climits>

class Solution {
public:
  long preimageSizeFZF(long k) {
    return right_bound(k) - left_bound(k) + 1;
  }

private:
  long left_bound(long k) {
    long left = 0, right = LONG_MAX;
    while (left <= right) {
      long mid = left + (right - left) / 2;
      long tmp = countZero(mid);
      if (tmp >= k) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }

  long right_bound(long k) {
    long left = 0, right = LONG_MAX;
    while (left <= right) {
      long mid = left + (right - left) / 2;
      long tmp = countZero(mid);
      if (tmp <= k) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return right;
  }

  long countZero(long k) {
    long count = 0;
    for (long d = k; d / 5 > 0; d /= 5) {
      count += d / 5;
    }

    return count;
  }
};
// @lc code=end
