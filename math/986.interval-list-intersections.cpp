/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 *
 * https://leetcode.com/problems/interval-list-intersections/description/
 *
 * algorithms
 * Medium (69.71%)
 * Likes:    3072
 * Dislikes: 70
 * Total Accepted:    228.5K
 * Total Submissions: 327.4K
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

using namespace std;

// @lc code=start
class Solution {
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                           vector<vector<int>>& secondList) {
    vector<vector<int>> res;
    int                 i = 0, j = 0;

    while (i < firstList.size() && j < secondList.size()) {
      vector<int> a = firstList[i];
      vector<int> b = secondList[j];

      if (b[1] >= a[0] && a[1] >= b[0]) {
        res.push_back(
            std::vector<int>{std::max(a[0], b[0]), std::min(a[1], b[1])});
      }

      if (b[1] < a[1]) {
        j++;
      } else {
        i++;
      }
    }

    return res;
  }
};
// @lc code=end
