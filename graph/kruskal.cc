#include <map>
#include <vector>

class Solution {
public:
  // 给定一个边集，判断这个边集能否构成一棵树
  bool validTree(int n, std::vector<std::vector<int>> edges) {
    UF uf(n);

    for (auto &item : edges) {
      if (uf.isConnect(item[0], item[1])) {
        return false;
      }

      uf.connect(item[0], item[1]);
    }

    return uf.count() == 1;
  }

private:
  class UF {
  public:
    UF(int n) {
      _parent = std::vector<int>(n, 0);
      _weight = std::vector<int>(n, 1);
      _count  = n;
      for (int i = 0; i < n; i++) {
        _parent[i] = i;
      }
    }

    bool isConnect(int p, int q) {
      int pParent = findParent(p);
      int qParent = findParent(q);

      return pParent == qParent;
    }

    int findParent(int p) {
      if (p != _parent[p]) {
        _parent[p] = _parent[_parent[p]];
        p          = _parent[p];
      }

      return p;
    }

    void connect(int p, int q) {
      if (isConnect(p, q)) {
        return;
      }

      int pParent = findParent(p);
      int qParent = findParent(q);

      _count--;

      if (_weight[pParent] > _weight[qParent]) {
        _weight[qParent] += _weight[pParent];
        _parent[pParent] = _parent[qParent];
      } else {
        _weight[pParent] += _weight[qParent];
        _parent[qParent] = _parent[pParent];
      }
    }

    int count() const {
      return _count;
    }

  private:
    std::vector<int> _parent;
    std::vector<int> _weight;
    int              _count;  // 联通分量个数
  };
};