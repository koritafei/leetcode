/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (52.22%)
 * Likes:    3130
 * Dislikes: 99
 * Total Accepted:    300.6K
 * Total Submissions: 575.2K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome. Return all possible palindrome partitioning of s.
 *
 * A palindrome string is a string that reads the same backward as forward.
 *
 *
 * Example 1:
 * Input: s = "aab"
 * Output: [["a","a","b"],["aa","b"]]
 * Example 2:
 * Input: s = "a"
 * Output: [["a"]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 16
 * s contains only lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution {
public:
  vector<vector<string>> partition(string s) {
    partition(s, 0);
    return res;
  }

private:
  void partition(string s, int start) {
    if (start == s.size()) {
      res.push_back(path);
      return;
    }

    for (int i = start; i < s.size(); i++) {
      if (isPalindrome(s, start, i)) {
        path.push_back(s.substr(start, i - start + 1));
        partition(s, i + 1);
        path.pop_back();
      }
    }
  }

  bool isPalindrome(string t, int start, int end) {
    int left = start, right = end;
    while (left <= right) {
      if (t[left] != t[right]) {
        return false;
      } else {
        left++;
        right--;
      }
    }
    return true;
  }

  vector<vector<string>> res;
  vector<string>         path;
};
// @lc code=end
