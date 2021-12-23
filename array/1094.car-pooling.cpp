/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 *
 * https://leetcode.com/problems/car-pooling/description/
 *
 * algorithms
 * Medium (59.46%)
 * Likes:    1723
 * Dislikes: 47
 * Total Accepted:    92.3K
 * Total Submissions: 155.2K
 * Testcase Example:  '[[2,1,5],[3,3,7]]\n4'
 *
 * There is a car with capacity empty seats. The vehicle only drives east
 * (i.e., it cannot turn around and drive west).
 *
 * You are given the integer capacity and an array trips where trip[i] =
 * [numPassengersi, fromi, toi] indicates that the i^th trip has numPassengersi
 * passengers and the locations to pick them up and drop them off are fromi and
 * toi respectively. The locations are given as the number of kilometers due
 * east from the car's initial location.
 *
 * Return true if it is possible to pick up and drop off all passengers for all
 * the given trips, or false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: trips = [[2,1,5],[3,3,7]], capacity = 4
 * Output: false
 *
 *
 * Example 2:
 *
 *
 * Input: trips = [[2,1,5],[3,3,7]], capacity = 5
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: trips = [[2,1,5],[3,5,7]], capacity = 3
 * Output: true
 *
 *
 * Example 4:
 *
 *
 * Input: trips = [[3,2,7],[3,7,9],[8,3,9]], capacity = 11
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= trips.length <= 1000
 * trips[i].length == 3
 * 1 <= numPassengersi <= 100
 * 0 <= fromi < toi <= 1000
 * 1 <= capacity <= 10^5
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  bool carPooling(std::vector<std::vector<int>>& trips, int capacity) {
    std::vector<int> nums(1001, 0);
    std::size_t      len = trips.size();
    difference       d(nums);

    for (std::size_t i = 0; i < len; i++) {
      d.increment(trips[i][1], trips[i][2] - 1, trips[i][0]);
    }

    auto res = d.result();

    for (std::size_t i = 0; i < res.size(); i++) {
      if (capacity < res[i]) {
        return false;
      }
    }

    return true;
  }

private:
  class difference {
  public:
    difference(std::vector<int>& nums) {
      std::size_t len = nums.size();
      if (len <= 0) {
        return;
      }

      diff_    = std::vector<int>(len, 0);
      diff_[0] = nums[0];
      for (std::size_t i = 1; i < len; i++) {
        diff_[i] = nums[i] - nums[i - 1];
      }
    }

    void increment(std::size_t i, std::size_t j, int val) {
      diff_[i] += val;
      if (j + 1 < diff_.size()) {
        diff_[j + 1] -= val;
      }
    }

    std::vector<int> result() {
      std::vector<int> res;
      std::size_t      len = diff_.size();
      if (len <= 0) {
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
