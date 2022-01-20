
#include <cstddef>
#include <map>
#include <string>
#include <vector>

template <typename T>
class TrieMap {
public:
  int size() const {
    return _size;
  }

  // 搜索key对应的值，不存在返回nullptr
  T getKey(std::string key) {
    // 从root开始搜索key
    TrieNode<T> *x = getNode(root, key);
    if (x == nullptr || x->val == nullptr) {
      return NULL;
    }

    return x->val;
  }

  // 判断key 是否存在map中
  bool containsKey(std::string &key) {
    return getKey(key) == NULL;
  }

  // 判断是否存在prefix的键
  bool hasKeyWithPrefix(std::string &prefix) {
    return containsKey(prefix);
  }

  // 在所有键中查找query的最短前缀
  std::string shortestPrefixOf(std::string &query) {
    TrieNode<T> *node = root;

    // 从根节点开始搜索
    for (int i = 0; i < query.length(); i++) {
      if (nullptr == node) {
        return "";
      }

      if (node->val != nullptr) {
        // 此时表示已经存在一个前缀，直接返回即可
        // 找到一个键是query的前缀
        return query.substr(0, i);
      }

      // 向下搜索
      node = node->chridlen[query[i]];
    }

    if (node != nullptr && node->val != nullptr) {
      // 如果query 本身就是一个键， 没有query子串的前缀
      return query;
    }

    return "";
  }

  std::string longestPrefixOf(std::string &query) {
    TrieNode<T> *node   = root;
    int          maxlen = 1;  // 记录最大长度
    for (int i = 0; i < query.length(); i++) {
      if (node == nullptr) {
        return "";
      }

      if (node->val != nullptr) {
        maxlen = i;
      }

      node = node->chridlen[query[i]];
    }

    if (node != nullptr && node->val != nullptr) {
      return query;
    }

    return query.substr(0, maxlen);
  }

  // 搜索前缀为prefix的所有键
  std::vector<std::string> keysWithPrefix(std::string prefix) {
    std::vector<std::string> res;

    // 找到在trietree中Trie上的节点
    TrieNode<T> *x = getNode(root, prefix);

    if (nullptr == x) {
      return res;
    }

    // DFS 以当前的root为根遍历树
    traverse(x, prefix, res);

    return res;
  }

  std::vector<std::string> keysWithPattern(std::string &pattern) {
    std::vector<std::string> res;
    std::string              path;
    traverse(root, path, pattern, 0, res);
    return res;
  }

  bool hasKeyWithPattern(std::string &pattern) {
    return hasKeyWithPattern(root, pattern, 0);
  }

  void put(std::string &key, T &val) {
    if (!containsKey(key)) {
      _size++;  // 新增键值对
    }

    root = put(root, key, val, 0);
  }

  void remove(std::string &key) {
    if (!containsKey(key)) {
      return;
    }

    // 递归修改数据结构
    root = remove(root, key, 0);
    --_size;
  }

private:
  template <typename V>
  struct TrieNode {
    V *val;  // 存储key对应的value, 不为空时表示存在一个key
    TrieNode<V>
        *chridlen;  // 存储指向子节点的指针, 从root到当前节点路径的字符串为key

    TrieNode() : val(0), chridlen(new TrieNode[R]) {
    }

    TrieNode(V val) : val(val), chridlen(new TrieNode[R]) {
    }
  };

  TrieNode<T> *root;  // trietree 的根节点

  static const int R     = 256;  // ascii码个数
  int              _size = 0;    // 当前map中存储的键值对

  // 从节点node开始搜索key，如果存在返回node，否则返回nullptr
  TrieNode<T> *getNode(TrieNode<T> *node, std::string key) {
    TrieNode<T> *p = node;
    // 从节点node开始搜索key
    for (int i = 0; i < key.length(); i++) {
      if (nullptr == p) {
        // 无法向下搜索，返回nullptr
        return nullptr;
      }

      // 向下搜索
      p = p->chridlen[key[i]];
    }

    return p;
  }

  // 遍历以node为根的trietree找到所有的key
  void traverse(TrieNode<T>              *node,
                std::string              &path,
                std::vector<std::string> &res) {
    if (nullptr == node) {
      // 达到底部，直接返回
      return;
    }

    if (node->val != nullptr) {
      // 找到一个结果加入到结果列表
      res.push_back(path);
    }

    // 回溯法遍历框架
    for (int i = 0; i < R; i++) {
      // 做选择
      path.push_back(node->val);
      // 递归
      traverse(node->chridlen[i], path, res);
      // 撤销选择
      path.pop_back();
    }
  }

  // 含有通配符的遍历
  void traverse(TrieNode<T>              *node,
                std::string              &path,
                std::string              &parttern,
                int                       i,
                std::vector<std::string> &res) {
    if (nullptr == node) {
      return;
    }

    if (i == parttern.size()) {
      // parttern 匹配完成
      if (nullptr == node->val) {
        res.push_back(path);
      }

      return;
    }

    char ch = parttern[i];
    if (parttern[ch] == '.') {
      // 通配符可以匹配任意字符
      for (char j = 0; j < R; j++) {
        path.push_back(j);
        traverse(node->chridlen[j], path, parttern, i + 1, res);
        path.pop_back();
      }
    } else {
      path.push_back(parttern[i]);
      traverse(node->chridlen[ch], path, parttern, i + 1, res);
      path.pop_back();
    }
  }

  bool keyWithPattern(TrieNode<T> *node, std::string pattern, int i) {
    if (node == nullptr) {
      return false;
    }

    if (i == pattern.size()) {
      // 匹配到末尾，检查是否匹配到key
      return node->val != nullptr;
    }

    char ch = pattern[i];

    // 没有遇到通配符
    if (ch != '.') {
      // 从node children节点开始匹配pattern[i+1...]
      return hasKeyPattern(node->chridlen[ch], pattern, i + 1);
    }

    for (char j = 0; j < R; j++) {
      if (hasKeyWithPattern(node->chridlen[j], pattern, i + 1)) {
        return true;
      }
    }

    return false;
  }

  TrieNode<T> *put(TrieNode<T> *node, std::string &key, T val, int i) {
    if (nullptr == node) {
      node = new TrieNode<T>;
    }

    if (i == key.length()) {
      // key 的路径插入完成，将val值存入节点
      node->val = val;
      return node;
    }

    char ch            = key[i];
    node->chridlen[ch] = put(node->chridlen[ch], key, val, i + 1);

    return node;
  }

  // 定义： 以node为根的Trie树删除key[i...], 返回删除后剩余节点
  TrieNode<T> *remove(TrieNode<T> *node, std::string &key, int i) {
    if (nullptr == node) {
      return node;
    }

    if (i == key.length()) {
      // 找到对应的key，删除val
      node->val = nullptr;
    } else {
      // 递归去子树删除
      char ch            = key[i];
      node->chridlen[ch] = remove(node->chridlen[ch], key, i + 1);
    }

    // 后序位置，递归路径上的子树可能被清理
    if (node->val != nullptr) {
      return node;
    }

    // 检查trienode是否存在后缀
    for (int j = 0; j < R; j++) {
      if (nullptr != node->chridlen[j]) {
        return node;  // 只要存在一个子树，就不需要清理
      }
    }

    return nullptr;
  }
};