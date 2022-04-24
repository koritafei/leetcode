/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Medium (32.87%)
 * Likes:    4156
 * Dislikes: 931
 * Total Accepted:    565.1K
 * Total Submissions: 1.7M
 * Testcase Example:  '10'
 *
 * Given an integer n, return the number of prime numbers that are strictly
 * less than n.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 0
 * Output: 0
 *
 *
 * Example 3:
 *
 *
 * Input: n = 1
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= n <= 5 * 10^6
 *
 *
 */

#include <cmath>
#include <vector>

// @lc code=start
class Solution {
public:
  int countPrimes(int n) {
    primesvec = std::vector<bool>(n, true);
    int count = 0;
    for (int i = 2; i < n; i++) {
      if (primesvec[i]) {
        count++;
        for (int j = i * 2; j < n; j += i) {
          primesvec[j] = false;
        }
      }
    }

    return count;
  }

private:
  std::vector<bool> primesvec;
};
// @lc code=end
