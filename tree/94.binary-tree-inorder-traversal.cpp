/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Easy (69.31%)
 * Likes:    6417
 * Dislikes: 273
 * Total Accepted:    1.3M
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the inorder traversal of its nodes'
 * values.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,2,3]
 * Output: [1,3,2]
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
  std::vector<int> inorderTraversal(TreeNode *root) {
    TreeNode *visited;
    pushNode(root);

    while (stack.size()) {
      TreeNode *curr = stack.top();

      if ((curr->left == nullptr || curr->left == visited) &&
          (curr->right != visited)) {
        // 中序遍历位置
        res.push_back(curr->val);
        pushNode(curr->right);
      }

      if (curr->right == nullptr || curr->right == visited) {
        visited = stack.top();
        stack.pop();
      }
    }

    return res;
  }

private:
  void pushNode(TreeNode *root) {
    while (root) {
      // 前序遍历位置
      stack.push(root);
      root = root->left;
    }
  }

  std::stack<TreeNode *> stack;
  std::vector<int>       res;
};
// @lc code=end
