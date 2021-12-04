#include <climits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

class graph {
public:
  // 输入一幅图graph,和一个起点start,计算start到其他节点的距离
  std::vector<int> dijkstra(int start) {
    // 途中节点个数
    int v = graph.size();
    // 记录最短路径的权重数组
    std::vector<int> dis = std::vector<int>(v, INT_MAX);

    // base case
    dis[0] = 0;

    // 按照distFromStart排序的小跟堆
    std::priority_queue<state, std::vector<state>, less> heap;

    // 从起点开始进行BFS
    heap.push(state(start, 0));
    while (heap.size()) {
      state curstate = heap.top();
      heap.pop();
      int currid            = curstate.id;
      int currdistfromstart = curstate.distFromStart;

      if (currdistfromstart > dis[currid]) {
        // 已经有一条最短路径到达当前节点
        continue;
      }

      for (auto iter : adj(currid)) {
        int distCurr = dis[currid] + weight(iter, currid);
        if (dis[iter] > distCurr) {
          // 更新结果
          dis[iter] = distCurr;
          // 将节点和距离加入到堆中
          heap.push(state(iter, distCurr));
        }
      }
    }

    return dis;
  }

private:
  std::list<int> adj(int i) {
    return graph[i];
  }

  // 获取权重
  int weight(int from, int to);

  struct state {
    state(int id, int dis) : id(id), distFromStart(dis) {
    }

    int id;             // 图的节点
    int distFromStart;  // 从start节点到当前节点的距离
  };

  struct less {
    bool operator()(const state &s1, const state &s2) {
      return s1.distFromStart < s2.distFromStart;
    }
  };

  // 邻接表表示的图，key为图的当前节点，value为<临边节点，权重>
  std::map<int, std::list<int>> graph;
};
