/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (39.15%)
 * Likes:    2439
 * Dislikes: 273
 * Total Accepted:    292.8K
 * Total Submissions: 747.3K
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

#include <cstring>
#include <string>
#include <unordered_map>
#include <vector>

// @lc code=start
class Solution {
public:
  bool wordPattern(std::string pattern, std::string s) {
    std::vector<std::string>                   words = splitString(s, " ");
    std::unordered_map<char, std::vector<int>> p;

    for (int i = 0; i < pattern.length(); i++) {
      p[pattern[i]].push_back(i);
    }

    std::unordered_map<std::string, std::vector<int>> index;
    for (int i = 0; i < words.size(); i++) {
      index[words[i]].push_back(i);
    }

    for (auto it : p) {
      if (it.second[0] >= words.size()) {
        return false;
      }

      std::string str = words[it.second[0]];

      if (!isEqual(index[str], it.second)) {
        return false;
      }
    }

    return true;
  }

private:
  bool isEqual(std::vector<int> s1, std::vector<int> s2) {
    int i = 0, j = 0;
    for (; i < s1.size() && j < s2.size(); i++, j++) {
      if (s1[i] != s2[j]) {
        return false;
      }
    }

    if (i < s1.size() && j >= s2.size()) {
      return false;
    }

    if (i >= s1.size() && j < s2.size()) {
      return false;
    }
    return true;
  }

  std::vector<std::string> splitString(std::string s, std::string seq) {
    std::vector<std::string> words;
    char                    *str;

    str = strtok(const_cast<char *>(s.c_str()), seq.c_str());
    words.push_back(std::string(str));

    while ((str = strtok(NULL, seq.c_str())) != NULL) {
      words.push_back(std::string(str));
    }

    return words;
  }
};
// @lc code=end
