#include <climits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

class graph {
public:
  // 输入一幅图graph,和一个起点start,计算start到其他节点的距离
  std::vector<int> dijkstra(int start, int n) {
    std::priority_queue<state, std::vector<state>, greator> minHeap;

    std::vector<int> res(n, INT_MAX);
    res[start] = 0;
    minHeap.push(state(start, 0));

    while (minHeap.size()) {
      state curr = minHeap.top();
      minHeap.pop();

      if (res[curr.id] < curr.dist) {
        continue;  // 已存在最小距离，跳过
      }

      for (auto &item : graph[curr.id]) {
        int dist = curr.dist + item.second;
        if (res[item.first] > dist) {
          res[item.first] = dist;
          minHeap.push(state(item.first, dist));
        }
      }
    }

    return res;
  }

private:
  struct state {
    int id;    // 当前图顶点
    int dist;  // 到达当前顶点的距离

    state(int id, int dist) : id(id), dist(dist) {
    }
  };

  // 仿函数，构建小跟堆
  struct greator {
    bool operator()(const state &s1, const state &s2) {
      return s1.dist > s2.dist;
    }
  };

  std::map<int, std::vector<std::pair<int, int>>>
      graph;  // 图，起点，终点，weight
};
