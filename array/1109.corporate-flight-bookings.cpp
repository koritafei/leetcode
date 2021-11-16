/*
 * @lc app=leetcode id=1109 lang=cpp
 *
 * [1109] Corporate Flight Bookings
 *
 * https://leetcode.com/problems/corporate-flight-bookings/description/
 *
 * algorithms
 * Medium (56.04%)
 * Likes:    849
 * Dislikes: 132
 * Total Accepted:    31.7K
 * Total Submissions: 56.5K
 * Testcase Example:  '[[1,2,10],[2,3,20],[2,5,25]]\n5'
 *
 * There are n flights that are labeled from 1 to n.
 *
 * You are given an array of flight bookings bookings, where bookings[i] =
 * [firsti, lasti, seatsi] represents a booking for flights firsti through
 * lasti (inclusive) with seatsi seats reserved for each flight in the range.
 *
 * Return an array answer of length n, where answer[i] is the total number of
 * seats reserved for flight i.
 *
 *
 * Example 1:
 *
 *
 * Input: bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
 * Output: [10,55,45,25,25]
 * Explanation:
 * Flight labels:        1   2   3   4   5
 * Booking 1 reserved:  10  10
 * Booking 2 reserved:      20  20
 * Booking 3 reserved:      25  25  25  25
 * Total seats:         10  55  45  25  25
 * Hence, answer = [10,55,45,25,25]
 *
 *
 * Example 2:
 *
 *
 * Input: bookings = [[1,2,10],[2,2,15]], n = 2
 * Output: [10,25]
 * Explanation:
 * Flight labels:        1   2
 * Booking 1 reserved:  10  10
 * Booking 2 reserved:      15
 * Total seats:         10  25
 * Hence, answer = [10,25]
 *
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 2 * 10^4
 * 1 <= bookings.length <= 2 * 10^4
 * bookings[i].length == 3
 * 1 <= firsti <= lasti <= n
 * 1 <= seatsi <= 10^4
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<int> corpFlightBookings(std::vector<std::vector<int>>& bookings,
                                      int                            n) {
    int              len = bookings.size();
    std::vector<int> diff(n, 0);

    for (int i = 0; i < len; i++) {
      std::vector<int> tmp   = bookings[i];
      int              start = tmp[0] - 1;
      int              end   = tmp[1] - 1;
      int              book  = tmp[2];
      diff[start] += book;
      if (end + 1 < n) {
        diff[end + 1] -= book;
      }
    }
    // 构造结果数组
    std::vector<int> res(n, 0);
    res[0] = diff[0];
    for (int i = 1; i < n; i++) {
      res[i] = res[i - 1] + diff[i];
    }

    return res;
  }
};
// @lc code=end
