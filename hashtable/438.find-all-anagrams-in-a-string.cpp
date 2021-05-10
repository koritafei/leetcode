/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (45.03%)
 * Likes:    3969
 * Dislikes: 199
 * Total Accepted:    342.5K
 * Total Submissions: 760.5K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given a string s and a non-empty string p, find all the start indices of p's
 * anagrams in s.
 *
 * Strings consists of lowercase English letters only and the length of both
 * strings s and p will not be larger than 20,100.
 *
 * The order of output does not matter.
 *
 * Example 1:
 *
 * Input:
 * s: "cbaebabacd" p: "abc"
 *
 * Output:
 * [0, 6]
 *
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of
 * "abc".
 *
 *
 *
 * Example 2:
 *
 * Input:
 * s: "abab" p: "ab"
 *
 * Output:
 * [0, 1, 2]
 *
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 *
 *
 */

#include <iostream>
#include <string>
#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<int> findAnagrams(std::string s, std::string p) {
    std::vector<int> res, freqq(26, 0), freqs(26, 0);

    int len1 = s.length();
    int len2 = p.length();
    if (len1 < 1 || len2 < 1 || len1 < len2) {
      return res;
    }

    for (int i = 0; i < len2; i++) {
      ++freqq[p[i] - 'a'];
      ++freqs[s[i] - 'a'];
    }

    if (freqq == freqs) {
      res.push_back(0);
    }

    for (int i = len2; i < len1; i++) {
      ++freqs[s[i] - 'a'];
      --freqs[s[i - len2] - 'a'];

      if (freqq == freqs) {
        res.push_back(i - len2 + 1);
      }
    }

    return res;
  }
};
// @lc code=end

void print(std::vector<int>& s) {
  for (auto item : s) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char** argv) {
  Solution    solution;
  std::string s   = "cbaebabacd";
  std::string p   = "abc";
  auto        res = solution.findAnagrams(s, p);
  print(res);
  s   = "abab";
  p   = "ab";
  res = solution.findAnagrams(s, p);
  print(res);
}
