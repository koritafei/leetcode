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
    int              len  = trips.size();
    std::vector<int> nums = std::vector<int>(1001, 0);
    difference       df(nums);
    for (int i = 0; i < len; i++) {
      int cap   = trips[i][0];
      int start = trips[i][1];
      int end   = trips[i][2] - 1;
      df.increment(cap, start, end);
    }

    std::vector<int> res = df.result();
    for (int i = 0; i < 1001; i++) {
      if (res[i] > capacity) {
        return false;
      }
    }

    return true;
  }

private:
  class difference {
  public:
    difference(std::vector<int>& nums) {
      diff    = std::vector<int>(nums.size(), 0);
      diff[0] = nums[0];
      for (int i = 1; i < nums.size(); i++) {
        diff[i] = nums[i] - nums[i - 1];
      }
    }

    void increment(int cap, int i, int j) {
      diff[i] += cap;
      if (j + 1 < diff.size()) {
        diff[j + 1] -= cap;
      }
    }

    std::vector<int> result() {
      std::vector<int> res = std::vector<int>(diff.size());
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
