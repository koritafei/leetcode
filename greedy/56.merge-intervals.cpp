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
    std::vector<std::vector<int>> res;

    int len = intervals.size();

    if (0 == len) {
      return res;
    }

    // std::sort(intervals.begin(),
    //           intervals.end(),
    //           [](const std::vector<int> &v1, const std::vector<int> &v2) {
    //             return v1[0] < v2[0];
    //           });

    // int i = 1;
    // res.push_back(intervals[0]);
    // while (i < len) {
    //   auto &end = res.back().back();
    //   if (intervals[i][0] <= end) {
    //     end = std::max(end, intervals[i][1]);
    //   } else {
    //     res.push_back(std::vector<int>{intervals[i][0], intervals[i][1]});
    //   }
    //   i++;
    // }

    std::sort(intervals.begin(),
              intervals.end(),
              [](const std::vector<int> &v1, const std::vector<int> &v2) {
                if (v1[0] == v2[0]) {
                  return v1[1] > v2[1];
                }
                return v1[0] < v2[0];
              });

    int left = intervals[0][0], right = intervals[0][1];
    for (int i = 1; i < len; i++) {
      // 覆盖，直接跳过
      if (left <= intervals[i][0] && right >= intervals[i][1]) {
        continue;
      }

      // 交叉，将right后移
      if (right >= intervals[i][0] && right <= intervals[i][1]) {
        right = intervals[i][1];
        continue;
      }

      // 不相交
      if (right < intervals[i][0]) {
        res.push_back(std::vector<int>{left, right});
        left  = intervals[i][0];
        right = intervals[i][1];
      }
    }

    res.push_back(std::vector<int>{left, right});  // 最后一组加入结果集

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
