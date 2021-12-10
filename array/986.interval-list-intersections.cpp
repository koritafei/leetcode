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
    int len1 = firstList.size();
    int len2 = secondList.size();

    std::vector<std::vector<int>> res;

    int i = 0, j = 0;
    while (i < len1 && j < len2) {
      int starti = firstList[i][0], endi = firstList[i][1];
      int startj = secondList[j][0], endj = secondList[j][1];

      // 是否存在交叉
      if (endj >= starti && endi >= startj) {
        res.push_back(
            std::vector<int>{std::max(starti, startj), std::min(endi, endj)});
      }

      if (endi < endj) {
        i++;
      } else {
        j++;
      }
    }

    return res;
  }
};
// @lc code=end
