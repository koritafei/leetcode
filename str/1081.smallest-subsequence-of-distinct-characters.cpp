/*
 * @lc app=leetcode id=1081 lang=cpp
 *
 * [1081] Smallest Subsequence of Distinct Characters
 *
 * https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/
 *
 * algorithms
 * Medium (54.46%)
 * Likes:    1256
 * Dislikes: 129
 * Total Accepted:    29.8K
 * Total Submissions: 54.6K
 * Testcase Example:  '"bcabc"'
 *
 * Given a string s, return the lexicographically smallest subsequence of s
 * that contains all the distinct characters of s exactly once.
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
 * 1 <= s.length <= 1000
 * s consists of lowercase English letters.
 *
 *
 *
 * Note: This question is the same as 316:
 * https://leetcode.com/problems/remove-duplicate-letters/
 */

// @lc code=start
class Solution {
public:
  string smallestSubsequence(string s) {
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
