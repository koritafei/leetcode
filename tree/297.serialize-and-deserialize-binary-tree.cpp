/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (52.16%)
 * Likes:    5423
 * Dislikes: 225
 * Total Accepted:    519.3K
 * Total Submissions: 994.6K
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

#include <cstddef>
#include <iostream>
#include <list>

struct TreeNode {
  int       val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {
  }
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
  }
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {
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
  std::string serialize(TreeNode *root) {
    if (root == nullptr) {
      return "#";
    }
    std::string res;
    // 后序
    std::string left  = serialize(root->left);
    std::string right = serialize(root->right);

    res += left + "," + right + "," + std::to_string(root->val);

    return res;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(std::string data) {
    int len = data.size();
    if (len == 0) {
      return nullptr;
    }

    std::list<std::string> str = split(data, ',');

    return deserialize(str);
  }

private:
  TreeNode *deserialize(std::list<std::string> &data) {
    if (data.empty()) {
      return nullptr;
    }

    std::string str = data.back();
    data.pop_back();
    if (str == "#") {
      return nullptr;
    }

    TreeNode *root = new TreeNode(std::stoi(str));
    root->right    = deserialize(data);
    root->left     = deserialize(data);

    return root;
  }

  std::list<std::string> split(std::string data, char seq) {
    std::list<std::string> res;
    for (int i = 0; i < data.size();) {
      if (i < data.size() && data[i] == seq) {
        i++;
        continue;
      }

      int         j = i;
      std::string tmp;
      while (j < data.size() && data[j] != seq) {
        tmp.push_back(data[j]);
        if (j < data.size()) {
          j++;
        }
      }

      res.push_back(tmp);
      i = j;
    }

    return res;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=endtre

int main() {
  TreeNode *t1 = new TreeNode(1);
  TreeNode *t2 = new TreeNode(2);
  TreeNode *t3 = new TreeNode(3);
  TreeNode *t4 = new TreeNode(4);
  TreeNode *t5 = new TreeNode(5);
  t1->left     = t2;
  t1->right    = t3;
  t3->left     = t4;
  t3->right    = t5;

  Codec c;
  std::cout << c.serialize(t1) << std::endl;
  c.deserialize(c.serialize(t1));
}
