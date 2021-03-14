/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 *
 * https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (37.59%)
 * Likes:    1472
 * Dislikes: 516
 * Total Accepted:    272.8K
 * Total Submissions: 717.5K
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

// @lc code=start
class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    stack<int> stack;
    int        a, b;
    for (auto str : tokens) {
      if (str == "+") {
        stack.empty() == true ?  : a = stack.top(), stack.pop();
        stack.empty() == true ?  : b = stack.top(), stack.pop();
        stack.push(b + a);
      } else if (str == "*") {
        stack.empty() == true ?  : a = stack.top(), stack.pop();
        stack.empty() == true ?  : b = stack.top(), stack.pop();
        stack.push(b * a);
      } else if (str == "-") {
        stack.empty() == true ?  : a = stack.top(), stack.pop();
        stack.empty() == true ?  : b = stack.top(), stack.pop();
        stack.push(b - a);
      } else if (str == "/") {
        stack.empty() == true ?  : a = stack.top(), stack.pop();
        stack.empty() == true ?  : b = stack.top(), stack.pop();
        stack.push(b / a);
      } else {
        stack.push(atoi(str.c_str()));
      }
    }

    if (stack.empty()) {
      "";
    }

    return stack.top();
  }
};
// @lc code=end
