/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 *
 * https://leetcode.com/problems/course-schedule-ii/description/
 *
 * algorithms
 * Medium (44.88%)
 * Likes:    5096
 * Dislikes: 194
 * Total Accepted:    499.7K
 * Total Submissions: 1.1M
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
 * Return the ordering of courses you should take to finish all courses. If
 * there are many valid answers, return any of them. If it is impossible to
 * finish all courses, return an empty array.
 *
 *
 * Example 1:
 *
 *
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: [0,1]
 * Explanation: There are a total of 2 courses to take. To take course 1 you
 * should have finished course 0. So the correct course order is [0,1].
 *
 *
 * Example 2:
 *
 *
 * Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
 * Output: [0,2,1,3]
 * Explanation: There are a total of 4 courses to take. To take course 3 you
 * should have finished both courses 1 and 2. Both courses 1 and 2 should be
 * taken after you finished course 0.
 * So one correct course order is [0,1,2,3]. Another correct ordering is
 * [0,2,1,3].
 *
 *
 * Example 3:
 *
 *
 * Input: numCourses = 1, prerequisites = []
 * Output: [0]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= numCourses * (numCourses - 1)
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * ai != bi
 * All the pairs [ai, bi] are distinct.
 *
 *
 */

#include <algorithm>
#include <deque>
#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<int> findOrder(int                            numCourses,
                             std::vector<std::vector<int>>& prerequisites) {
    std::vector<std::vector<int>> graph = buildGraph(numCourses, prerequisites);
    std::vector<int>              indegree(numCourses);
    std::deque<int>               que;

    for (int i = 0; i < numCourses; i++) {
      for (auto item : graph[i]) {
        indegree[item]++;
      }
    }

    for (int i = 0; i < numCourses; i++) {
      if (0 == indegree[i]) {
        que.push_back(i);
      }
    }

    std::vector<int> order(numCourses, 0);
    int              index = 0;

    while (que.size()) {
      int v = que.front();
      que.pop_front();

      order[index++] = v;

      for (auto item : graph[v]) {
        indegree[item]--;
        if (0 == indegree[item]) {
          que.push_back(item);
        }
      }
    }

    if (index != numCourses) {
      return std::vector<int>();
    } else {
      std::reverse(order.begin(), order.end());
      return order;
    }
  }

private:
  std::vector<std::vector<int>> buildGraph(
      int                            numCourses,
      std::vector<std::vector<int>>& prerequisites) {
    std::vector<std::vector<int>> graph(numCourses, std::vector<int>());

    for (int i = 0; i < prerequisites.size(); i++) {
      int from = prerequisites[i][0];
      int to   = prerequisites[i][1];
      graph[from].push_back(to);
    }

    return graph;
  }
};
// @lc code=end
