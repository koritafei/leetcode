/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 *
 * https://leetcode.com/problems/interval-list-intersections/description/
 *
 * algorithms
 * Medium (70.47%)
 * Likes:    3600
 * Dislikes: 77
 * Total Accepted:    254.6K
 * Total Submissions: 361.4K
 * Testcase Example:
 * '[[0,2],[5,10],[13,23],[24,25]]\n[[1,5],[8,12],[15,24],[25,26]]'
 *
 * You are given two lists of closed intervals, firstList and secondList, where
 * firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list
 * of intervals is pairwise disjoint and in sorted order.
 *
 * Return the intersection of these two interval lists.
 *
 * A closed interval [a, b] (with a <= b) denotes the set of real numbers x
 * with a <= x <= b.
 *
 * The intersection of two closed intervals is a set of real numbers that are
 * either empty or represented as a closed interval. For example, the
 * intersection of [1, 3] and [2, 4] is [2, 3].
 *
 *
 * Example 1:
 *
 *
 * Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList =
 * [[1,5],[8,12],[15,24],[25,26]]
 * Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 *
 *
 * Example 2:
 *
 *
 * Input: firstList = [[1,3],[5,9]], secondList = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: firstList = [], secondList = [[4,8],[10,12]]
 * Output: []
 *
 *
 * Example 4:
 *
 *
 * Input: firstList = [[1,7]], secondList = [[3,10]]
 * Output: [[3,7]]
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= firstList.length, secondList.length <= 1000
 * firstList.length + secondList.length >= 1
 * 0 <= starti < endi <= 10^9
 * endi < starti+1
 * 0 <= startj < endj <= 10^9
 * endj < startj+1
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<std::vector<int>> intervalIntersection(
      std::vector<std::vector<int>>& firstList,
      std::vector<std::vector<int>>& secondList) {
    std::vector<std::vector<int>> res;

    int lenf = firstList.size();
    int lens = secondList.size();

    if (lens == 0 || lenf == 0) {
      return res;
    }

    int i = 0, j = 0;
    while (i < lenf && j < lens) {
      int a1 = firstList[i][0], b1 = firstList[i][1];
      int a2 = secondList[j][0], b2 = secondList[j][1];

      if (b1 >= a2 && b2 >= a1) {
        res.push_back(std::vector<int>{std::max(a1, a2), std::min(b1, b2)});
      }

      if (b1 <= b2) {
        i++;
      } else {
        j++;
      }
    }

    return res;
  }
};
// @lc code=end
