/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Easy (69.12%)
 * Likes:    6321
 * Dislikes: 268
 * Total Accepted:    1.2M
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
 * Example 4:
 *
 *
 * Input: root = [1,2]
 * Output: [2,1]
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
  std::vector<int> inorderTraversal(TreeNode* root) {
    TreeNode* visited;
    pushNode(root);

    while (stack.size()) {
      TreeNode* curr = stack.top();
      if ((curr->left == nullptr || visited == curr->left) &&
          curr->right != visited) {
        // 中序遍历位置
        res.push_back(curr->val);
        pushNode(curr->right);
      }

      if (curr->right == nullptr || visited == curr->right) {
        // 后续遍历位置
        // 以curr为根的子树遍历完成
        visited = curr;
        stack.pop();
      }
    }

    return res;
  }

private:
  void pushNode(TreeNode* root) {
    while (root) {
      // 先序遍历位置

      stack.push(root);
      root = root->left;
    }
  }

  std::vector<int>      res;
  std::stack<TreeNode*> stack;
};
// @lc code=end
