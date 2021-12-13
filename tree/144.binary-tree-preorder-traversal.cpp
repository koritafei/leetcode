/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (60.62%)
 * Likes:    3282
 * Dislikes: 113
 * Total Accepted:    796.5K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the preorder traversal of its nodes'
 * values.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,2,3]
 * Output: [1,2,3]
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
 * Example 5:
 *
 *
 * Input: root = [1,null,2]
 * Output: [1,2]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 *
 *
 *
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 *
 */
#include <stack>
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
  std::vector<int> preorderTraversal(TreeNode* root) {
    pushNode(root);
    TreeNode* visited;
    while (stack.size() > 0) {
      TreeNode* node = stack.top();

      if ((node->left == nullptr || visited == node->left) &&
          (node->right != visited)) {
        pushNode(node->right);
      }

      if (node->right == nullptr || visited == node->right) {
        visited = node;
        stack.pop();
      }
    }

    return res;
  }

private:
  void pushNode(TreeNode* root) {
    while (root) {
      res.push_back(root->val);
      stack.push(root);
      root = root->left;
    }
  }

  std::stack<TreeNode*> stack;
  std::vector<int>      res;
};
// @lc code=end
