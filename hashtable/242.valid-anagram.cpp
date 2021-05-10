/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (58.66%)
 * Likes:    2391
 * Dislikes: 160
 * Total Accepted:    773K
 * Total Submissions: 1.3M
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t, return true if t is an anagram of s, and false
 * otherwise.
 *
 *
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, t.length <= 5 * 10^4
 * s and t consist of lowercase English letters.
 *
 *
 *
 * Follow up: What if the inputs contain Unicode characters? How would you
 * adapt your solution to such a case?
 *
 */

// @lc code=start
class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> m;
    for (auto item : s) {
      m[item]++;
    }

    for (auto item : t) {
      if (m.find(item) == m.end()) {
        return false;
      } else {
        if (m[item]) {
          m[item]--;
        } else {
          return false;
        }
      }
    }

    for (auto it = m.begin(); it != m.end(); it++) {
      if (it->second) {
        return false;
      }
    }

    return true;
  }
};
// @lc code=end
