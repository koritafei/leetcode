/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (63.94%)
 * Likes:    6719
 * Dislikes: 315
 * Total Accepted:    744.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given an integer array nums and an integer k, return the k most frequent
 * elements. You may return the answer in any order.
 *
 *
 * Example 1:
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * Example 2:
 * Input: nums = [1], k = 1
 * Output: [1]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * k is in the range [1, the number of unique elements in the array].
 * It is guaranteed that the answer is unique.
 *
 *
 *
 * Follow up: Your algorithm's time complexity must be better than O(n log n),
 * where n is the array's size.
 *
 */

#include <map>
#include <queue>
#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
    std::map<int, int> freq;  // 统计出现频率
    std::vector<int>   res;   // 结果集

    for (auto it : nums) {
      freq[it]++;
    }

    std::priority_queue<std::pair<int, int>,
                        std::vector<std::pair<int, int>>,
                        greator>
        heap;

    for (auto it = freq.begin(); it != freq.end(); it++) {
      heap.push(std::make_pair(it->first, it->second));
      while (heap.size() > k) {
        heap.pop();
      }
    }

    while (heap.size()) {
      res.push_back(heap.top().first);
      heap.pop();
    }

    std::reverse(res.begin(), res.end());

    return res;
  }

private:
  struct greator {  // 小跟堆
    bool operator()(const std::pair<int, int> &p1,
                    const std::pair<int, int> &p2) {
      return p1.second >= p2.second;
    }
  };
};
// @lc code=end
