/*
 * @lc app=leetcode id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
 *
 * https://leetcode.com/problems/min-cost-to-connect-all-points/description/
 *
 * algorithms
 * Medium (60.24%)
 * Likes:    856
 * Dislikes: 35
 * Total Accepted:    35.4K
 * Total Submissions: 58.7K
 * Testcase Example:  '[[0,0],[2,2],[3,10],[5,2],[7,0]]'
 *
 * You are given an array points representing integer coordinates of some
 * points on a 2D-plane, where points[i] = [xi, yi].
 *
 * The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan
 * distance between them: |xi - xj| + |yi - yj|, where |val| denotes the
 * absolute value of val.
 *
 * Return the minimum cost to make all points connected. All points are
 * connected if there is exactly one simple path between any two points.
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
 * Output: 20
 * Explanation:
 *
 * We can connect the points as shown above to get the minimum cost of 20.
 * Notice that there is a unique path between every pair of points.
 *
 *
 * Example 2:
 *
 *
 * Input: points = [[3,12],[-2,5],[-4,1]]
 * Output: 18
 *
 *
 * Example 3:
 *
 *
 * Input: points = [[0,0],[1,1],[1,0],[-1,1]]
 * Output: 4
 *
 *
 * Example 4:
 *
 *
 * Input: points = [[-1000000,-1000000],[1000000,1000000]]
 * Output: 4000000
 *
 *
 * Example 5:
 *
 *
 * Input: points = [[0,0]]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= points.length <= 1000
 * -10^6 <= xi, yi <= 10^6
 * All pairs (xi, yi) are distinct.
 *
 *
 */

#include <algorithm>
#include <cmath>
#include <vector>

// @lc code=start
class Solution {
public:
  int minCostConnectPoints(std::vector<std::vector<int>>& points) {
    std::vector<std::vector<int>> graph = buildGraph(points);
    int                           n     = points.size();

    int mst = 0;
    UF  uf(n);

    std::sort(graph.begin(),
              graph.end(),
              [](std::vector<int>& a, std::vector<int>& b) {
                return a[2] < b[2];
              });

    for (int i = 0; i < graph.size(); i++) {
      int u = graph[i][0];
      int v = graph[i][1];
      int w = graph[i][2];
      if (uf.connected(u, v)) {
        continue;
      }

      mst += w;
      uf.connectTwoPoints(u, v);
    }

    return mst;
  }

private:
  std::vector<std::vector<int>> buildGraph(
      std::vector<std::vector<int>>& points) {
    std::vector<std::vector<int>> graph;

    int row = points.size();

    for (int i = 0; i < row; i++) {
      for (int j = i + 1; j < row; j++) {
        int dis =
            abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        graph.push_back(std::vector<int>{i, j, dis});
      }
    }

    return graph;
  }

  class UF {
  public:
    UF(int n)
        : count_(n),
          parent_(std::vector<int>(n, 0)),
          weight_(std::vector<int>(n, 0)) {
      for (int i = 0; i < n; i++) {
        parent_[i] = i;
      }
    }

    void connectTwoPoints(int p, int q) {
      int rootp = find(p);
      int rootq = find(q);

      if (rootq == rootp) {
        return;
      }

      if (weight_[rootp] < weight_[rootq]) {
        weight_[rootp] += weight_[rootq];
        parent_[rootq] = rootp;
      } else {
        weight_[rootq] += weight_[rootq];
        parent_[rootp] = rootq;
      }
    }

    bool connected(int p, int q) {
      int rootp = find(p);
      int rootq = find(q);

      return rootp == rootq;
    }

    int count() const {
      return count_;
    }

    int find(int p) {
      while (p != parent_[p]) {
        parent_[p] = parent_[parent_[p]];
        p          = parent_[p];
      }

      return p;
    }

  private:
    int              count_;
    std::vector<int> parent_;
    std::vector<int> weight_;
  };
};
// @lc code=end
