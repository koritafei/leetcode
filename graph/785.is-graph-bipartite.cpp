/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 *
 * https://leetcode.com/problems/is-graph-bipartite/description/
 *
 * algorithms
 * Medium (49.67%)
 * Likes:    3479
 * Dislikes: 250
 * Total Accepted:    244.1K
 * Total Submissions: 491.4K
 * Testcase Example:  '[[1,2,3],[0,2],[0,1,3],[0,2]]'
 *
 * There is an undirected graph with n nodes, where each node is numbered
 * between 0 and n - 1. You are given a 2D array graph, where graph[u] is an
 * array of nodes that node u is adjacent to. More formally, for each v in
 * graph[u], there is an undirected edge between node u and node v. The graph
 * has the following properties:
 *
 *
 * There are no self-edges (graph[u] does not contain u).
 * There are no parallel edges (graph[u] does not contain duplicate
 * values).
 * If v is in graph[u], then u is in graph[v] (the graph is undirected).
 * The graph may not be connected, meaning there may be two nodes u and v such
 * that there is no path between them.
 *
 *
 * A graph is bipartite if the nodes can be partitioned into two independent
 * sets A and B such that every edge in the graph connects a node in set A and
 * a node in set B.
 *
 * Return true if and only if it is bipartite.
 *
 *
 * Example 1:
 *
 *
 * Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
 * Output: false
 * Explanation: There is no way to partition the nodes into two independent
 * sets such that every edge connects a node in one and a node in the other.
 *
 * Example 2:
 *
 *
 * Input: graph = [[1,3],[0,2],[1,3],[0,2]]
 * Output: true
 * Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.
 *
 *
 * Constraints:
 *
 *
 * graph.length == n
 * 1 <= n <= 100
 * 0 <= graph[u].length < n
 * 0 <= graph[u][i] <= n - 1
 * graph[u] does not contain u.
 * All the values of graph[u] are unique.
 * If graph[u] contains v, then graph[v] contains u.
 *
 *
 */

#include <iostream>
#include <vector>

// @lc code=start
class Solution {
public:
  bool isBipartite(std::vector<std::vector<int>> &graph) {
    bool              isbip = true;
    int               n     = graph.size();
    std::vector<bool> visited = std::vector<bool>(n, false);  // 是否被访问过
    std::vector<bool> color = std::vector<bool>(n, false);  // 染色

    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        isBipartite(graph, isbip, visited, color, i);
      }
    }

    return isbip;
  }

private:
  void isBipartite(std::vector<std::vector<int>> &graph,
                   bool                          &isbip,
                   std::vector<bool>             &visited,
                   std::vector<bool>             &color,
                   int                            v) {
    if (!isbip) {  // 已经确定结果，直接返回
      return;
    }
    visited[v] = true;

    for (auto iter : graph[v]) {
      if (!visited[iter]) {       // 临近节点未被访问过
        color[iter] = !color[v];  // 标记与当前节点的不同颜色
        isBipartite(graph, isbip, visited, color, iter);
      } else {
        // 如果已经被访问过
        // 判断颜色是否与当前节点颜色相同，如果相同，直接返回false
        if (color[iter] == color[v]) {
          isbip = false;
          return;
        }
      }
    }
  }
};
// @lc code=end
