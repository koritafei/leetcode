/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (62.59%)
 * Likes:    7537
 * Dislikes: 273
 * Total Accepted:    1.2M
 * Total Submissions: 1.8M
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * Given an array of strings strs, group the anagrams together. You can return
 * the answer in any order.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 *
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 * Example 2:
 * Input: strs = [""]
 * Output: [[""]]
 * Example 3:
 * Input: strs = ["a"]
 * Output: [["a"]]
 *
 *
 * Constraints:
 *
 *
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] consists of lowercase English letters.
 *
 *
 */

#include <algorithm>
#include <map>
#include <string>
#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<std::vector<std::string>> groupAnagrams(
      std::vector<std::string>& strs) {
    std::map<std::string, std::vector<std::string>> groups;
    std::vector<std::vector<std::string>>           res;

    for (auto iter : strs) {
      std::string str = iter;
      std::sort(iter.begin(), iter.end());
      groups[iter].push_back(str);
    }

    for (auto iter : groups) {
      res.push_back(iter.second);
    }

    return res;
  }
};
// @lc code=end
