/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (45.12%)
 * Likes:    952
 * Dislikes: 1442
 * Total Accepted:    267.1K
 * Total Submissions: 591.9K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and reverse only the vowels of
 * a string.
 *
 * Example 1:
 *
 *
 * Input: "hello"
 * Output: "holle"
 *
 *
 *
 * Example 2:
 *
 *
 * Input: "leetcode"
 * Output: "leotcede"
 *
 *
 * Note:
 * The vowels does not include the letter "y".
 *
 *
 *
 */

#include <iostream>
#include <string>
#include <unordered_map>

// @lc code=start
class Solution {
public:
  std::string reverseVowels(std::string s) {
    int len = s.length();
    if (len < 2) {
      return s;
    }
    std::unordered_map<char, int> m;

    m['a'] = 1;
    m['e'] = 1;
    m['i'] = 1;
    m['o'] = 1;
    m['u'] = 1;
    m['A'] = 1;
    m['E'] = 1;
    m['I'] = 1;
    m['O'] = 1;
    m['U'] = 1;

    int left = 0, right = len - 1;
    while (left < right) {
      while (left < right && m.find(s[left]) == m.end()) {
        left++;
      }
      while (left < right && m.find(s[right]) == m.end()) {
        right--;
      }
      std::swap(s[left++], s[right--]);
    }

    return s;
  }
};
// @lc code=end

int main(int argc, char** argv) {
  std::string s = "leetcode";
  std::cout << s << std::endl;
  Solution solution;
  auto     ss = solution.reverseVowels(s);
  std::cout << ss << std::endl;
}
