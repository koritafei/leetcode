/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (40.52%)
 * Likes:    1902
 * Dislikes: 456
 * Total Accepted:    348.5K
 * Total Submissions: 860K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings s and t are isomorphic if the characters in s can be replaced to
 * get t.
 *
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character, but a character may map to itself.
 *
 *
 * Example 1:
 * Input: s = "egg", t = "add"
 * Output: true
 * Example 2:
 * Input: s = "foo", t = "bar"
 * Output: false
 * Example 3:
 * Input: s = "paper", t = "title"
 * Output: true
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 5 * 10^4
 * t.length == s.length
 * s and t consist of any valid ascii character.
 *
 *
 */

// @lc code=start
class Solution {
public:
  bool isIsomorphic(string s, string t) {
    int lens = s.length();
    int lent = t.length();

    if (lens != lent) {
      return false;
    }
    unordered_map<char, int> sm;
    unordered_map<char, int> st;

    for (int i = 0; i < lens; i++) {
      if (sm[s[i]] != st[t[i]]) {
        return false;
      } else {
        sm[s[i]] = st[t[i]] = i + 1;
      }
    }

    return true;
  }
};
// @lc code=end
