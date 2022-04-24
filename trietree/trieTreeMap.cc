
#include <cstddef>
#include <list>
#include <map>
#include <memory>
#include <string>
#include <vector>

#define NOT_EXISTS -1

template <typename T>
class TrieMap {
public:
  // 增/改
  // map 中添加key
  void put(std::string &key, T &val) {
    if (!containsKey(key)) {
      size_++;
    }

    put(root, key, val, 0);
  }

  // 删
  void remove(std::string &key) {
    if (!containsKey(key)) {
      return;
    }

    root = remove(root, key, 0);
    size_--;
  }

  // 搜索key对应的值，不存在放回nullptr
  T get(std::string &key) {
    std::shared_ptr<TrieNode> node = getNode(root, key);

    if (node == nullptr || node->val == nullptr) {
      return NOT_EXISTS;
    }

    return *(node->val);
  }

  // 判断key是否存在在map中
  bool containsKey(std::string &key) {
    TrieNode p = getNode(root, key);
    return p != nullptr && p->val != nullptr;
  }

  // 在Map的所有键中搜索query的最小前缀
  std::string shortestPrefix(std::string &query) {
    std::shared_ptr<TrieNode> p = root;
    // 从node节点开始搜索key
    for (int i = 0; i < query.size(); i++) {
      if (p == nullptr) {
        return "";
      }

      if (p->val != nullptr) {
        return query.substr(0, i);
      }

      p = p->children[query[i]];
    }

    // query 本身是一个前缀
    if (p != nullptr && p->val != nullptr) {
      return query;
    }

    return "";
  }

  // 在Map的所有键所有query的最长前缀
  std::string longestPrefix(std::string &query) {
    std::shared_ptr<TrieNode> p      = root;
    int                       maxlen = 0;
    for (int i = 0; i < query.length(); i++) {
      if (p == nullptr) {
        return "";
      }

      if (p->val != nullptr) {
        maxlen = i;
      }

      p = p->children[query[i]];
    }

    if (p != nullptr && p->val != nullptr) {
      return query;
    }

    return query.substr(0, maxlen);
  }

  // 搜索所有前缀为prefix的键
  std::list<std::string> keysWithPrefix(std::string &prefix) {
    std::list<std::string> res;

    TrieNode   *p = getNode(root, prefix);
    std::string path;

    if (p == nullptr) {
      return res;
    }

    traverse(p, path, res);

    return res;
  }

  // 判断是否存在键为prefix的键
  bool hasKeyWithPrefix(std::string &prefix) {
    return getNode(root, prefix) != nullptr;
  }

  // 搜索匹配模式的字符串
  std::list<std::string> keysWithPattern(std::string &pattern) {
    std::string            path;
    std::list<std::string> res;

    traverse(root, path, pattern, 0, res);

    return res;
  }

  //通配符 . 匹配任意字符，判断是否存在匹配的键
  bool hasKeyWithPattern(std::string &pattern) {
    return hasKeyWithPattern(root, pattern, 0);
  }

  // 大小
  int size() const {
    return size_;
  }

private:
  struct TrieNode {
  public:
    TrieNode()
        : val(nullptr), children(std::vector<std::shared_ptr<TrieNode>>(R)) {
    }

  private:
    std::shared_ptr<T>                     val;
    std::vector<std::shared_ptr<TrieNode>> children;
  };

  std::shared_ptr<TrieNode> getNode(std::shared_ptr<TrieNode> node,
                                    std::string              &key) {
    std::shared_ptr<TrieNode> p = node;
    // 从节点node，开始搜索key
    for (int i = 0; i < key.length(); i++) {
      if (p == nullptr) {
        return nullptr;
      }
      p = p->children[key[i]];
    }
    return p;
  }

  void traverse(std::shared_ptr<TrieNode> node,
                std::string              &path,
                std::list<std::string>   &res) {
    if (nullptr == node) {  // 到达底部
      return;
    }

    if (node->val != nullptr) {
      res.push_back(path);
    }

    // 回溯
    for (char c = 0; c < R; c++) {
      path.push_back(c);
      traverse(node->children[c], path, res);
      path.pop_back();
    }
  }

  void traverse(std::shared_ptr<TrieNode> node,
                std::string              &path,
                std::string              &pattern,
                int                       i,
                std::list<std::string>   &res) {
    if (node == nullptr) {
      return;
    }

    if (i == pattern.length()) {
      if (node->val != nullptr) {
        res.push_back(path);
      }

      return;
    }

    char c = pattern[i];

    if (c == '.') {
      for (char j = 0; j < pattern.length(); j++) {
        path.push_back(j);
        traverse(node->children[j], path, pattern, i + 1, res);
        path.pop_back();
      }
    } else {
      path.push_back(c);
      traverse(node->children[c], path, pattern, i + 1, res);
      path.pop_back();
    }
  }

  bool hasKeyWithPattern(std::shared_ptr<TrieNode> node,
                         std::string              &pattern,
                         int                       i) {
    if (node == nullptr) {
      return false;
    }

    if (i == pattern.length()) {
      return node->val != nullptr;
    }

    char c = pattern[i];
    if (c != '.') {
      return traverse(node->children[c], pattern, i + 1);
    }

    for (char j = 0; j < R; j++) {
      if (traverse(node->children[j], pattern, i + 1)) {
        return true;
      }
    }

    return false;
  }

  void put(std::shared_ptr<TrieNode> node, std::string &key, T &val, int i) {
    if (nullptr == node) {
      node = std::make_shared<TrieNode>();
    }

    if (i == key.length()) {
      node->val = std::make_shared<T>(val);
      return node;
    }

    char c            = key[i];
    node->children[c] = put(node->children[c], key, val, i + 1);
    return node;
  }

  std::shared_ptr<TrieNode> remove(std::shared_ptr<TrieNode> node,
                                   std::string              &key,
                                   int                       i) {
    if (nullptr == node) {
      return nullptr;
    }

    if (i == key.length()) {
      node->val = nullptr;
    } else {
      char c            = key[i];
      node->children[i] = remove(node->childe[c], key, i + 1);
    }

    if (nullptr != node) {
      return node;
    }

    for (char c = 0; c < R; c++) {
      if (nullptr != node->children[c]) {
        return node;
      }
    }

    return nullptr;
  }

  static const int R = 256;

  int                       size_;
  std::shared_ptr<TrieNode> root;
};