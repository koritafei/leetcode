/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 *
 * https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
 *
 * algorithms
 * Medium (62.17%)
 * Likes:    3190
 * Dislikes: 75
 * Total Accepted:    107.2K
 * Total Submissions: 172.4K
 * Testcase Example:  '[1,2,3,4,5,6,7,8,9,10]\n5'
 *
 * A conveyor belt has packages that must be shipped from one port to another
 * within days days.
 *
 * The i^th package on the conveyor belt has a weight of weights[i]. Each day,
 * we load the ship with packages on the conveyor belt (in the order given by
 * weights). We may not load more weight than the maximum weight capacity of
 * the ship.
 *
 * Return the least weight capacity of the ship that will result in all the
 * packages on the conveyor belt being shipped within days days.
 *
 *
 * Example 1:
 *
 *
 * Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
 * Output: 15
 * Explanation: A ship capacity of 15 is the minimum to ship all the packages
 * in 5 days like this:
 * 1st day: 1, 2, 3, 4, 5
 * 2nd day: 6, 7
 * 3rd day: 8
 * 4th day: 9
 * 5th day: 10
 *
 * Note that the cargo must be shipped in the order given, so using a ship of
 * capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6,
 * 7), (8), (9), (10) is not allowed.
 *
 *
 * Example 2:
 *
 *
 * Input: weights = [3,2,2,4,1,4], days = 3
 * Output: 6
 * Explanation: A ship capacity of 6 is the minimum to ship all the packages in
 * 3 days like this:
 * 1st day: 3, 2
 * 2nd day: 2, 4
 * 3rd day: 1, 4
 *
 *
 * Example 3:
 *
 *
 * Input: weights = [1,2,3,1,1], days = 4
 * Output: 3
 * Explanation:
 * 1st day: 1
 * 2nd day: 2
 * 3rd day: 3
 * 4th day: 1, 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= days <= weights.length <= 5 * 10^4
 * 1 <= weights[i] <= 500
 *
 */

#include <climits>
#include <vector>

// @lc code=start
class Solution {
public:
  int shipWithinDays(std::vector<int> &weights, int days) {
    int left = getMax(weights), right = getSum(weights);

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (canCarry(weights, mid, days)) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }

private:
  bool canCarry(std::vector<int> &weights, int weight, int days) {
    int j = 0;
    for (int i = 0; i < days; i++) {
      int maxcap = weight;
      while ((maxcap -= weights[j]) >= 0) {
        j++;
        if (j == weights.size()) {
          return true;
        }
      }
    }

    return false;
  }

  int getMax(std::vector<int> &weights) {
    int res = INT_MIN;
    for (auto &it : weights) {
      res = std::max(it, res);
    }

    return res == INT_MIN ? 0 : res;
  }

  int getSum(std::vector<int> &weights) {
    int sum = 0;
    for (auto &it : weights) {
      sum += it;
    }
    return sum;
  }
};
// @lc code=end
