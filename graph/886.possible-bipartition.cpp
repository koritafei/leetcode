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
    isBip      = true;
    visited    = std::vector<bool>(n + 1, false);
    color      = std::vector<bool>(n + 1, false);
    auto graph = buildGraph(n, dislikes);

    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        if (!isBippartition(graph, i)) {
          return false;
        }
      }
    }

    return isBip;
  }

private:
  bool isBippartition(std::map<int, std::vector<int>> &graph, int v) {
    if (!isBip) {
      return false;
    }

    visited[v] = true;
    for (auto &adv : graph[v]) {
      if (!visited[adv]) {
        // 未访问过
        color[adv] = !color[v];
        if (!isBippartition(graph, adv)) {
          isBip = false;
          return false;
        }
      } else {
        // 已访问过
        if (color[adv] == color[v]) {
          isBip = false;
          return false;
        }
      }
    }

    return true;
  }

  std::map<int, std::vector<int>> buildGraph(
      int                            n,
      std::vector<std::vector<int>> &dislikes) {
    std::map<int, std::vector<int>> graph;
    for (int i = 0; i < dislikes.size(); i++) {
      int s1 = dislikes[i][0];
      int s2 = dislikes[i][1];
      graph[s1].push_back(s2);
      graph[s2].push_back(s1);
    }

    return graph;
  }

  std::vector<bool> visited;
  std::vector<bool> color;
  bool              isBip;
};
// @lc code=end
