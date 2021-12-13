/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Hard (33.96%)
 * Likes:    6382
 * Dislikes: 1539
 * Total Accepted:    673K
 * Total Submissions: 2M
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
 * the number of words in the shortest transformation sequence from beginWord
 * to endWord, or 0 if no such sequence exists.
 *
 *
 * Example 1:
 *
 *
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log","cog"]
 * Output: 5
 * Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot"
 * -> "dog" -> cog", which is 5 words long.
 *
 *
 * Example 2:
 *
 *
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log"]
 * Output: 0
 * Explanation: The endWord "cog" is not in wordList, therefore there is no
 * valid transformation sequence.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= beginWord.length <= 10
 * endWord.length == beginWord.length
 * 1 <= wordList.length <= 5000
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
  int ladderLength(std::string               beginWord,
                   std::string               endWord,
                   std::vector<std::string>& wordList) {
    int length = wordList.size();
    int lenb   = beginWord.length();
    int lene   = endWord.length();

    std::unordered_set<std::string> dict(wordList.begin(), wordList.end());
    if (dict.find(endWord) == dict.end()) {
      return 0;
    }

    int res = 1;

    std::list<std::string> que;
    que.push_back(beginWord);
    while (que.size()) {
      int sz = que.size();

      for (int t = 0; t < sz; t++) {
        std::string str = que.front();
        que.pop_front();

        if (str == endWord) {
          return res;
        }

        dict.erase(str);

        for (int i = 0; i < str.length(); i++) {
          char c = str[i];
          for (int k = 0; k < 26; k++) {
            str[i] = 'a' + k;
            if (dict.find(str) != dict.end()) {
              que.push_back(str);
            }
          }
          str[i] = c;
        }
      }
      res++;
    }

    return 0;
  }
};
// @lc code=end
