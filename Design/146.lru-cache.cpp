/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (38.35%)
 * Likes:    10715
 * Dislikes: 427
 * Total Accepted:    899.2K
 * Total Submissions: 2.3M
 * Testcase Example:
 '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design a data structure that follows the constraints of a Least Recently
 * Used (LRU) cache.
 *
 * Implement the LRUCache class:
 *
 *
 * LRUCache(int capacity) Initialize the LRU cache with positive size
 * capacity.
 * int get(int key) Return the value of the key if the key exists, otherwise
 * return -1.
 * void put(int key, int value) Update the value of the key if the key exists.
 * Otherwise, add the key-value pair to the cache. If the number of keys
 * exceeds the capacity from this operation, evict the least recently used
 * key.
 *
 *
 * The functions get and put must each run in O(1) average time complexity.
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * Output
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 *
 * Explanation
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // cache is {1=1}
 * lRUCache.put(2, 2); // cache is {1=1, 2=2}
 * lRUCache.get(1);    // return 1
 * lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
 * lRUCache.get(2);    // returns -1 (not found)
 * lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
 * lRUCache.get(1);    // return -1 (not found)
 * lRUCache.get(3);    // return 3
 * lRUCache.get(4);    // return 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= capacity <= 3000
 * 0 <= key <= 10^4
 * 0 <= value <= 10^5
 * At most 2 * 10^5 calls will be made to get and put.
 *
 *
 */

#include <list>
#include <unordered_map>

// @lc code=start

class LRUCache {
public:
  typedef std::list<std::pair<int, int>>::iterator node;

  LRUCache(int capacity)
      : capacity_(capacity), head_(new std::list<std::pair<int, int>>) {
  }

  int get(int key) {
    if (map_.count(key) == 0) {
      return -1;
    }
    node val = map_[key];
    int  res = val->second;
    // 删除老节点
    map_.erase(key);
    head_->erase(val);
    // 构造一个新节点,并插入头部
    head_->push_front(std::make_pair(key, res));
    map_[key] = head_->begin();
    return res;
  }

  void put(int key, int value) {
    // 判断是否已经存在这个key
    if (map_.count(key)) {
      // 已经存在
      // 删除老节点，并插入头部
      node old = map_[key];
      map_.erase(key);
      head_->erase(old);
    } else {
      // 不存在
      if (map_.size() == capacity_) {
        // 已满，移除最后一个
        int key = head_->back().first;
        head_->pop_back();
        map_.erase(key);
      }
    }
    head_->push_front(std::make_pair(key, value));
    map_[key] = head_->begin();
  }

private:
  std::list<std::pair<int, int>> *head_;  // 存储数据
  std::unordered_map<int, node>   map_;   // 存储key， node*
  const int                       capacity_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
