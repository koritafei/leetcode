/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (52.44%)
 * Likes:    5598
 * Dislikes: 226
 * Total Accepted:    532.2K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 *
 * Clarification: The input/output format is the same as how LeetCode
 * serializes a binary tree. You do not necessarily need to follow this format,
 * so please be creative and come up with different approaches yourself.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,null,null,4,5]
 * Output: [1,2,3,null,null,4,5]
 *
 *
 * Example 2:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1]
 * Output: [1]
 *
 *
 * Example 4:
 *
 *
 * Input: root = [1,2]
 * Output: [1,2]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 10^4].
 * -1000 <= Node.val <= 1000
 *
 *
 */
#include <cstring>
#include <queue>
#include <string>

#include "treenode.h"

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
  std::string serialize(TreeNode* root) {
    std::string res;
    if (root == nullptr) {
      return res;
    }

    std::queue<TreeNode*> que;
    que.push(root);
    while (que.size()) {
      int sz = que.size();
      for (int i = 0; i < sz; i++) {
        TreeNode* curr = que.front();
        que.pop();
        if (curr == nullptr) {
          res.append("#,");
          continue;
        }
        res.append(std::to_string(curr->val) + ",");
        que.push(curr->left);
        que.push(curr->right);
      }
    }

    return res;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(std::string data) {
    if (data.size() == 0) {
      return nullptr;
    }

    std::vector<std::string> vec = splitString(data, ",");

    TreeNode*             root = new TreeNode(atoi(vec[0].c_str()));
    std::queue<TreeNode*> que;
    que.push(root);

    int len = vec.size();

    for (int i = 1; i < len;) {
      TreeNode* curr = que.front();
      que.pop();
      if (i < len && vec[i] == "#") {
        curr->left = nullptr;
      } else if (i < len && vec[i] != "#") {
        curr->left = new TreeNode(atoi(vec[i].c_str()));
        que.push(curr->left);
      }

      i++;
      if (i < len && vec[i] == "#") {
        curr->right = nullptr;
      } else if (i < len && vec[i] != "#") {
        curr->right = new TreeNode(atoi(vec[i].c_str()));
        que.push(curr->right);
      }
      i++;
    }

    return root;
  }

private:
  std::vector<std::string> splitString(std::string s, std::string seq) {
    std::vector<std::string> res;
    char* str = strtok(const_cast<char*>(s.c_str()), seq.c_str());
    res.push_back(std::string(str));

    while ((str = strtok(NULL, seq.c_str()))) {
      res.push_back(std::string(str));
    }

    return res;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
