/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 *
 * https://leetcode.com/problems/different-ways-to-add-parentheses/description/
 *
 * algorithms
 * Medium (59.72%)
 * Likes:    2928
 * Dislikes: 155
 * Total Accepted:    142.8K
 * Total Submissions: 238.3K
 * Testcase Example:  '"2-1-1"'
 *
 * Given a string expression of numbers and operators, return all possible
 * results from computing all the different possible ways to group numbers and
 * operators. You may return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: expression = "2-1-1"
 * Output: [0,2]
 * Explanation:
 * ((2-1)-1) = 0
 * (2-(1-1)) = 2
 *
 *
 * Example 2:
 *
 *
 * Input: expression = "2*3-4*5"
 * Output: [-34,-14,-10,-10,10]
 * Explanation:
 * (2*(3-(4*5))) = -34
 * ((2*3)-(4*5)) = -14
 * ((2*(3-4))*5) = -10
 * (2*((3-4)*5)) = -10
 * (((2*3)-4)*5) = 10
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= expression.length <= 20
 * expression consists of digits and the operator '+', '-', and '*'.
 * All the integer values in the input expression are in the range [0, 99].
 *
 *
 */

#include <string>
#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<int> diffWaysToCompute(std::string expression) {
    std::vector<int> res;
    for (int i = 0; i < expression.size(); i++) {
      if (expression[i] == '+' || expression[i] == '*' ||
          expression[i] == '-') {
        // 分治
        std::vector<int> left  = diffWaysToCompute(expression.substr(0, i));
        std::vector<int> right = diffWaysToCompute(
            expression.substr(i + 1, expression.size() - i - 1));

        for (auto item : left) {
          for (auto it : right) {
            switch (expression[i]) {
              case '+':
                res.push_back(item + it);
                break;
              case '-':
                res.push_back(item - it);
                break;
              case '*':
                res.push_back(item * it);
                break;
            }
          }
        }
      }
    }

    if (res.empty()) {
      res.push_back(atoi(expression.c_str()));
    }

    return res;
  }
};
// @lc code=end
