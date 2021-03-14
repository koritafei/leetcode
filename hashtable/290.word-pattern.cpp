/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (38.39%)
 * Likes:    1752
 * Dislikes: 211
 * Total Accepted:    248.1K
 * Total Submissions: 646.3K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string s, find if s follows the same pattern.
 *
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in s.
 *
 *
 * Example 1:
 *
 *
 * Input: pattern = "abba", s = "dog cat cat dog"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: pattern = "abba", s = "dog cat cat fish"
 * Output: false
 *
 *
 * Example 3:
 *
 *
 * Input: pattern = "aaaa", s = "dog cat cat dog"
 * Output: false
 *
 *
 * Example 4:
 *
 *
 * Input: pattern = "abba", s = "dog dog dog dog"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= pattern.length <= 300
 * pattern contains only lower-case English letters.
 * 1 <= s.length <= 3000
 * s contains only lower-case English letters and spaces ' '.
 * s does not contain any leading or trailing spaces.
 * All the words in s are separated by a single space.
 *
 *
 */

// @lc code=start
class Solution {
public:
  bool wordPattern(string pattern, string s) {
    unordered_map<string, int> ss;
    unordered_map<char, int>   pp;
    istringstream              in(s);

    int i = 0, len = pattern.length();

    for (string word; in >> word; ++i) {
      if (i == len || pp[pattern[i]] != ss[word]) {
        return false;
      } else {
        pp[pattern[i]] = ss[word] = i + 1;
      }
    }

    return i == len;
  }
};
// @lc code=end
