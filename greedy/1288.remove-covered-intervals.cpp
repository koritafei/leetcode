/*
 * @lc app=leetcode id=1288 lang=cpp
 *
 * [1288] Remove Covered Intervals
 *
 * https://leetcode.com/problems/remove-covered-intervals/description/
 *
 * algorithms
 * Medium (57.83%)
 * Likes:    777
 * Dislikes: 30
 * Total Accepted:    51.7K
 * Total Submissions: 89.4K
 * Testcase Example:  '[[1,4],[3,6],[2,8]]'
 *
 * Given an array intervals where intervals[i] = [li, ri] represent the
 * interval [li, ri), remove all intervals that are covered by another interval
 * in the list.
 *
 * The interval [a, b) is covered by the interval [c, d) if and only if c <= a
 * and b <= d.
 *
 * Return the number of remaining intervals.
 *
 *
 * Example 1:
 *
 *
 * Input: intervals = [[1,4],[3,6],[2,8]]
 * Output: 2
 * Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
 *
 *
 * Example 2:
 *
 *
 * Input: intervals = [[1,4],[2,3]]
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: intervals = [[0,10],[5,12]]
 * Output: 2
 *
 *
 * Example 4:
 *
 *
 * Input: intervals = [[3,10],[4,10],[5,11]]
 * Output: 2
 *
 *
 * Example 5:
 *
 *
 * Input: intervals = [[1,2],[1,4],[3,4]]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= intervals.length <= 1000
 * intervals[i].length == 2
 * 0 <= li <= ri <= 10^5
 * All the given intervals are unique.
 *
 *
 */

#include <algorithm>
#include <vector>

// @lc code=start
class Solution {
public:
  int removeCoveredIntervals(std::vector<std::vector<int>> &intervals) {
    int len = intervals.size();
    if (len == 0) {
      return 0;
    }

    std::sort(intervals.begin(),
              intervals.end(),
              [](const std::vector<int> &v1, const std::vector<int> &v2) {
                if (v1[0] == v2[0]) {
                  return v1[1] > v2[1];
                }

                return v1[0] < v2[0];
              });
    int count = 0;
    int left = intervals[0][0], right = intervals[0][1];

    for (int i = 1; i < len; i++) {
      // 覆盖
      if (left <= intervals[i][0] && right >= intervals[i][1]) {
        count++;
        continue;
      }
      // 交叉
      if (right <= intervals[i][1]) {
        right = intervals[i][1];
        continue;
      }

      // 不相交
      if (right < intervals[i][0]) {
        left  = intervals[i][0];
        right = intervals[i][1];
      }
    }

    return len - count;
  }
};
// @lc code=end
