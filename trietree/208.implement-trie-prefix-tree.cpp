/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (56.42%)
 * Likes:    6115
 * Dislikes: 82
 * Total Accepted:    516.3K
 * Total Submissions: 913.7K
 * Testcase Example:
 '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * A trie (pronounced as "try") or prefix tree is a tree data structure used to
 * efficiently store and retrieve keys in a dataset of strings. There are
 * various applications of this data structure, such as autocomplete and
 * spellchecker.
 *
 * Implement the Trie class:
 *
 *
 * Trie() Initializes the trie object.
 * void insert(String word) Inserts the string word into the trie.
 * boolean search(String word) Returns true if the string word is in the trie
 * (i.e., was inserted before), and false otherwise.
 * boolean startsWith(String prefix) Returns true if there is a previously
 * inserted string word that has the prefix prefix, and false otherwise.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
 * [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
 * Output
 * [null, null, true, false, true, null, true]
 *
 * Explanation
 * Trie trie = new Trie();
 * trie.insert("apple");
 * trie.search("apple");   // return True
 * trie.search("app");     // return False
 * trie.startsWith("app"); // return True
 * trie.insert("app");
 * trie.search("app");     // return True
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word.length, prefix.length <= 2000
 * word and prefix consist only of lowercase English letters.
 * At most 3 * 10^4 calls in total will be made to insert, search, and
 * startsWith.
 *
 *
 */

#include <map>
#include <string>

// @lc code=start
class Trie {
public:
  Trie() {
    root = new TrieNode;
  }

  void insert(std::string word) {
    TrieNode *curr = root;
    int       len  = word.size();

    for (int i = 0; i < len; i++) {
      if (curr->next.find(word[i]) == curr->next.end()) {
        curr->next[word[i]] = new TrieNode;
      }
      curr = curr->next[word[i]];
      curr->path++;
    }
    curr->end++;
  }

  bool search(std::string word) {
    TrieNode *curr = root;
    int       len  = word.size();

    for (int i = 0; i < len; i++) {
      if (curr->next.find(word[i]) == curr->next.end()) {
        return false;
      }
      curr = curr->next[word[i]];
    }

    return curr->end != 0;
  }

  bool startsWith(std::string prefix) {
    TrieNode *curr = root;
    int       len  = prefix.size();

    for (int i = 0; i < len; i++) {
      if (curr->next.find(prefix[i]) == curr->next.end()) {
        return false;
      }
      curr = curr->next[prefix[i]];
    }
    return curr->path != 0;
  }

private:
  struct TrieNode {
    int                        path;
    int                        end;
    std::map<char, TrieNode *> next;
    TrieNode() : path(0), end(0) {
    }
  };

  TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
