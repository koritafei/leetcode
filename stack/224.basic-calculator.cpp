/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 *
 * https://leetcode.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (39.81%)
 * Likes:    3187
 * Dislikes: 272
 * Total Accepted:    266.3K
 * Total Submissions: 668.3K
 * Testcase Example:  '"1 + 1"'
 *
 * Given a string s representing a valid expression, implement a basic
 * calculator to evaluate it, and return the result of the evaluation.
 *
 * Note: You are not allowed to use any built-in function which evaluates
 * strings as mathematical expressions, such as eval().
 *
 *
 * Example 1:
 *
 *
 * Input: s = "1 + 1"
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: s = " 2-1 + 2 "
 * Output: 3
 *
 *
 * Example 3:
 *
 *
 * Input: s = "(1+(4+5+2)-3)+(6+8)"
 * Output: 23
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 3 * 10^5
 * s consists of digits, '+', '-', '(', ')', and ' '.
 * s represents a valid expression.
 * '+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is
 * invalid).
 * '-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is
 * valid).
 * There will be no two consecutive operators in the input.
 * Every number and running calculation will fit in a signed 32-bit integer.
 *
 *
 */

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

void print(std::vector<std::string> &vec) {
  for (auto &iter : vec) {
    std::cout << iter << ' ';
  }
  std::cout << '\n';
}

// @lc code=start
class Solution {
public:
  int calculate(std::string s) {
    ops["+"] = 1;
    ops["-"] = 1;
    ops["*"] = 2;
    ops["/"] = 2;

    std::vector<std::string> vec = transreverse(s);
    // print(vec);
    return evalRPN(vec);
  }

private:
  // 中缀表达式转后缀表达式
  std::vector<std::string> transreverse(std::string &s) {
    std::vector<std::string> res;
    std::stack<std::string>  stack;
    std::string              str;  // 存储数字字符串
    for (int i = 0; i < s.size(); i++) {
      if ((i == 0 && (s[i] == '+' || s[i] == '-')) ||
          (s[i] >= '0' && s[i] <= '9')) {
        str += s[i];
        continue;
      }

      if (s[i] == ')') {
        if (str.length() != 0) {
          res.push_back(str);
          str.clear();
        }
        while (stack.top() != "(") {
          res.push_back(stack.top());
          stack.pop();
        }
        stack.pop();  // 弹出(
      }

      std::string op = std::string(1, s[i]);

      if (s[i] == '(') {
        stack.push(op);
        continue;
      }

      if (ops.find(op) != ops.end()) {
        if (str.length() != 0) {
          res.push_back(str);
          str.clear();
        }
        while (stack.size()) {
          if (stack.top() != "(" && ops[op] <= ops[stack.top()]) {
            res.push_back(stack.top());
            stack.pop();
          } else {
            break;
          }
        }
        stack.push(op);
        continue;
      }
    }

    if (str.length() != 0) {
      res.push_back(str);
    }

    while (stack.size()) {
      res.push_back(stack.top());
      stack.pop();
    }

    return res;
  }

  // 后缀表达式求值
  int evalRPN(std::vector<std::string> &vec) {
    std::stack<std::string> stack;
    for (auto &iter : vec) {
      if (ops.find(iter) != ops.end()) {
        calcRes(stack, iter);
      } else {
        stack.push(iter);
      }
    }

    return std::atol(stack.top().c_str());
  }

  void calcRes(std::stack<std::string> &stack, std::string &op) {
    int num2 = std::atol(stack.top().c_str());
    stack.pop();
    int num1 = std::atol(stack.top().c_str());
    stack.pop();

    if (op == "+") {
      num1 += num2;
    } else if (op == "-") {
      num1 -= num2;
    } else if (op == "*") {
      num1 *= num2;
    } else if (op == "/") {
      num1 /= num2;
    }

    stack.push(std::to_string(num1));
  }

  std::map<std::string, int> ops;
};
// @lc code=end

int main(int argc, char **argv) {
  std::string str = "(1+(4+5+2)-3)+(6+8)";
  Solution    sol;
  std::cout << sol.calculate(str) << std::endl;
}