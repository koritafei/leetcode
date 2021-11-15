/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 *
 * https://leetcode.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (45.76%)
 * Likes:    7838
 * Dislikes: 280
 * Total Accepted:    481.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * You are given an array of integers nums, there is a sliding window of size k
 * which is moving from the very left of the array to the very right. You can
 * only see the k numbers in the window. Each time the sliding window moves
 * right by one position.
 *
 * Return the max sliding window.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
 * Output: [3,3,5,5,6,7]
 * Explanation:
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1], k = 1
 * Output: [1]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,-1], k = 1
 * Output: [1,-1]
 *
 *
 * Example 4:
 *
 *
 * Input: nums = [9,11], k = 2
 * Output: [11]
 *
 *
 * Example 5:
 *
 *
 * Input: nums = [4,-2], k = 2
 * Output: [4]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 *
 *
 */

#include <list>
#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    MonotonicQueue   window;
    std::vector<int> res;

    for (int i = 0; i < nums.size(); i++) {
      // 填满前k个元素
      if (i < k - 1) {
        window.push(nums[i]);
      } else {
        // 窗口开始向前移动
        window.push(nums[i]);
        //当前窗口中最大元素加入结果集
        res.push_back(window.max());
        // 移出最后的元素
        window.popFirst(nums[i - k + 1]);
      }
    }
    return res;
  }

private:
  // 单调队列的实现
  class MonotonicQueue {
  public:
    void push(int n) {
      // 删除当前队列中所有小于n的元素
      while (!que_.empty() && que_.back() < n) {
        que_.pop_back();
      }

      que_.push_back(n);
    }

    int max() const {
      return que_.front();
    }

    void popFirst(int n) {
      if (n == que_.front()) {
        return que_.pop_front();
      }
    }

  private:
    std::list<int> que_;
  };
};
// @lc code=end
