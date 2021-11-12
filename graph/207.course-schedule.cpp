/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (44.66%)
 * Likes:    7542
 * Dislikes: 306
 * Total Accepted:    716.2K
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

#include <list>
#include <unordered_map>
#include <vector>

// @lc code=start
class Solution {
public:
  bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    std::unordered_map<int, std::list<int>> graph =
        buildGraph(numCourses, prerequisites);
    std::vector<int> indegree(numCourses, 0);

    for (int i = 0; i < numCourses; i++) {
      for (auto item : graph[i]) {
        indegree[item]++;
      }
    }

    std::list<int> list;
    // 所有入度为0的节点放入队列
    for (int i = 0; i < numCourses; i++) {
      if (0 == indegree[i]) {
        list.push_back(i);
      }
    }

    std::vector<int> order(numCourses, 0);
    int              index = 0;
    // BFS遍历
    while (list.size()) {
      int curr = list.front();
      list.pop_front();

      order[index++] = curr;
      for (auto item : graph[curr]) {
        indegree[item]--;
        // 入度为0加入队列
        if (0 == indegree[item]) {
          list.push_back(item);
        }
      }
    }

    // 遍历完成结束之后，判断排序的数组长度是否等于课程数，相等的话，可以完成，不等的话完不成
    return index == numCourses;
  }

private:
  std::unordered_map<int, std::list<int>> buildGraph(
      int                            numCourse,
      std::vector<std::vector<int>>& prerequisited) {
    std::unordered_map<int, std::list<int>> graph(numCourse + 1);

    for (int i = 1; i < numCourse; i++) {
      graph[i] = std::list<int>();
    }

    for (auto item : prerequisited) {
      int from = item[0];
      int to   = item[1];

      graph[from].push_back(to);
    }

    return graph;
  }
};
// @lc code=end
