/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 *
 * https://leetcode.com/problems/lfu-cache/description/
 *
 * algorithms
 * Hard (38.55%)
 * Likes:    2698
 * Dislikes: 185
 * Total Accepted:    134.4K
 * Total Submissions: 348.6K
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

#include <list>
#include <unordered_map>

// @lc code=start
class LFUCache {
public:
  typedef std::list<std::pair<int, int>>::iterator Iter;
  typedef std::list<int>::iterator                 listIter;

  LFUCache(int capacity) : capacity(capacity), size(0), minFreq(1) {
  }

  int get(int key) {
    // 不存在
    if (capacity == 0 || keyIter.find(key) == keyIter.end()) {
      return -1;
    }

    // 存在更新freq
    int val = keyIter[key]->second;

    // 更新freq
    update(key);

    return val;
  }

  void put(int key, int value) {
    if (capacity == 0) {
      return;
    }

    // 存在
    if (keyIter.find(key) != keyIter.end()) {
      Iter it    = keyIter[key];
      it->second = value;
      update(key);
      return;
    }

    // 不存在
    if (size >= capacity) {
      remove();
      size--;
    }

    // 插入新的节点
    kv.push_front(std::make_pair(key, value));
    keyIter[key] = kv.begin();
    freqKeys[1].push_front(key);
    keyFreq[key] = std::make_pair(1, freqKeys[1].begin());
    minFreq      = 1;
    size++;
  }

private:
  void remove() {
    int key = freqKeys[minFreq].back();

    freqKeys[minFreq].pop_back();
    if (freqKeys[minFreq].empty()) {
      freqKeys.erase(minFreq);
    }

    Iter iter = keyIter[key];
    keyIter.erase(key);
    kv.erase(iter);
    keyFreq.erase(key);
  }

  void update(int key) {
    std::pair<int, listIter> freqIter = keyFreq[key];

    int      freq = freqIter.first;
    listIter iter = freqIter.second;

    // 从freqKeys删除指定key
    freqKeys[freq].erase(iter);

    if (freqKeys[freq].empty()) {
      freqKeys.erase(freq);
      if (minFreq == freq) {
        minFreq++;
      }
    }

    // 插入新的freq中
    int newfreq = ++freq;
    freqKeys[newfreq].push_front(key);
    keyFreq[key] = std::make_pair(newfreq, freqKeys[newfreq].begin());
  }

  int minFreq;   // 最小频率
  int capacity;  // 容量
  int size;      // 使用的大小

  std::unordered_map<int, std::pair<int, listIter>>
      keyFreq;  // 存储key,freq,freq_iterator对应关系
  std::list<std::pair<int, int>>          kv;        // <key, val>
  std::unordered_map<int, Iter>           keyIter;   // <key, iterator>
  std::unordered_map<int, std::list<int>> freqKeys;  // freq对应的key列表
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
