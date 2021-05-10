/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

#include <iostream>
#include <stack>
#include <string>

// @lc code=start
class Solution {
  public:
  bool isValid(std::string s) {
    int slen = s.length();
    if (slen % 2) {
      // 奇数元素直接返回false
      return false;
    }

    for (auto item : s) {
      switch (item) {
        case '(':
        case '[':
        case '{':
          _help.push(item);
          break;
        case ')':
          if (_help.empty() || _help.top() != '(') {
            return false;
          } else {
            _help.pop();
            continue;
          }
        case ']':
          if (_help.empty() || _help.top() != '[') {
            return false;
          } else {
            _help.pop();
            continue;
          }
        case '}':
          if (_help.empty() || _help.top() != '{') {
            return false;
          } else {
            _help.pop();
            continue;
          }
      }
    }

    return _help.empty();
  }

  private:
  std::stack<char> _help;
};
// @lc code=end

int main(int argc, char** argv) {
}
