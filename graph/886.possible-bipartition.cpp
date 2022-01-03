/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 *
 * https://leetcode.com/problems/possible-bipartition/description/
 *
 * algorithms
 * Medium (46.46%)
 * Likes:    1916
 * Dislikes: 49
 * Total Accepted:    92.9K
 * Total Submissions: 200K
 * Testcase Example:  '4\n[[1,2],[1,3],[2,4]]'
 *
 * We want to split a group of n people (labeled from 1 to n) into two groups
 * of any size. Each person may dislike some other people, and they should not
 * go into the same group.
 *
 * Given the integer n and the array dislikes where dislikes[i] = [ai, bi]
 * indicates that the person labeled ai does not like the person labeled bi,
 * return true if it is possible to split everyone into two groups in this
 * way.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
 * Output: true
 * Explanation: group1 [1,4] and group2 [2,3].
 *
 *
 * Example 2:
 *
 *
 * Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 2000
 * 0 <= dislikes.length <= 10^4
 * dislikes[i].length == 2
 * 1 <= dislikes[i][j] <= n
 * ai < bi
 * All the pairs of dislikes are unique.
 *
 *
 */

#include <list>
#include <map>
#include <vector>

// @lc code=start
class Solution {
public:
  bool possibleBipartition(int n, std::vector<std::vector<int>> &dislikes) {
    visited                               = std::vector<bool>(n + 1, false);
    color                                 = std::vector<bool>(n + 1, false);
    isBip                                 = true;
    std::map<int, std::vector<int>> graph = buildGraph(dislikes);

    for (auto &it : graph) {
      if (visited[it.first] == false) {
        isBipartition(graph, it.first);
      }
    }

    return isBip;
  }

private:
  std::map<int, std::vector<int>> buildGraph(
      std::vector<std::vector<int>> &dislikes) {
    std::map<int, std::vector<int>> graph;

    for (auto &iter : dislikes) {
      graph[iter[0]].push_back(iter[1]);
      graph[iter[1]].push_back(iter[0]);
    }
    return graph;
  }

  void isBipartition(std::map<int, std::vector<int>> &graph, int v) {
    if (isBip == false) {
      return;
    }

    visited[v] = true;

    for (auto &it : graph[v]) {
      if (visited[it] == false) {
        color[it] = !color[v];
        isBipartition(graph, it);
      } else {
        if (color[v] == color[it]) {
          isBip = false;
          return;
        }
      }
    }
  }

  std::vector<bool> visited;
  std::vector<bool> color;
  bool              isBip;
};
// @lc code=end
