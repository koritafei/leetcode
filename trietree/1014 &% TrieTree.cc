#include <iostream>
#include <map>
#include <string>

class TrieTree {
public:
  TrieTree() {
    root = new TrieNode;
  }

  // 增加一个字符串
  void add(std::string &str) {
    TrieNode *curr = root;
    for (int i = 0; i < str.size(); i++) {
      if (curr->next.find(str[i]) == curr->next.end()) {
        curr->next[str[i]] = new TrieNode;
      }
      curr->path++;
      curr = curr->next[str[i]];
    }
    curr->end++;
  }

  // search
  bool search(std::string &str) {
    TrieNode *curr = root;
    for (int i = 0; i < str.size(); i++) {
      if (curr->next.find(str[i]) == curr->next.end()) {
        return false;
      }
      curr = curr->next[str[i]];
    }

    return true;
  }

  // 删除一个字符串
  void delstr(std::string &str) {
    if (!search(str)) {
      return;
    }
    TrieNode *curr = root;

    for (int i = 0; i < str.size(); i++) {
      if (curr->next[str[i]]->path-- == 1) {
        curr->next[str[i]] = nullptr;
        return;
      }
    }
    curr->end--;
  }

  // 查询前缀
  int prefix(std::string &str) {
    int len = str.size();
    if (0 == len) {
      return 0;
    }

    TrieNode *curr = root;
    for (int i = 0; i < len; i++) {
      if (curr->next.find(str[i]) == curr->next.end()) {
        return 0;
      }
      curr = curr->next[str[i]];
    }

    return curr->path;
  }

private:
  struct TrieNode {
    std::map<char, TrieNode *> next;
    int                        path;
    int                        end;
    TrieNode() : path(0), end(0) {
    }
  };

  TrieNode *root;
};

int main(int argc, char **argv) {
  int         m = 0;
  std::string str;
  TrieTree    tree;
  std::cin >> m;
  while (m--) {
    std::cin >> str;
    tree.add(str);
  }

  std::cin >> m;
  while (m--) {
    std::cin >> str;
    std::cout << tree.prefix(str) << std::endl;
  }
}
