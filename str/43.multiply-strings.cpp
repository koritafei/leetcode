/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (36.24%)
 * Likes:    3631
 * Dislikes: 1434
 * Total Accepted:    446.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 *
 * Note: You must not use any built-in BigInteger library or convert the inputs
 * to integer directly.
 *
 *
 * Example 1:
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * Example 2:
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 *
 *
 * Constraints:
 *
 *
 * 1 <= num1.length, num2.length <= 200
 * num1 and num2 consist of digits only.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 *
 *
 */

#include <string>
#include <vector>

// @lc code=start
class Solution {
public:
  std::string multiply(std::string num1, std::string num2) {
    int              len1 = num1.size(), len2 = num2.size();
    std::vector<int> res(len1 + len2, 0);  // 结果最大长度为len1+len2

    for (int i = len1 - 1; i >= 0; i--) {
      for (int j = len2 - 1; j >= 0; j--) {
        int tmp        = (num1[i] - '0') * (num2[j] - '0');
        int sum        = res[i + j + 1] + tmp;
        res[i + j + 1] = sum % 10;
        res[i + j] += sum / 10;
      }
    }

    int i = 0;
    for (; i < res.size(); i++) {
      if (0 != res[i]) {
        break;
      }
    }

    std::string result;
    for (; i < res.size(); i++) {
      result.push_back(res[i] + '0');
    }

    return result.size() == 0 ? "0" : result;
  }
};
// @lc code=end
