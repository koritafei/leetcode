/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 *
 * https://leetcode.com/problems/non-overlapping-intervals/description/
 *
 * algorithms
 * Medium (46.39%)
 * Likes:    2965
 * Dislikes: 83
 * Total Accepted:    186.2K
 * Total Submissions: 400.4K
 * Testcase Example:  '[[1,2],[2,3],[3,4],[1,3]]'
 *
 * Given an array of intervals intervals where intervals[i] = [starti, endi],
 * return the minimum number of intervals you need to remove to make the rest
 * of the intervals non-overlapping.
 *
 *
 * Example 1:
 *
 *
 * Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
 * Output: 1
 * Explanation: [1,3] can be removed and the rest of the intervals are
 * non-overlapping.
 *
 *
 * Example 2:
 *
 *
 * Input: intervals = [[1,2],[1,2],[1,2]]
 * Output: 2
 * Explanation: You need to remove two [1,2] to make the rest of the intervals
 * non-overlapping.
 *
 *
 * Example 3:
 *
 *
 * Input: intervals = [[1,2],[2,3]]
 * Output: 0
 * Explanation: You don't need to remove any of the intervals since they're
 * already non-overlapping.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= intervals.length <= 10^5
 * intervals[i].length == 2
 * -5 * 10^4 <= starti < endi <= 5 * 10^4
 *
 *
 */

#include <algorithm>
#include <vector>

// @lc code=start
class Solution {
public:
  int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
    int len = intervals.size();
    if (1 >= len) {
      return 0;
    }

    std::sort(intervals.begin(),
              intervals.end(),
              [](std::vector<int> a, std::vector<int> b) {
                return a[1] < b[1];
              });

    int count = 1;
    int endy  = intervals[0][1];
    for (int i = 1; i < len; i++) {
      int startx = intervals[i][0];
      if (startx >= endy) {
        count++;
        endy = intervals[i][1];
      }
    }

    return len - count;
  }
};
// @lc code=end
