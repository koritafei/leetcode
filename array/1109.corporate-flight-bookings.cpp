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
    std::vector<int> nums(n, 0);
    difference       d(nums);
    for (std::size_t i = 0; i < bookings.size(); i++) {
      d.increment(bookings[i][0] - 1, bookings[i][1] - 1, bookings[i][2]);
    }

    return d.result();
  }

private:
  class difference {
  public:
    difference(std::vector<int>& nums) {
      std::size_t len = nums.size();
      if (0 == len) {
        return;
      }
      diff_    = std::vector<int>(len, 0);
      diff_[0] = nums[0];

      for (std::size_t i = 1; i < len; i++) {
        diff_[i] = nums[i] - nums[i - 1];
      }
    }

    void increment(std::size_t i, std::size_t j, int val) {
      // 从i到j增加val
      diff_[i] += val;
      if (j + 1 < diff_.size()) {
        diff_[j + 1] -= val;
      }
    }

    // 还原数组
    std::vector<int> result() {
      std::vector<int> res;
      std::size_t      len = diff_.size();
      if (0 >= len) {
        return res;
      }

      res = std::vector<int>(len, 0);

      res[0] = diff_[0];
      for (std::size_t i = 1; i < len; i++) {
        res[i] = res[i - 1] + diff_[i];
      }

      return res;
    }

  private:
    std::vector<int> diff_;
  };
};
// @lc code=end
