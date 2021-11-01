/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (36.64%)
 * Likes:    8658
 * Dislikes: 354
 * Total Accepted:    775.3K
 * Total Submissions: 2.1M
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
 * Follow up:
 * Could you do get and put in O(1) time complexity?
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
 * 0 <= key <= 3000
 * 0 <= value <= 10^4
 * At most 3 * 10^4 calls will be made to get and put.
 *
 *
 */

#include <cstddef>
#include <iostream>
#include <map>
#include <unordered_map>

// @lc code=start
class LRUCache {
public:
  LRUCache(int capacity) : head(nullptr), tail(nullptr), _capacity(capacity) {
  }

  ~LRUCache() {
    while (head) {
      Node* tmp = head;
      head      = head->next;
      delete tmp;
    }
  }

  int get(int key) {
    Node* node = map[key];
    if (nullptr == node) {
      return -1;
    } else {
      // 当前node放置到末尾
      moveToBack(node);
      return node->_val.second;
    }
  }

  void put(int key, int value) {
    Node* node = map[key];
    if (nullptr == node) {
      // node 不存在
      node = new Node(key, value);
      // 插入尾部
      insertNodeTail(node);
      _count++;
      checkCapacity();
    } else {
      node->_val.second = value;
      moveToBack(node);
    }
  }

private:
  struct Node {
    std::pair<int, int> _val;  // <key,value>对
    Node*               next;
    Node*               prev;

    Node(int key, int value)
        : _val(std::make_pair(key, value)), next(nullptr), prev(nullptr) {
    }
  };

  void checkCapacity() {
    if (_count > _capacity) {
      // 超出容量，删除队头
      Node* tmp = head;
      head      = head->next;
      _count--;
      map.erase(tmp->_val.first);
      delete tmp;
    }
  }

  void insertNodeTail(Node* node) {
    map[node->_val.first] = node;
    if (head == nullptr) {
      head = tail = node;
      return;
    }

    tail->next = node;
    node->prev = tail;
    tail       = tail->next;
  }

  void moveToBack(Node* node) {
    if (node == tail) {
      return;
    } else if (head == node) {
      head       = head->next;
      head->prev = nullptr;
    } else {
      node->prev->next = node->next;
      node->next->prev = node->prev;
    }

    tail->next = node;
    node->prev = tail;
    node->next = nullptr;
    tail       = tail->next;
  }

  std::unordered_map<int, Node*> map;
  Node*                          head;       // 链表头
  Node*                          tail;       // 链表尾
  int                            _capacity;  // cache容量
  int                            _count;     // 当前cache元素个数
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main(int argc, char** argv) {
  LRUCache* lRUCache = new LRUCache(2);
  lRUCache->put(1, 1);                         // cache is {1=1}
  lRUCache->put(2, 2);                         // cache is {1=1, 2=2}
  std::cout << lRUCache->get(1) << std::endl;  // return 1
  lRUCache->put(3, 3);  // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
  std::cout << lRUCache->get(2) << std::endl;  // returns -1 (not found)
  lRUCache->put(4, 4);  // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
  std::cout << lRUCache->get(1) << std::endl;  // return -1 (not found)
  std::cout << lRUCache->get(3) << std::endl;  // return 3
  std::cout << lRUCache->get(4) << std::endl;  // return 4
}
