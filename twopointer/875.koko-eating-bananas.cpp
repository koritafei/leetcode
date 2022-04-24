/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 *
 * https://leetcode.com/problems/koko-eating-bananas/description/
 *
 * algorithms
 * Medium (54.15%)
 * Likes:    2278
 * Dislikes: 123
 * Total Accepted:    104.7K
 * Total Submissions: 193.3K
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

#include <vector>

// @lc code=start
class Solution {
public:
  int minEatingSpeed(std::vector<int>& piles, int h) {
    int left = 1, right = getMax(piles);

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (canFinish(piles, mid, h)) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }

private:
  bool canFinish(std::vector<int>& piles, int speed, int h) {
    int count = 0;
    for (auto item : piles) {
      count += time(item, speed);
    }

    return count <= h;
  }

  int time(int n, int speed) {
    return (n / speed) + (n % speed > 0 ? 1 : 0);
  }

  // 获取数组中最大值
  int getMax(std::vector<int>& piles) {
    int max = INT_MIN;
    for (auto item : piles) {
      max = (max > item ? max : item);
    }

    return max;
  }
};
// @lc code=end
