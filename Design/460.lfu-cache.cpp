/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 *
 * https://leetcode.com/problems/lfu-cache/description/
 *
 * algorithms
 * Hard (38.36%)
 * Likes:    2622
 * Dislikes: 180
 * Total Accepted:    131.5K
 * Total Submissions: 342.5K
 * Testcase Example:
 '["LFUCache","put","put","get","put","get","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for a Least Frequently Used (LFU)
 * cache.
 *
 * Implement the LFUCache class:
 *
 *
 * LFUCache(int capacity) Initializes the object with the capacity of the data
 * structure.
 * int get(int key) Gets the value of the key if the key exists in the cache.
 * Otherwise, returns -1.
 * void put(int key, int value) Update the value of the key if present, or
 * inserts the key if not already present. When the cache reaches its capacity,
 * it should invalidate and remove the least frequently used key before
 * inserting a new item. For this problem, when there is a tie (i.e., two or
 * more keys with the same frequency), the least recently used key would be
 * invalidated.
 *
 *
 * To determine the least frequently used key, a use counter is maintained for
 * each key in the cache. The key with the smallest use counter is the least
 * frequently used key.
 *
 * When a key is first inserted into the cache, its use counter is set to 1
 * (due to the put operation). The use counter for a key in the cache is
 * incremented either a get or put operation is called on it.
 *
 * The functions get and put must each run in O(1) average time complexity.
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get",
 * "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
 * Output
 * [null, null, null, 1, null, -1, 3, null, -1, 3, 4]
 *
 * Explanation
 * // cnt(x) = the use counter for key x
 * // cache=[] will show the last used order for tiebreakers (leftmost element
 * is  most recent)
 * LFUCache lfu = new LFUCache(2);
 * lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
 * lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
 * lfu.get(1);      // return 1
 * ⁠                // cache=[1,2], cnt(2)=1, cnt(1)=2
 * lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest,
 * invalidate 2.
 * // cache=[3,1], cnt(3)=1, cnt(1)=2
 * lfu.get(2);      // return -1 (not found)
 * lfu.get(3);      // return 3
 * ⁠                // cache=[3,1], cnt(3)=2, cnt(1)=2
 * lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate
 * 1.
 * ⁠                // cache=[4,3], cnt(4)=1, cnt(3)=2
 * lfu.get(1);      // return -1 (not found)
 * lfu.get(3);      // return 3
 * ⁠                // cache=[3,4], cnt(4)=1, cnt(3)=3
 * lfu.get(4);      // return 4
 * ⁠                // cache=[3,4], cnt(4)=2, cnt(3)=3
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= capacity <= 10^4
 * 0 <= key <= 10^5
 * 0 <= value <= 10^9
 * At most 2 * 10^5 calls will be made to get and put.
 *
 *
 *
 *
 */

#include <iostream>
#include <list>
#include <unordered_map>

// @lc code=start
class LFUCache {
public:
  LFUCache(int capacity) {
    _minFreq = 1;
    _cap     = capacity;
  }

  int get(int key) {
    if (!kvMap.count(key) || this->_cap <= 0) {
      return -1;
    }

    increaseFreq(key);
    return kvMap[key].first;
  }

  void put(int key, int value) {
    if (this->_cap <= 0) {
      return;
    }

    // 已存在key，更新频率
    if (kvMap.count(key)) {
      kvMap[key].first = value;
      increaseFreq(key);
      return;
    }

    // 不存在
    if (_size >= this->_cap) {
      // _cap已满，删除一个元素
      removeKeyFromkvMap();
      _size--;
    }

    // 插入一个元素
    kvMap[key] = std::make_pair(value, 1);
    freqKeysMap[1].push_back(key);  // 每次新插入元素，都在list的最后
    keyIter[key] = --freqKeysMap[1].end();
    // 每次新插入元素，minFreq 都重置为1
    this->_minFreq = 1;
    _size++;
  }

  void print() {
    for (auto it : kvMap) {
      std::cout << it.first << ' ' << it.second.first << ' ' << it.second.second
                << std::endl;
    }
    std::cout << std::endl;
  }

private:
  void increaseFreq(int key) {
    int freq = kvMap[key].second;
    kvMap[key].second++;  // 访问了一次，freq增加1

    std::list<int>::iterator it = keyIter[key];
    freqKeysMap[freq].erase(it);  // 从原freq中删除当前key

    if (freqKeysMap[freq].empty()) {
      freqKeysMap.erase(freq);
      if (this->_minFreq == freq) {  // 原freq中只有一个key，且为最小频率
        this->_minFreq++;
      }
    }
    // 在新的freq中插入key
    freqKeysMap[freq + 1].push_back(key);
    keyIter[key] = --freqKeysMap[freq + 1].end();
  }

  void removeKeyFromkvMap() {
    int key = freqKeysMap[_minFreq].front();
    freqKeysMap[_minFreq].pop_front();

    kvMap.erase(key);
    keyIter.erase(key);
    if (freqKeysMap[_minFreq].empty()) {
      freqKeysMap.erase(_minFreq);
    }
  }

  int                                          _minFreq;  // 最小的freq
  int                                          _cap;
  int                                          _size;
  std::unordered_map<int, std::pair<int, int>> kvMap;  // key-<val, frep> map
  std::unordered_map<int, std::list<int>::iterator>
                                          keyIter;      // key-iterator map
  std::unordered_map<int, std::list<int>> freqKeysMap;  // freq-keys map
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main(int argc, char** argv) {
  LFUCache* obj = new LFUCache(2);
  obj->put(1, 1);
  obj->print();
  obj->put(2, 2);
  obj->print();
  std::cout << "key 1 " << obj->get(1) << std::endl;
  obj->print();

  obj->put(3, 3);
  obj->print();

  std::cout << "key 2 " << obj->get(2) << std::endl;
  obj->print();
  std::cout << "key 3 " << obj->get(3) << std::endl;
  obj->print();
  obj->put(4, 4);
  obj->print();
  std::cout << "key 1 " << obj->get(1) << std::endl;
  obj->print();
  std::cout << "key 3 " << obj->get(3) << std::endl;
  obj->print();
  std::cout << "key 4 " << obj->get(4) << std::endl;
  obj->print();
}
