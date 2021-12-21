/*
 * @lc app=leetcode id=233 lang=cpp
 *
 * [233] Number of Digit One
 *
 * https://leetcode.com/problems/number-of-digit-one/description/
 *
 * algorithms
 * Hard (32.77%)
 * Likes:    580
 * Dislikes: 896
 * Total Accepted:    59.1K
 * Total Submissions: 180.1K
 * Testcase Example:  '13'
 *
 * Given an integer n, count the total number of digit 1 appearing in all
 * non-negative integers less than or equal to n.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 13
 * Output: 6
 *
 *
 * Example 2:
 *
 *
 * Input: n = 0
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= n <= 10^9
 *
 *
 */

#include <cmath>

// @lc code=start
class Solution {
public:
  int countDigitOne(int n) {
    if (n <= 0) {
      return 0;
    }

    int len      = getLenOfNum(n);
    int tmp      = power10Base(len - 1);
    int first    = n / tmp;
    int firstOne = first == 1 ? n % tmp + 1 : tmp;
    int otherOne = first * (len - 1) * (tmp / 10);

    return firstOne + otherOne + countDigitOne(n % tmp);
  }

private:
  int getLenOfNum(int num) {
    int len = 0;

    while (num) {
      num /= 10;
      len++;
    }

    return len;
  }

  int power10Base(int base) {
    return std::pow(10, base);
  }
};
// @lc code=end
