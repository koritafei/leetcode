/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (38.68%)
 * Likes:    11167
 * Dislikes: 441
 * Total Accepted:    928K
 * Total Submissions: 2.4M
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
  LRUCache(int capacity) : capacity(capacity), size(0) {
  }

  int get(int key) {
    if (keyIter.count(key) == 0) {
      return -1;
    }

    std::list<std::pair<int, int>>::iterator iter = keyIter[key];
    int                                      val  = iter->second;

    updateKV(key, val);

    return val;
  }

  void put(int key, int value) {
    if (keyIter.count(key)) {
      updateKV(key, value);
      return;
    }

    if (size == capacity) {
      // 移除最后一个元素
      auto iter = cache.back();
      cache.pop_back();
      keyIter.erase(iter.first);
      size--;
    }

    cache.push_front(std::make_pair(key, value));
    keyIter[key] = cache.begin();
    size++;
  }

private:
  void updateKV(int key, int val) {
    std::list<std::pair<int, int>>::iterator iter = keyIter[key];

    // 调整位置
    cache.erase(iter);
    cache.push_front(std::make_pair(key, val));
    keyIter[key] = cache.begin();
  }

  int                            capacity;  // 容量
  int                            size;
  std::list<std::pair<int, int>> cache;  // cache
  std::unordered_map<int, std::list<std::pair<int, int>>::iterator> keyIter;  //
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
