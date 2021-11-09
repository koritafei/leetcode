/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 *
 * https://leetcode.com/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (49.46%)
 * Likes:    5633
 * Dislikes: 102
 * Total Accepted:    383.7K
 * Total Submissions: 775.5K
 * Testcase Example:
 '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n' +
  '[[],[1],[2],[],[3],[]]'
 *
 * The median is the middle value in an ordered integer list. If the size of
 * the list is even, there is no middle value and the median is the mean of the
 * two middle values.
 *
 *
 * For example, for arr = [2,3,4], the median is 3.
 * For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
 *
 *
 * Implement the MedianFinder class:
 *
 *
 * MedianFinder() initializes the MedianFinder object.
 * void addNum(int num) adds the integer num from the data stream to the data
 * structure.
 * double findMedian() returns the median of all elements so far. Answers
 * within 10^-5 of the actual answer will be accepted.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
 * [[], [1], [2], [], [3], []]
 * Output
 * [null, null, null, 1.5, null, 2.0]
 *
 * Explanation
 * MedianFinder medianFinder = new MedianFinder();
 * medianFinder.addNum(1);    // arr = [1]
 * medianFinder.addNum(2);    // arr = [1, 2]
 * medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
 * medianFinder.addNum(3);    // arr[1, 2, 3]
 * medianFinder.findMedian(); // return 2.0
 *
 *
 *
 * Constraints:
 *
 *
 * -10^5 <= num <= 10^5
 * There will be at least one element in the data structure before calling
 * findMedian.
 * At most 5 * 10^4 calls will be made to addNum and findMedian.
 *
 *
 *
 * Follow up:
 *
 *
 * If all integer numbers from the stream are in the range [0, 100], how would
 * you optimize your solution?
 * If 99% of all integer numbers from the stream are in the range [0, 100], how
 * would you optimize your solution?
 *
 *
 */

#include <queue>
#include <vector>

// @lc code=start
class MedianFinder {
public:
  MedianFinder() {
  }

  void addNum(int num) {
    // 添加元素
    if (small.size() >= big.size()) {
      small.push(num);
      int top = small.top();
      small.pop();
      big.push(top);
    } else {
      big.push(num);
      int top = big.top();
      big.pop();
      small.push(top);
    }
  }

  double findMedian() {
    // 如果大根堆元素多，返回大根堆的栈顶
    if (big.size() > small.size()) {
      return big.top() * 1.0;
    } else if (big.size() < small.size()) {
      // 如果小根堆元素多，返回小根堆的栈顶
      return small.top() * 1.0;
    } else {
      // 如果元素一样多，返回两者栈顶之和的一半
      return (small.top() + big.top()) / 2.0;
    }
  }

private:
  struct greator {
    bool operator()(const int &a, const int &b) const {
      return a > b;
    }
  };

  std::priority_queue<int, std::vector<int>>          big;    // 默认大根堆
  std::priority_queue<int, std::vector<int>, greator> small;  // 小根堆
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
