/*
 * @lc app=leetcode id=319 lang=cpp
 *
 * [319] Bulb Switcher
 *
 * https://leetcode.com/problems/bulb-switcher/description/
 *
 * algorithms
 * Medium (46.45%)
 * Likes:    774
 * Dislikes: 1463
 * Total Accepted:    103.8K
 * Total Submissions: 223.2K
 * Testcase Example:  '3'
 *
 * There are n bulbs that are initially off. You first turn on all the bulbs,
 * then you turn off every second bulb.
 *
 * On the third round, you toggle every third bulb (turning on if it's off or
 * turning off if it's on). For the i^th round, you toggle every i bulb. For
 * the n^th round, you only toggle the last bulb.
 *
 * Return the number of bulbs that are on after n rounds.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3
 * Output: 1
 * Explanation: At first, the three bulbs are [off, off, off].
 * After the first round, the three bulbs are [on, on, on].
 * After the second round, the three bulbs are [on, off, on].
 * After the third round, the three bulbs are [on, off, off].
 * So you should return 1 because there is only one bulb is on.
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
 * Output: 1
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

// @lc code=start
class Solution {
public:
  int bulbSwitch(int n) {
    return (int)sqrt(n);
  }
};
// @lc code=end
