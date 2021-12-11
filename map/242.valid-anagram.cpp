/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (60.39%)
 * Likes:    3686
 * Dislikes: 190
 * Total Accepted:    1M
 * Total Submissions: 1.7M
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

#include <map>
#include <string>

// @lc code=start
class Solution {
public:
  bool isAnagram(std::string s, std::string t) {
    std::map<char, int> freq;
    for (char ch : t) {
      freq[ch]++;
    }

    for (char ch : s) {
      if (freq.find(ch) != freq.end() && freq[ch] > 0) {
        freq[ch]--;
        if (freq[ch] == 0) {
          freq.erase(ch);
        }
      } else {
        return false;
      }
    }

    return freq.empty();
  }
};
// @lc code=end
