/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (52.30%)
 * Likes:    4743
 * Dislikes: 154
 * Total Accepted:    616.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return the zigzag level order traversal of
 * its nodes' values. (i.e., from left to right, then right to left for the
 * next level and alternate between).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[20,9],[15,7]]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1]
 * Output: [[1]]
 *
 *
 * Example 3:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 2000].
 * -100 <= Node.val <= 100
 *
 *
 */

#include <list>
#include <queue>
#include <vector>

#include "treenode.h"

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
    bool                          flag = true;
    std::queue<TreeNode*>         que;
    std::vector<std::vector<int>> res;

    if (root == nullptr) {
      return res;
    }
    que.push(root);

    while (que.size() > 0) {
      int            sz = que.size();
      std::list<int> tmp;

      for (int i = 0; i < sz; i++) {
        TreeNode* node = que.front();
        que.pop();
        if (flag) {
          tmp.push_back(node->val);
        } else {
          tmp.push_front(node->val);
        }

        if (node->left) {
          que.push(node->left);
        }

        if (node->right) {
          que.push(node->right);
        }
      }

      flag = !flag;
      std::vector<int> t;
      for (auto it : tmp) {
        t.push_back(it);
      }
      res.push_back(t);
      tmp.clear();
    }

    return res;
  }
};
// @lc code=end
