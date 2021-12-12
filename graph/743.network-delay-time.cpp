/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 *
 * https://leetcode.com/problems/network-delay-time/description/
 *
 * algorithms
 * Medium (47.27%)
 * Likes:    3382
 * Dislikes: 263
 * Total Accepted:    194.4K
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
#include <map>
#include <queue>
#include <vector>

// @lc code=start
class Solution {
public:
  int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
    std::vector<int> dp = std::vector<int>(n + 1, INT_MAX);
    std::map<int, std::vector<std::pair<int, int>>> graph = buildGraph(times);
    std::priority_queue<state, std::vector<state>, greator> hp;
    hp.push(state(k, 0));
    dp[k] = 0;

    while (hp.size()) {
      state curr = hp.top();
      hp.pop();
      int currid   = curr.id;
      int currdist = curr.distance;
      if (currdist > dp[currid]) {
        continue;
      }

      for (auto it = graph[currid].begin(); it != graph[currid].end(); it++) {
        int nextid   = it->first;
        int nextdist = it->second + currdist;
        if (nextdist < dp[nextid]) {
          dp[nextid] = nextdist;
          hp.push(state(nextid, nextdist));
        }
      }
    }

    int res = INT_MIN;
    for (int i = 1; i <= n; i++) {
      if (dp[i] == INT_MAX) {
        return -1;
      } else {
        res = res > dp[i] ? res : dp[i];
      }
    }

    return res;
  }

private:
  struct state {
    int id;        // 图顶点
    int distance;  // 从起点到当前顶点的dis
    state(int id, int dis) : id(id), distance(dis) {
    }
  };

  struct greator {
    bool operator()(const state& s1, const state& s2) {
      return s1.distance > s2.distance;
    }
  };

  std::map<int, std::vector<std::pair<int, int>>> buildGraph(
      std::vector<std::vector<int>>& times) {
    std::map<int, std::vector<std::pair<int, int>>> graph;
    for (auto iter : times) {
      int start  = iter[0];
      int end    = iter[1];
      int weight = iter[2];
      graph[start].push_back(std::make_pair(end, weight));
    }

    return graph;
  }
};
// @lc code=end
