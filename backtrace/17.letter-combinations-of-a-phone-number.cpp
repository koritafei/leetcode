/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (52.21%)
 * Likes:    8142
 * Dislikes: 604
 * Total Accepted:    1M
 * Total Submissions: 2M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent. Return the answer in
 * any order.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 *
 *
 * Example 2:
 *
 *
 * Input: digits = ""
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: digits = "2"
 * Output: ["a","b","c"]
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= digits.length <= 4
 * digits[i] is a digit in the range ['2', '9'].
 *
 *
 */

#include <string>
#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<std::string> letterCombinations(std::string digits) {
    int len = digits.length();
    if (len == 0) {
      return res;
    }

    backtrace(digits, len, 0);

    return res;
  }

private:
  void backtrace(std::string &digits, int len, int index) {
    if (index >= len) {
      res.push_back(path);
      return;
    }

    std::string str = mapping[digits[index] - '0'];
    for (int j = 0; j < str.length(); j++) {
      // 做选择
      path.push_back(str[j]);
      // 递归
      backtrace(digits, len, index + 1);
      // 撤销选择
      path.pop_back();
    }
  }

  std::string              path;  // 路径
  std::vector<std::string> res;   // 结果集

  const std::vector<std::string> mapping = std::vector<std::string>{"",
                                                                    "",
                                                                    "abc",
                                                                    "def",
                                                                    "ghi",
                                                                    "jkl",
                                                                    "mno",
                                                                    "pqrs",
                                                                    "tuv",
                                                                    "wxyz"};
};
// @lc code=end
