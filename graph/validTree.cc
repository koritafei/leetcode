
#include <vector>

// union find
class UF {
public:
  // 初始化
  UF(int n) {
    uf_     = std::vector<int>(n, -1);
    weight_ = std::vector<int>(n, 0);
    count_  = n;

    for (int i = 0; i < n; i++) {
      uf_[i]     = i;
      weight_[i] = 1;
    }
  }

  // 连接p,q节点
  void connect(int p, int q) {
    int rootP = find(p);
    int rootQ = find(q);
    if (rootQ == rootP) {
      return;
    }

    if (weight_[rootP] < weight_[rootQ]) {
      // 链接到小根节点
      weight_[rootP] += weight_[rootQ];
      uf_[rootQ] = rootP;
    } else {
      weight_[rootQ] += weight_[rootP];
      uf_[rootP] = rootP;
    }

    count_--;
  }

  // 判断是否连通
  bool isConnect(int p, int q) {
    int rootq = find(q);
    int rootp = find(p);
    return rootq == rootq;
  }

  // 查找父节点
  int find(int q) {
    if (q != uf_[q]) {
      uf_[q] = uf_[uf_[q]];  // 路径压缩
      q      = uf_[q];
    }

    return q;
  }

  int count() const {
    return count_;
  }

private:
  std::vector<int> uf_;      // 存储一颗树
  std::vector<int> weight_;  // 权重
  int              count_;   // 连通分量个数
};

class Solution {
public:
  // 给定一个边集，判断这个边集能否构成一棵树
  bool validTree(int n, std::vector<std::vector<int>> edges) {
    // 初始化0~n-1个节点
    UF uf(n);
    for (auto item : edges) {
      int p = item[0];
      int q = item[1];
      if (uf.isConnect(p, q)) {
        return false;
      }

      uf.connect(p, q);
    }

    return uf.count() == 1;
  }
};