/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (72.85%)
 * Likes:    3439
 * Dislikes: 857
 * Total Accepted:    1.3M
 * Total Submissions: 1.8M
 * Testcase Example:  '["h","e","l","l","o"]'
 *
 * Write a function that reverses a string. The input string is given as an
 * array of characters s.
 *
 * You must do this by modifying the input array in-place with O(1) extra
 * memory.
 *
 *
 * Example 1:
 * Input: s = ["h","e","l","l","o"]
 * Output: ["o","l","l","e","h"]
 * Example 2:
 * Input: s = ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s[i] is a printable ascii character.
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  void reverseString(std::vector<char>& s) {
    int left = 0, right = s.size() - 1;
    while (left <= right) {
      std::swap(s[left++], s[right--]);
    }
  }
};
// @lc code=end
