#include <vector>

class UF {
public:
  UF(int n) {
    count  = n;  // 初始n个节点互不连通
    parent = std::vector<int>(n, 0);

    for (int i = 0; i < n; ++i) {
      parent[i] = i;
      weight[i] = 1;
    }
  }

  // 连通两个节点
  void Union(int p, int q) {
    int rootP = Find(p);
    int rootQ = Find(q);

    if (rootQ == rootP) {
      return;
    }

    if (weight[rootP] >= weight[rootQ]) {
      parent[rootP] = rootQ;
      weight[rootP] += weight[rootQ];
    } else {
      parent[rootQ] = rootP;
      weight[rootQ] += weight[rootP];
    }

    count--;  // 连通分量个数减一
  }

  // 查找当前节点的parent
  int Find(int x) {
    while (x != parent[x]) {
      parent[x] = parent[parent[x]];
      x         = parent[x];
    }

    return x;
  }

  int Count() const {
    // 返回连通分量个数
    return count;
  }

  bool isConnect(int p, int q) {
    int rootP = Find(p);
    int rootQ = Find(q);

    return rootP == rootQ;
  }

private:
  int              count;   // 连通分量个数
  std::vector<int> parent;  // 节点x的父节点为parent[x]
  std::vector<int> weight;  // 树的重量
};
