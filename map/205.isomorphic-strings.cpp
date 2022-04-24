/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (41.66%)
 * Likes:    2946
 * Dislikes: 585
 * Total Accepted:    447.7K
 * Total Submissions: 1.1M
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

#include <string>
#include <unordered_map>

// @lc code=start
class Solution {
public:
  bool isIsomorphic(std::string s, std::string t) {
    std::unordered_map<char, char> map;
    std::unordered_map<char, char> map2;
    int                            lens = s.length(), lent = t.length();

    if (lens != lent) {
      return false;
    }

    for (int i = 0; i < lens; ++i) {
      if (map.find(s[i]) != map.end() || map2.find(t[i]) != map2.end()) {
        if (map[s[i]] != t[i] || map2[t[i]] != s[i]) {
          return false;
        }
      } else {
        map.insert(std::make_pair(s[i], t[i]));
        map2.insert(std::make_pair(t[i], s[i]));
      }
    }

    return true;
  }
};
// @lc code=end
