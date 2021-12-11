/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (46.34%)
 * Likes:    1332
 * Dislikes: 1676
 * Total Accepted:    318.8K
 * Total Submissions: 688K
 * Testcase Example:  '"hello"'
 *
 * Given a string s, reverse only all the vowels in the string and return it.
 *
 * The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both
 * cases.
 *
 *
 * Example 1:
 * Input: s = "hello"
 * Output: "holle"
 * Example 2:
 * Input: s = "leetcode"
 * Output: "leotcede"
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 3 * 10^5
 * s consist of printable ASCII characters.
 *
 *
 */

#include <string>

// @lc code=start
class Solution {
public:
  std::string reverseVowels(std::string s) {
    int len   = s.size();
    int left  = 0;
    int right = len - 1;
    while (left <= right) {
      if (!isvowel(s[left])) {
        left++;
      }
      if (!isvowel(s[right])) {
        right--;
      }

      if (left <= right && isvowel(s[left]) && isvowel(s[right])) {
        std::swap(s[left++], s[right--]);
      }
    }

    return s;
  }

private:
  bool isvowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
  }
};
// @lc code=end
