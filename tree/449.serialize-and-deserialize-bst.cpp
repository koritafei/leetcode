/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
 *
 * https://leetcode.com/problems/serialize-and-deserialize-bst/description/
 *
 * algorithms
 * Medium (54.08%)
 * Likes:    1855
 * Dislikes: 94
 * Total Accepted:    146.5K
 * Total Submissions: 270.8K
 * Testcase Example:  '[2,1,3]'
 *
 * Serialization is converting a data structure or object into a sequence of
 * bits so that it can be stored in a file or memory buffer, or transmitted
 * across a network connection link to be reconstructed later in the same or
 * another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary search tree. There
 * is no restriction on how your serialization/deserialization algorithm should
 * work. You need to ensure that a binary search tree can be serialized to a
 * string, and this string can be deserialized to the original tree structure.
 *
 * The encoded string should be as compact as possible.
 *
 *
 * Example 1:
 * Input: root = [2,1,3]
 * Output: [2,1,3]
 * Example 2:
 * Input: root = []
 * Output: []
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 10^4].
 * 0 <= Node.val <= 10^4
 * The input tree is guaranteed to be a binary search tree.
 *
 *
 */

#include <iostream>
#include <list>
#include <string>

using std::list;
using std::string;

struct TreeNode {
  int       val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {
  }
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string str = "";
    if (root == nullptr) {
      return "#!";
    }

    str += root->val + "!";
    str += serialize(root->left);
    str += serialize(root->right);

    return str;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    int len = data.length();
    if (len == 0) {
      return nullptr;
    }

    auto v = strsplit(data, "!");

    return deserialize(v);
  }

private:
  TreeNode* deserialize(list<string>& str) {
    string value = str.front();
    str.pop_front();
    if (value == "#") {
      return nullptr;
    }

    TreeNode* root = new TreeNode(atoi(value.c_str()));
    root->left     = deserialize(str);
    root->right    = deserialize(str);

    return root;
  }

  list<string>& strsplit(string str, string sp) {
    list<string>           res;
    std::string::size_type pos1, pos2;
    pos1 = 0;
    pos2 = str.find(sp);

    while (std::string::npos != pos2) {
      res.push_back(str.substr(pos1, pos2));
      pos1 = pos2 + sp.size();
      pos2 = str.find(sp, pos1);
    }

    if (pos1 != str.length()) {
      res.push_back(str.substr(pos1));
    }

    return res;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

int main (int argc, char **argv) {
  
}
