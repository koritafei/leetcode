/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (62.46%)
 * Likes:    4620
 * Dislikes: 261
 * Total Accepted:    555.5K
 * Total Submissions: 889.3K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 *
 * Example 1:
 *
 *
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1], k = 1
 * Output: [1]
 *
 *
 * Note:
 *
 *
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * It's guaranteed that the answer is unique, in other words the set of the top
 * k frequent elements is unique.
 * You can return the answer in any order.
 *
 *
 */

// @lc code=start
class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    std::vector<int> res;
    if (k <= 0) {
      return res;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
                            heap;
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
      m[nums[i]]++;
    }

    for (auto it = m.begin(); it != m.end(); it++) {
      if (heap.size() == k) {
        if (it->second > heap.top().first) {
          heap.pop();
          heap.push(make_pair(it->second, it->first));
        }
      } else {
        heap.push(make_pair(it->second, it->first));
      }
    }

    while (heap.size()) {
      res.push_back(heap.top().second);
      heap.pop();
    }

    return res;
  }
};
// @lc code=end
