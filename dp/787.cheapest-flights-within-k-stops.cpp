/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 *
 * https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
 *
 * algorithms
 * Medium (36.82%)
 * Likes:    4066
 * Dislikes: 166
 * Total Accepted:    191.7K
 * Total Submissions: 522.4K
 * Testcase Example:  '3\n[[0,1,100],[1,2,100],[0,2,500]]\n0\n2\n1'
 *
 * There are n cities connected by some number of flights. You are given an
 * array flights where flights[i] = [fromi, toi, pricei] indicates that there
 * is a flight from city fromi to city toi with cost pricei.
 *
 * You are also given three integers src, dst, and k, return the cheapest price
 * from src to dst with at most k stops. If there is no such route, return
 * -1.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k
 * = 1
 * Output: 200
 * Explanation: The graph is shown.
 * The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as
 * marked red in the picture.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k
 * = 0
 * Output: 500
 * Explanation: The graph is shown.
 * The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as
 * marked blue in the picture.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 100
 * 0 <= flights.length <= (n * (n - 1) / 2)
 * flights[i].length == 3
 * 0 <= fromi, toi < n
 * fromi != toi
 * 1 <= pricei <= 10^4
 * There will not be any multiple flights between two cities.
 * 0 <= src, dst, k < n
 * src != dst
 *
 *
 */

#include <climits>
#include <map>
#include <vector>

// @lc code=start
class Solution {
public:
  int findCheapestPrice(int                            n,
                        std::vector<std::vector<int>>& flights,
                        int                            src,
                        int                            dst,
                        int                            k) {
    src_ = src;
    dst_ = dst;

    memo =
        std::vector<std::vector<int>>(n + 1, std::vector<int>(k + 1, INT_MIN));

    // 构建图
    for (auto item : flights) {
      int to    = item[1];
      int from  = item[0];
      int price = item[2];
      graph_[to].push_back(std::vector<int>{from, price});
    }

    return dp(dst, k, memo);
  }

private:
  int dp(int s, int k, std::vector<std::vector<int>>& memo) {
    if (s == src_) {
      return 0;
    }

    if (k == -1) {
      return -1;
    }

    if (memo[s][k] != INT_MIN) {
      return memo[s][k];
    }

    int res = INT_MAX;

    if (graph_.count(s)) {
      // 当s有入度节点时分解为子问题
      for (auto item : graph_[s]) {
        int from  = item[0];
        int price = item[1];
        // 从src 到达临边所需的最小代价
        int subProblem = dp(from, k - 1, memo);
        if (subProblem == -1) {
          continue;
        } else {
          res = std::min(res, price + subProblem);
        }
      }
    }

    return memo[s][k] = res == INT_MAX ? -1 : res;
  }

  std::map<int, std::vector<std::vector<int>>> graph_;  // to-->from-->price
  int                                          src_;
  int                                          dst_;
  std::vector<std::vector<int>>                memo;
};
// @lc code=end
