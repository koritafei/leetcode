/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 *
 * https://leetcode.com/problems/different-ways-to-add-parentheses/description/
 *
 * algorithms
 * Medium (55.78%)
 * Likes:    1790
 * Dislikes: 98
 * Total Accepted:    107.4K
 * Total Submissions: 192.4K
 * Testcase Example:  '"2-1-1"'
 *
 * Given a string of numbers and operators, return all possible results from
 * computing all the different possible ways to group numbers and operators.
 * The valid operators are +, - and *.
 *
 * Example 1:
 *
 *
 * Input: "2-1-1"
 * Output: [0, 2]
 * Explanation:
 * ((2-1)-1) = 0
 * (2-(1-1)) = 2
 *
 * Example 2:
 *
 *
 * Input: "2*3-4*5"
 * Output: [-34, -14, -10, -10, 10]
 * Explanation:
 * (2*(3-(4*5))) = -34
 * ((2*3)-(4*5)) = -14
 * ((2*(3-4))*5) = -10
 * (2*((3-4)*5)) = -10
 * (((2*3)-4)*5) = 10
 *
 */

#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> diffWaysToCompute(string input) {
    vector<int> res;

    for (int i = 0; i < input.length(); i++) {
      if (input[i] < '0' || input[i] > '9') {
        auto L = diffWaysToCompute(input.substr(0, i));   // 递归左分支
        auto R = diffWaysToCompute(input.substr(i + 1));  // 递归右分支
        for (auto l : L) {
          for (auto r : R) {
            switch (input[i]) {
              case '-':
                res.push_back(l - r);
                break;
              case '*':
                res.push_back(l * r);
                break;
              case '+':
                res.push_back(l + r);
                break;
            }
          }
        }
      }
    }

    if (res.empty()) {  // 只有一个元素
      res.push_back(stoi(input));
    }

    return res;
  }
};
// @lc code=end

int main(int argc, char* argv[]) {
  string      input = "2*3-4*5";
  Solution    sol;
  vector<int> res = sol.diffWaysToCompute(input);
  for (auto item : res) {
    cout << item << endl;
  }
  cout << endl;
}
