/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (44.70%)
 * Likes:    7790
 * Dislikes: 311
 * Total Accepted:    737.1K
 * Total Submissions: 1.6M
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of numCourses courses you have to take, labeled from 0 to
 * numCourses - 1. You are given an array prerequisites where prerequisites[i]
 * = [ai, bi] indicates that you must take course bi first if you want to take
 * course ai.
 *
 *
 * For example, the pair [0, 1], indicates that to take course 0 you have to
 * first take course 1.
 *
 *
 * Return true if you can finish all courses. Otherwise, return false.
 *
 *
 * Example 1:
 *
 *
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0. So it is possible.
 *
 *
 * Example 2:
 *
 *
 * Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take.
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should also have finished course 1. So it is impossible.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= numCourses <= 10^5
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * All the pairs prerequisites[i] are unique.
 *
 *
 */

#include <map>
#include <queue>
#include <vector>

// @lc code=start
class Solution {
public:
  bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    std::map<int, std::vector<int>> graph = buildGraph(prerequisites);

    std::vector<int> indegrees(numCourses, 0);
    std::queue<int>  que;

    for (auto& iter : graph) {  // 入度统计
      for (auto& it : iter.second) {
        indegrees[it]++;
      }
    }

    for (int i = 0; i < numCourses; i++) {
      if (indegrees[i] == 0) {
        que.push(i);
      }
    }

    int              index = 0;
    std::vector<int> order(numCourses, 0);

    while (que.size()) {
      int curr = que.front();
      que.pop();
      order[index++] = curr;
      if (graph.find(curr) != graph.end()) {
        for (auto& iter : graph[curr]) {
          indegrees[iter]--;
          if (indegrees[iter] == 0) {
            que.push(iter);
          }
        }
      }
    }

    return index == numCourses ? true : false;
  }

private:
  std::map<int, std::vector<int>> buildGraph(
      std::vector<std::vector<int>>& prerequisites) {
    std::map<int, std::vector<int>> graph;

    for (auto& iter : prerequisites) {
      graph[iter[1]].push_back(iter[0]);
    }

    return graph;
  }
};
// @lc code=end
