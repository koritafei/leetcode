/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (40.19%)
 * Likes:    2716
 * Dislikes: 4567
 * Total Accepted:    1.1M
 * Total Submissions: 2.6M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * A phrase is a palindrome if, after converting all uppercase letters into
 * lowercase letters and removing all non-alphanumeric characters, it reads the
 * same forward and backward. Alphanumeric characters include letters and
 * numbers.
 *
 * Given a string s, return true if it is a palindrome, or false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 * Explanation: "amanaplanacanalpanama" is a palindrome.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "race a car"
 * Output: false
 * Explanation: "raceacar" is not a palindrome.
 *
 *
 * Example 3:
 *
 *
 * Input: s = " "
 * Output: true
 * Explanation: s is an empty string "" after removing non-alphanumeric
 * characters.
 * Since an empty string reads the same forward and backward, it is a
 * palindrome.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 2 * 10^5
 * s consists only of printable ASCII characters.
 *
 *
 */
#include <string>
// @lc code=start
class Solution {
public:
  bool isPalindrome(std::string s) {
    int len = s.size();

    int left = 0, right = len - 1;
    while (left <= right) {
      if (isLetters(s[left]) && isLetters(s[right])) {
        if (std::tolower(s[left]) != std::tolower(s[right])) {
          return false;
        } else {
          left++, right--;
        }
      }

      if (left < len && !isLetters(s[left])) {
        left++;
      }

      if (right >= 0 && !isLetters(s[right])) {
        right--;
      }
    }

    return true;
  }

private:
  bool isLetters(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' and ch <= '9');
  }
};
// @lc code=end
