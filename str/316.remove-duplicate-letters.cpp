/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 *
 * https://leetcode.com/problems/remove-duplicate-letters/description/
 *
 * algorithms
 * Medium (40.62%)
 * Likes:    3460
 * Dislikes: 242
 * Total Accepted:    141.8K
 * Total Submissions: 348.5K
 * Testcase Example:  '"bcabc"'
 *
 * Given a string s, remove duplicate letters so that every letter appears once
 * and only once. You must make sure your result is the smallest in
 * lexicographical order among all possible results.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "bcabc"
 * Output: "abc"
 *
 *
 * Example 2:
 *
 *
 * Input: s = "cbacdcbc"
 * Output: "acdb"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^4
 * s consists of lowercase English letters.
 *
 *
 *
 * Note: This question is the same as 1081:
 * https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
 *
 */

#include <list>
#include <map>
#include <string>
#include <vector>

// @lc code=start
class Solution {
public:
  std::string removeDuplicateLetters(std::string s) {
    std::list<char>    st;
    std::map<int, int> map;
    std::vector<bool>  visited(256, false);
    for (int i = 0; i < s.size(); i++) {
      map[s[i]]++;
    }

    for (int i = 0; i < s.size(); i++) {
      char ch = s[i];
      map[ch]--;

      if (visited[ch]) {
        continue;  // 已访问过
      }

      while (!st.empty() && st.back() > ch) {
        if (map[st.back()] == 0) {
          break;  // 后续不存在相关字符，终止
        }
        visited[st.back()] = false;
        st.pop_back();
      }

      st.push_back(ch);
      visited[ch] = true;
    }

    std::string res;
    for (auto item : st) {
      res += item;
    }

    return res;
  }
};
// @lc code=end
