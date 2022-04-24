/*
 * @lc app=leetcode id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
 *
 * https://leetcode.com/problems/min-cost-to-connect-all-points/description/
 *
 * algorithms
 * Medium (60.24%)
 * Likes:    868
 * Dislikes: 36
 * Total Accepted:    36.4K
 * Total Submissions: 60.3K
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
#include <map>
#include <vector>

// @lc code=start
class Solution {
public:
  int minCostConnectPoints(std::vector<std::vector<int>> &points) {
    int                           mst = 0;
    std::vector<std::vector<int>> graph_;
    int                           len = points.size();
    // 构建图的边集合
    for (int i = 0; i < points.size(); i++) {
      for (int j = i + 1; j < points.size(); j++) {
        graph_.push_back(
            std::vector<int>{i, j, distance(points[i], points[j])});
      }
    }

    std::sort(graph_.begin(),
              graph_.end(),
              [](std::vector<int> &a, std::vector<int> &b) {
                return a[2] < b[2];
              });

    UF uf(len);

    for (int i = 0; i < graph_.size(); i++) {
      int start  = graph_[i][0];
      int end    = graph_[i][1];
      int weight = graph_[i][2];
      if (uf.connected(start, end)) {
        continue;
      }

      mst += weight;
      uf.connect(start, end);
    }

    return mst;
  }

private:
  int distance(std::vector<int> &vec1, std::vector<int> &vec2) {
    return abs(vec1[0] - vec2[0]) + abs(vec1[1] - vec2[1]);
  }

  class UF {
  public:
    UF(int size) {
      count_  = 0;
      parent_ = std::vector<int>(size, 0);
      weight_ = std::vector<int>(size, 0);
      for (int i = 0; i < size; i++) {
        parent_[i] = i;
      }
    }

    void connect(int p, int q) {
      int rootp = find(p);
      int rootq = find(q);
      if (rootp == rootq) {
        return;
      }

      if (weight_[rootp] < weight_[rootq]) {
        weight_[rootp] += weight_[rootq];
        parent_[rootq] = rootp;
      } else {
        weight_[rootq] += weight_[rootp];
        parent_[rootp] = rootq;
      }
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

    bool connected(int p, int q) {
      int rootq = find(q);
      int rootp = find(p);

      return rootp == rootq;
    }

  private:
    int              count_;
    std::vector<int> parent_;
    std::vector<int> weight_;
  };
};
// @lc code=end
