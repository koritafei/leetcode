/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (43.23%)
 * Likes:    10305
 * Dislikes: 447
 * Total Accepted:    1.1M
 * Total Submissions: 2.6M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given an array of intervals where intervals[i] = [starti, endi], merge all
 * overlapping intervals, and return an array of the non-overlapping intervals
 * that cover all the intervals in the input.
 *
 *
 * Example 1:
 *
 *
 * Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 *
 *
 * Example 2:
 *
 *
 * Input: intervals = [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^4
 *
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

void print(std::vector<std::vector<int>> res) {
  for (auto item : res) {
    for (auto it : item) {
      std::cout << it << ' ';
    }
    std::cout << '\n';
  }

  std::cout << "\n\n";
}

// @lc code=start
class Solution {
public:
  std::vector<std::vector<int>> merge(
      std::vector<std::vector<int>> &intervals) {
    int                           len = intervals.size();
    std::vector<std::vector<int>> res;
    if (0 == len) {
      return res;
    }

    // 排序，起点升序，起点相同终点降序
    std::sort(intervals.begin(),
              intervals.end(),
              [](std::vector<int> &a, std::vector<int> &b) {
                if (a[0] == b[0]) {
                  return a[1] > b[1];
                }
                return a[0] < b[0];
              });

    // print(intervals);

    int left  = intervals[0][0];  // 起点
    int right = intervals[0][1];  // 终点

    for (int i = 1; i < len; i++) {
      // 覆盖
      if (left <= intervals[i][0] && right >= intervals[i][1]) {
        continue;
      }

      // 相交，合并
      if (right >= intervals[i][0] && right <= intervals[i][1]) {
        // std::cout << left << ' ' << right << std::endl;

        right = intervals[i][1];
      }

      // 不相交，加入结果集
      if (right < intervals[i][0]) {
        res.push_back(std::vector<int>{left, right});
        left  = intervals[i][0];
        right = intervals[i][1];
      }
    }

    res.push_back(std::vector<int>{left, right});

    return res;
  }
};
// @lc code=end

int main() {
  std::vector<std::vector<int>> nums = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  Solution                      s;
  auto                          res = s.merge(nums);
  print(res);
}
