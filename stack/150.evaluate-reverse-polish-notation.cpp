/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 *
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (40.90%)
 * Likes:    2358
 * Dislikes: 575
 * Total Accepted:    348.2K
 * Total Submissions: 850K
 * Testcase Example:  '["2","1","+","3","*"]'
 *
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * Valid operators are +, -, *, and /. Each operand may be an integer or
 * another expression.
 *
 * Note that division between two integers should truncate toward zero.
 *
 * It is guaranteed that the given RPN expression is always valid. That means
 * the expression would always evaluate to a result, and there will not be any
 * division by zero operation.
 *
 *
 * Example 1:
 *
 *
 * Input: tokens = ["2","1","+","3","*"]
 * Output: 9
 * Explanation: ((2 + 1) * 3) = 9
 *
 *
 * Example 2:
 *
 *
 * Input: tokens = ["4","13","5","/","+"]
 * Output: 6
 * Explanation: (4 + (13 / 5)) = 6
 *
 *
 * Example 3:
 *
 *
 * Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
 * Output: 22
 * Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= tokens.length <= 10^4
 * tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the
 * range [-200, 200].
 *
 *
 */

#include <set>
#include <stack>
#include <string>
#include <vector>

// @lc code=start
class Solution {
public:
  int evalRPN(std::vector<std::string>& tokens) {
    std::stack<std::string> nums;
    for (auto& iter : tokens) {
      if (ops.find(iter) != ops.end()) {
        calcsRes(nums, iter);
      } else {
        nums.push(iter);
      }
    }

    return atol(nums.top().c_str());
  }

private:
  void calcsRes(std::stack<std::string>& nums, std::string& op) {
    int nums2 = atol(nums.top().c_str());
    nums.pop();
    int nums1 = atol(nums.top().c_str());
    nums.pop();

    if (op == "+") {
      nums1 += nums2;
    }

    if (op == "-") {
      nums1 -= nums2;
    }

    if (op == "*") {
      nums1 *= nums2;
    }

    if (op == "/") {
      nums1 /= nums2;
    }

    nums.push(std::to_string(nums1));
  }

  const std::set<std::string> ops = {"+", "-", "*", "/"};
};
// @lc code=end
