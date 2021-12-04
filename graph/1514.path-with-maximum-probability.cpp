/*
 * @lc app=leetcode id=1514 lang=cpp
 *
 * [1514] Path with Maximum Probability
 *
 * https://leetcode.com/problems/path-with-maximum-probability/description/
 *
 * algorithms
 * Medium (44.67%)
 * Likes:    911
 * Dislikes: 20
 * Total Accepted:    32.6K
 * Total Submissions: 72.9K
 * Testcase Example:  '3\n[[0,1],[1,2],[0,2]]\n[0.5,0.5,0.2]\n0\n2'
 *
 * You are given an undirected weighted graph of n nodes (0-indexed),
 * represented by an edge list where edges[i] = [a, b] is an undirected edge
 * connecting the nodes a and b with a probability of success of traversing
 * that edge succProb[i].
 *
 * Given two nodes start and end, find the path with the maximum probability of
 * success to go from start to end and return its success probability.
 *
 * If there is no path from start to end, return 0. Your answer will be
 * accepted if it differs from the correct answer by at most 1e-5.
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start =
 * 0, end = 2
 * Output: 0.25000
 * Explanation: There are two paths from start to end, one having a probability
 * of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start =
 * 0, end = 2
 * Output: 0.30000
 *
 *
 * Example 3:
 *
 *
 *
 *
 * Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
 * Output: 0.00000
 * Explanation: There is no path between 0 and 2.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= n <= 10^4
 * 0 <= start, end < n
 * start != end
 * 0 <= a, b < n
 * a != b
 * 0 <= succProb.length == edges.length <= 2*10^4
 * 0 <= succProb[i] <= 1
 * There is at most one edge between every two nodes.
 *
 */

#include <cmath>
#include <list>
#include <map>
#include <queue>
#include <vector>

// @lc code=start
const double eps = 1e-5;

class Solution {
public:
  double maxProbability(int                            n,
                        std::vector<std::vector<int>>& edges,
                        std::vector<double>&           succProb,
                        int                            start,
                        int                            end) {
    std::vector<double> res   = std::vector<double>(n, -1);
    auto                graph = createGraph(edges, succProb);
    std::priority_queue<state, std::vector<state>, greator> hp;
    hp.push(state(start, 1));
    res[start] = 1;

    while (hp.size()) {
      state currstate = hp.top();
      hp.pop();
      int    currid   = currstate.id;
      double currdist = currstate.distfromstart;

      if (currid == end) {
        return currdist;
      }

      if (currdist + eps < res[currid]) {
        continue;
      }

      for (auto item : graph[currid]) {
        double dist = item.second * currdist;
        if (dist > eps + res[item.first]) {
          res[item.first] = dist;
          hp.push(state(item.first, dist));
        }
      }
    }

    return 0.0;
  }

private:
  std::map<int, std::list<std::pair<int, double>>> createGraph(
      std::vector<std::vector<int>>& edges,
      std::vector<double>&           succProb) {
    std::map<int, std::list<std::pair<int, double>>> graph;
    int                                              row = edges.size();

    for (int i = 0; i < row; i++) {
      graph[edges[i][0]].push_back(std::make_pair(edges[i][1], succProb[i]));
      graph[edges[i][1]].push_back(std::make_pair(edges[i][0], succProb[i]));
    }

    return graph;
  }

  struct state {
    int    id;
    double distfromstart;
    state(int id, double d) : id(id), distfromstart(d) {
    }
  };

  struct greator {
    bool operator()(const state& s1, const state& s2) {
      return s1.distfromstart + eps < s2.distfromstart;
    }
  };
};

// @lc code=end
