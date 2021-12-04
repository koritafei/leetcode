/*
 * @lc app=leetcode id=886 lang=cpp
 *
 * [886] Possible Bipartition
 *
 * https://leetcode.com/problems/possible-bipartition/description/
 *
 * algorithms
 * Medium (46.45%)
 * Likes:    1904
 * Dislikes: 49
 * Total Accepted:    92.5K
 * Total Submissions: 199.1K
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
#include <vector>

// @lc code=start
class Solution {
public:
  bool possibleBipartition(int n, std::vector<std::vector<int>> &dislikes) {
    std::vector<bool>           visited = std::vector<bool>(n + 1, false);
    std::vector<bool>           color   = std::vector<bool>(n + 1, false);
    std::vector<std::list<int>> graph   = buildGraph(n, dislikes);

    for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
        if (!traver(graph, i, visited, color)) {
          return false;
        }
      }
    }

    return true;
  }

private:
  bool traver(std::vector<std::list<int>> &graph,
              int                          v,
              std::vector<bool>           &visited,
              std::vector<bool>           &color) {
    visited[v] = true;
    for (auto iter : graph[v]) {
      if (!visited[iter]) {
        color[iter] = !color[v];
        traver(graph, iter, visited, color);
      } else {
        if (color[iter] == color[v]) {
          return false;
        }
      }
    }
    return true;
  }

  std::vector<std::list<int>> buildGraph(
      int                            n,
      std::vector<std::vector<int>> &dislike) {
    std::vector<std::list<int>> graph =
        std::vector<std::list<int>>(n + 1, std::list<int>());

    int row = dislike.size();
    for (int i = 0; i < row; i++) {
      int v1 = dislike[i][0];
      int v2 = dislike[i][1];
      graph[v1].push_back(v2);
      graph[v2].push_back(v1);
    }

    return graph;
  }
};
// @lc code=end
