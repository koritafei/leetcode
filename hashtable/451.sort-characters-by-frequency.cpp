/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 *
 * https://leetcode.com/problems/sort-characters-by-frequency/description/
 *
 * algorithms
 * Medium (64.45%)
 * Likes:    2200
 * Dislikes: 145
 * Total Accepted:    244.1K
 * Total Submissions: 378.6K
 * Testcase Example:  '"tree"'
 *
 * Given a string, sort it in decreasing order based on the frequency of
 * characters.
 *
 * Example 1:
 *
 * Input:
 * "tree"
 *
 * Output:
 * "eert"
 *
 * Explanation:
 * 'e' appears twice while 'r' and 't' both appear once.
 * So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid
 * answer.
 *
 *
 *
 * Example 2:
 *
 * Input:
 * "cccaaa"
 *
 * Output:
 * "cccaaa"
 *
 * Explanation:
 * Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 * Note that "cacaca" is incorrect, as the same characters must be together.
 *
 *
 *
 * Example 3:
 *
 * Input:
 * "Aabb"
 *
 * Output:
 * "bbAa"
 *
 * Explanation:
 * "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
 *
 *
 */

#include <iostream>
#include <string>
#include <unordered_map>

// @lc code=start
class Solution {
public:
  std::string frequencySort(std::string s) {
    std::string                   res;
    std::unordered_map<char, int> m;
    for (char ch : s) {
      m[ch]++;
    }
    int  max = 0;
    char ch;
    while (m.size()) {
      for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second > max) {
          max = it->second;
          ch  = it->first;
        }
      }
      res.append(max, ch);
      max = 0;
      m.erase(ch);
    }

    return res;
  }
};
// @lc code=end

int main(int argc, char **argv) {
  Solution    solution;
  std::string s = "tree";
  std::cout << solution.frequencySort(s) << std::endl;
}
