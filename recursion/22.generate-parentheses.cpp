/*
 * @lc app=leetcode id=22 lang=cpp
 * @lcpr version=30122
 *
 * [22] Generate Parentheses
 */

// @lcpr-template-start
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  std::vector<std::string> generateParenthesis(int n) {
    if (n <= 0) {
      return {""};
    }
    std::vector<std::string> res;
    for (int i = 0; i < n; i++) {
      for (auto &left : generateParenthesis(i)) {
        for (auto &right : generateParenthesis(n - i - 1)) {
          res.emplace_back("(" + left + ")" + right);
        }
      }
    }
    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
