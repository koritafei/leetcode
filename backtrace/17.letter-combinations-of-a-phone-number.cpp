/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (49.26%)
 * Likes:    5525
 * Dislikes: 499
 * Total Accepted:    779.5K
 * Total Submissions: 1.6M
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

// @lc code=start
class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> result;
    if (digits.length() == 0) {
      return result;
    }

    string s = "";

    findletterCombinations(digits, 0, s, result);

    return result;
  }

private:
  const string letterMap[10] = {
      " ",     // 0,
      "",      // 1,
      "abc",   // 2,
      "def",   // 3,
      "ghi",   // 4,
      "jkl",   // 5,
      "mno",   // 6,
      "pqrs",  // 7,
      "tuv",   // 8,
      "wxyz"   // 9,
  };

  void findletterCombinations(string &digits, int index, const string &s,
                              vector<string> &res) {
    if (index == digits.length()) {
      res.push_back(s);
      return;
    }

    char   ch     = digits[index];
    string letter = letterMap[ch - '0'];
    for (int i = 0; i < letter.size(); i++) {
      findletterCombinations(digits, index + 1, s + letter[i], res);
    }

    return;
  }
};
// @lc code=end
