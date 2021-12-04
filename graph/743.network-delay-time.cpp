/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 *
 * https://leetcode.com/problems/network-delay-time/description/
 *
 * algorithms
 * Medium (47.27%)
 * Likes:    3381
 * Dislikes: 263
 * Total Accepted:    194.3K
 * Total Submissions: 411.1K
 * Testcase Example:  '[[2,1,1],[2,3,1],[3,4,1]]\n4\n2'
 *
 * You are given a network of n nodes, labeled from 1 to n. You are also given
 * times, a list of travel times as directed edges times[i] = (ui, vi, wi),
 * where ui is the source node, vi is the target node, and wi is the time it
 * takes for a signal to travel from source to target.
 *
 * We will send a signal from a given node k. Return the time it takes for all
 * the n nodes to receive the signal. If it is impossible for all the n nodes
 * to receive the signal, return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: times = [[1,2,1]], n = 2, k = 1
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: times = [[1,2,1]], n = 2, k = 2
 * Output: -1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= n <= 100
 * 1 <= times.length <= 6000
 * times[i].length == 3
 * 1 <= ui, vi <= n
 * ui != vi
 * 0 <= wi <= 100
 * All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
 *
 *
 */

#include <climits>
#include <list>
#include <map>
#include <queue>
#include <vector>

// @lc code=start
class Solution {
public:
  int networkDelayTime(std::vector<std::vector<int>> &times, int n, int k) {
    createGraph(times);
    std::vector<int> res = dijkstra(k, n);

    int t = 0;
    for (int i = 1; i <= n; i++) {
      if (INT_MAX == res[i]) {
        // 存在节点不可达
        return -1;
      } else {
        t = (t > res[i] ? t : res[i]);
      }
    }

    return t;
  }

private:
  std::vector<int> dijkstra(int start, int n) {
    std::vector<int> res = std::vector<int>(n + 1, INT_MAX);
    std::priority_queue<state, std::vector<state>, greator> heap;  // 小根堆
    res[start] = 0;
    // base case
    heap.push(state(start, 0));

    while (heap.size()) {
      state curstate = heap.top();
      heap.pop();

      int currid   = curstate.id;
      int currdist = curstate.distfromstart;

      if (res[currid] < currdist) {
        continue;
      }

      for (auto item : adj(currid)) {
        int dist = currdist + item.second;

        if (dist < res[item.first]) {
          res[item.first] = dist;
          heap.push(state(item.first, dist));
        }
      }
    }

    return res;
  }

  void createGraph(std::vector<std::vector<int>> &times) {
    for (auto item : times) {
      graph[item[0]].push_back(std::make_pair(item[1], item[2]));
    }
  }

  std::list<std::pair<int, int>> adj(int v) {
    return graph[v];
  }

  struct state {
    state(int id, int dis) : id(id), distfromstart(dis) {
    }

    int id;
    int distfromstart;
  };

  struct greator {
    bool operator()(const state &s1, const state &s2) {
      return s1.distfromstart > s2.distfromstart;
    }
  };

  std::map<int, std::list<std::pair<int, int>>> graph;
};
// @lc code=end
