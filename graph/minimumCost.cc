#include <algorithm>
#include <vector>

class UF {
public:
  UF(int n) {
    parent_ = std::vector<int>(n, -1);
    weight_ = std::vector<int>(n, 0);
    count_  = n;
    for (int i = 0; i < n; i++) {
      parent_[i] = i;
      weight_[i] = 0;
    }
  }

  void connect(int p, int q) {
    int rootp = find(p);
    int rootq = find(q);
    if (rootp == rootq) {
      return;
    }

    if (weight_[rootp] < weight_[rootq]) {
      weight_[rootp] += weight_[rootq];
      parent_[rootq] = rootp;
    } else {
      weight_[rootq] += weight_[rootq];
      parent_[rootp] = rootq;
    }
  }

  bool connected(int p, int q) {
    int rootp = find(p);
    int rootq = find(q);

    return rootp == rootq;
  }

  int count() const {
    return count_;
  }

  int find(int v) {
    while (v != parent_[v]) {
      parent_[v] = parent_[parent_[v]];
      v          = parent_[v];
    }

    return v;
  }

private:
  int              count_;   // 连通分量个数
  std::vector<int> weight_;  // 权重数组
  std::vector<int> parent_;  // 连通分量父节点数组
};

int minimumCost(int n, std::vector<std::vector<int>> &connections) {
  UF  uf(n + 1);
  int mst = 0;
  std::sort(connections.begin(),
            connections.end(),
            [](std::vector<int> &a, std::vector<int> &b) {
              return a[2] < b[2];
            });

  for (int i = 0; i < n; i++) {
    int u = connections[i][0];
    int v = connections[i][1];
    int w = connections[i][2];

    if (uf.connected(u, v)) {
      continue;
    }

    mst += w;
    uf.connect(u, v);
  }

  return uf.count() == 2 ? mst : -1;
}