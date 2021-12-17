/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (39.23%)
 * Likes:    7902
 * Dislikes: 120
 * Total Accepted:    429.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given an array of integers heights representing the histogram's bar height
 * where the width of each bar is 1, return the area of the largest rectangle
 * in the histogram.
 *
 *
 * Example 1:
 *
 *
 * Input: heights = [2,1,5,6,2,3]
 * Output: 10
 * Explanation: The above is a histogram where width of each bar is 1.
 * The largest rectangle is shown in the red area, which has an area = 10
 * units.
 *
 *
 * Example 2:
 *
 *
 * Input: heights = [2,4]
 * Output: 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= heights.length <= 10^5
 * 0 <= heights[i] <= 10^4
 *
 *
 */

#include <stack>
#include <vector>

// @lc code=start
class Solution {
public:
  int largestRectangleArea(std::vector<int>& heights) {
    int maxArea = 0;
    int len     = heights.size();
    std::stack<int>
        minstack;  // 存储了一个递增序列，表示back()的元素向前扩展到back()-1，向后扩展到i-1
    for (int i = 0; i < len; i++) {
      while (minstack.size() && heights[minstack.top()] > heights[i]) {
        int j = minstack.top();
        minstack.pop();
        int t   = minstack.empty() ? -1 : minstack.top();
        maxArea = std::max(maxArea, (i - t - 1) * heights[j]);
      }
      minstack.push(i);
    }

    while (minstack.size()) {
      int j = minstack.top();
      minstack.pop();
      int i   = minstack.empty() ? -1 : minstack.top();
      maxArea = std::max(maxArea, (len - i - 1) * heights[j]);
    }

    return maxArea;
  }
};
// @lc code=end
