/*
 * @lc app=leetcode id=480 lang=cpp
 *
 * [480] Sliding Window Median
 *
 * https://leetcode.com/problems/sliding-window-median/description/
 *
 * algorithms
 * Hard (40.32%)
 * Likes:    1872
 * Dislikes: 119
 * Total Accepted:    93.6K
 * Total Submissions: 231.7K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * The median is the middle value in an ordered integer list. If the size of
 * the list is even, there is no middle value. So the median is the mean of the
 * two middle values.
 *
 *
 * For examples, if arr = [2,3,4], the median is 3.
 * For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
 *
 *
 * You are given an integer array nums and an integer k. There is a sliding
 * window of size k which is moving from the very left of the array to the very
 * right. You can only see the k numbers in the window. Each time the sliding
 * window moves right by one position.
 *
 * Return the median array for each window in the original array. Answers
 * within 10^-5 of the actual value will be accepted.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
 * Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
 * Explanation:
 * Window position                Median
 * ---------------                -----
 * [1  3  -1] -3  5  3  6  7        1
 * ⁠1 [3  -1  -3] 5  3  6  7       -1
 * ⁠1  3 [-1  -3  5] 3  6  7       -1
 * ⁠1  3  -1 [-3  5  3] 6  7        3
 * ⁠1  3  -1  -3 [5  3  6] 7        5
 * ⁠1  3  -1  -3  5 [3  6  7]       6
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,4,2,3,1,4,2], k = 3
 * Output: [2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= nums.length <= 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 *
 *
 */

#include <algorithm>
#include <queue>
#include <vector>

// @lc code=start
class DualHeap {
private:
  // 大根堆，维护较小的一半元素
  priority_queue<int> small;
  // 小根堆，维护较大的一半元素
  priority_queue<int, vector<int>, greater<int>> large;
  // 哈希表，记录「延迟删除」的元素，key 为元素，value 为需要删除的次数
  unordered_map<int, int> delayed;

  int k;
  // small 和 large 当前包含的元素个数，需要扣除被「延迟删除」的元素
  int smallSize, largeSize;

public:
  DualHeap(int _k) : k(_k), smallSize(0), largeSize(0) {
  }

private:
  // 不断地弹出 heap 的堆顶元素，并且更新哈希表
  template <typename T>
  void prune(T& heap) {
    while (!heap.empty()) {
      int num = heap.top();
      if (delayed.count(num)) {
        --delayed[num];
        if (!delayed[num]) {
          delayed.erase(num);
        }
        heap.pop();
      } else {
        break;
      }
    }
  }

  // 调整 small 和 large 中的元素个数，使得二者的元素个数满足要求
  void makeBalance() {
    if (smallSize > largeSize + 1) {
      // small 比 large 元素多 2 个
      large.push(small.top());
      small.pop();
      --smallSize;
      ++largeSize;
      // small 堆顶元素被移除，需要进行 prune
      prune(small);
    } else if (smallSize < largeSize) {
      // large 比 small 元素多 1 个
      small.push(large.top());
      large.pop();
      ++smallSize;
      --largeSize;
      // large 堆顶元素被移除，需要进行 prune
      prune(large);
    }
  }

public:
  void insert(int num) {
    if (small.empty() || num <= small.top()) {
      small.push(num);
      ++smallSize;
    } else {
      large.push(num);
      ++largeSize;
    }
    makeBalance();
  }

  void erase(int num) {
    ++delayed[num];
    if (num <= small.top()) {
      --smallSize;
      if (num == small.top()) {
        prune(small);
      }
    } else {
      --largeSize;
      if (num == large.top()) {
        prune(large);
      }
    }
    makeBalance();
  }

  double getMedian() {
    return k & 1 ? small.top() : ((double)small.top() + large.top()) / 2;
  }
};

class Solution {
public:
  vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    DualHeap dh(k);
    for (int i = 0; i < k; ++i) {
      dh.insert(nums[i]);
    }
    vector<double> ans = {dh.getMedian()};
    for (int i = k; i < nums.size(); ++i) {
      dh.insert(nums[i]);
      dh.erase(nums[i - k]);
      ans.push_back(dh.getMedian());
    }
    return ans;
  }
};
// @lc code=end
