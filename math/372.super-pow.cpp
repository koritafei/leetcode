/*
 * @lc app=leetcode id=372 lang=cpp
 *
 * [372] Super Pow
 *
 * https://leetcode.com/problems/super-pow/description/
 *
 * algorithms
 * Medium (37.49%)
 * Likes:    388
 * Dislikes: 982
 * Total Accepted:    44.7K
 * Total Submissions: 119.3K
 * Testcase Example:  '2\n[3]'
 *
 * Your task is to calculate a^b mod 1337 where a is a positive integer and b
 * is an extremely large positive integer given in the form of an array.
 *
 *
 * Example 1:
 * Input: a = 2, b = [3]
 * Output: 8
 * Example 2:
 * Input: a = 2, b = [1,0]
 * Output: 1024
 * Example 3:
 * Input: a = 1, b = [4,3,3,8,5,2]
 * Output: 1
 * Example 4:
 * Input: a = 2147483647, b = [2,0,0]
 * Output: 1198
 *
 *
 * Constraints:
 *
 *
 * 1 <= a <= 2^31 - 1
 * 1 <= b.length <= 2000
 * 0 <= b[i] <= 9
 * b doesn't contain leading zeros.
 *
 *
 */
#include <vector>

// @lc code=start
class Solution {
public:
  int superPow(int a, std::vector<int>& b) {
    if (b.empty()) {
      return 1;
    }

    int last = b.back();
    b.pop_back();

    int part1 = mypow(a, last);
    int part2 = mypow(superPow(a, b), 10);

    return part1 * part2 % base;
  }

private:
  int mypow(int a, int k) {
    if (k == 0) {
      return 1;
    }

    a %= base;

    if (k % 2 == 0) {
      int sub = mypow(a, k / 2);
      return sub * sub % base;
    } else {
      return a * mypow(a, k - 1) % base;
    }
  }

  int base = 1337;
};
// @lc code=end
