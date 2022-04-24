/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 *
 * https://leetcode.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (26.06%)
 * Likes:    3265
 * Dislikes: 319
 * Total Accepted:    269.4K
 * Total Submissions: 1M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * A transformation sequence from word beginWord to word endWord using a
 * dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... ->
 * sk such that:
 *
 *
 * Every adjacent pair of words differs by a single letter.
 * Every si for 1 <= i <= k is in wordList. Note that beginWord does not need
 * to be in wordList.
 * sk == endWord
 *
 *
 * Given two words, beginWord and endWord, and a dictionary wordList, return
 * all the shortest transformation sequences from beginWord to endWord, or an
 * empty list if no such sequence exists. Each sequence should be returned as a
 * list of the words [beginWord, s1, s2, ..., sk].
 *
 *
 * Example 1:
 *
 *
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log","cog"]
 * Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
 * Explanation: There are 2 shortest transformation sequences:
 * "hit" -> "hot" -> "dot" -> "dog" -> "cog"
 * "hit" -> "hot" -> "lot" -> "log" -> "cog"
 *
 *
 * Example 2:
 *
 *
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log"]
 * Output: []
 * Explanation: The endWord "cog" is not in wordList, therefore there is no
 * valid transformation sequence.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= beginWord.length <= 5
 * endWord.length == beginWord.length
 * 1 <= wordList.length <= 1000
 * wordList[i].length == beginWord.length
 * beginWord, endWord, and wordList[i] consist of lowercase English
 * letters.
 * beginWord != endWord
 * All the words in wordList are unique.
 *
 *
 */

#include <list>
#include <string>
#include <unordered_set>
#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<std::vector<std::string>> findLadders(
      std::string               beginWord,
      std::string               endWord,
      std::vector<std::string>& wordList) {
    std::list<std::vector<std::string>>   path;  // 路径集合
    std::vector<std::vector<std::string>> res;   // 结果集
    std::unordered_set<std::string>       vis;

    std::unordered_set<std::string> dict(wordList.begin(), wordList.end());
    if (dict.find(endWord) == dict.end()) {
      return res;
    }

    path.push_back({beginWord});

    while (path.size()) {
      int sz = path.size();

      for (int i = 0; i < sz; i++) {
        std::vector<std::string> curr = path.front();
        path.pop_front();
        std::string s = curr.back();

        for (int j = 0; j < s.length(); j++) {
          char c = s[j];
          for (int k = 0; k < 26; k++) {
            s[j] = 'a' + k;
            if (s[j] != c) {
              if (dict.find(s) != dict.end()) {
                vis.insert(s);
                auto newpath = curr;
                newpath.push_back(s);

                if (s == endWord) {
                  res.push_back(newpath);
                } else {
                  path.push_back(newpath);
                }
              }
            }
            s[j] = c;
          }
        }
      }

      for (auto it : vis) {
        dict.erase(it);
      }
    }

    return res;
  }
};
// @lc code=end
