/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 *
 * https://leetcode.com/problems/koko-eating-bananas/description/
 *
 * algorithms
 * Medium (54.24%)
 * Likes:    2366
 * Dislikes: 127
 * Total Accepted:    108.3K
 * Total Submissions: 199.8K
 * Testcase Example:  '[3,6,7,11]\n8'
 *
 * Koko loves to eat bananas. There are n piles of bananas, the i^th pile has
 * piles[i] bananas. The guards have gone and will come back in h hours.
 *
 * Koko can decide her bananas-per-hour eating speed of k. Each hour, she
 * chooses some pile of bananas and eats k bananas from that pile. If the pile
 * has less than k bananas, she eats all of them instead and will not eat any
 * more bananas during this hour.
 *
 * Koko likes to eat slowly but still wants to finish eating all the bananas
 * before the guards return.
 *
 * Return the minimum integer k such that she can eat all the bananas within h
 * hours.
 *
 *
 * Example 1:
 *
 *
 * Input: piles = [3,6,7,11], h = 8
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: piles = [30,11,23,4,20], h = 5
 * Output: 30
 *
 *
 * Example 3:
 *
 *
 * Input: piles = [30,11,23,4,20], h = 6
 * Output: 23
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= piles.length <= 10^4
 * piles.length <= h <= 10^9
 * 1 <= piles[i] <= 10^9
 *
 *
 */

#include <climits>
#include <vector>

// @lc code=start
class Solution {
public:
  int minEatingSpeed(std::vector<int>& piles, int h) {
    int left = 1, right = getMax(piles);
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (eatTime(piles, mid, h)) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }

private:
  bool eatTime(std::vector<int>& piles, int t, int h) {
    int count = 0;
    for (auto it : piles) {
      count += it > t ? it / t + (it % t > 0 ? 1 : 0) : 1;
    }
    return count <= h;
  }

  int getMax(std::vector<int>& piles) {
    int max = INT_MIN;
    for (auto it : piles) {
      max = max > it ? max : it;
    }

    return max;
  }
};
// @lc code=end
