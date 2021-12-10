/*
 * @lc app=leetcode id=1109 lang=cpp
 *
 * [1109] Corporate Flight Bookings
 *
 * https://leetcode.com/problems/corporate-flight-bookings/description/
 *
 * algorithms
 * Medium (56.51%)
 * Likes:    870
 * Dislikes: 132
 * Total Accepted:    32.6K
 * Total Submissions: 57.6K
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
    std::vector<int> nums = std::vector<int>(n, 0);
    difference       df(nums);
    std::vector<int> res;

    for (int i = 0; i < bookings.size(); i++) {
      int s = bookings[i][0] - 1;
      int e = bookings[i][1] - 1;
      int b = bookings[i][2];
      df.increment(b, s, e);
    }

    res = df.result();

    return res;
  }

private:
  class difference {
  public:
    difference(std::vector<int> nums) {
      int len = nums.size();
      if (len > 0) {
        diff    = std::vector<int>(len, 0);
        diff[0] = nums[0];
        for (int i = 1; i < len; i++) {
          diff[i] = nums[i] - nums[i - 1];
        }
      }
    }

    void increment(int cap, int left, int right) {
      diff[left] += cap;
      if (right + 1 < diff.size()) {
        diff[right + 1] -= cap;
      }
    }

    std::vector<int> result() {
      std::vector<int> res = std::vector<int>(diff.size(), 0);
      res[0]               = diff[0];
      for (int i = 1; i < diff.size(); i++) {
        res[i] = res[i - 1] + diff[i];
      }

      return res;
    }

  private:
    std::vector<int> diff;
  };
};
// @lc code=end
