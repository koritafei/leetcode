/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (57.14%)
 * Likes:    2100
 * Dislikes: 86
 * Total Accepted:    605.1K
 * Total Submissions: 1.1M
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
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;

    preorderTraversal(root, res);

    return res;
  }

private:
  // // 递归形式
  // void preorderTraversal(TreeNode *root, vector<int> &res) {
  //   if (root == nullptr) {
  //     return;
  //   }
  //   res.push_back(root->val);
  //   preorderTraversal(root->left, res);
  //   preorderTraversal(root->right, res);
  // }

  // 非递归形式
  void preorderTraversal(TreeNode *root, vector<int> &res) {
    stack<TreeNode *> stack;
    while (!stack.empty() || root != nullptr) {
      if (root != nullptr) {
        res.push_back(root->val);
        stack.push(root);
        root = root->left;
      } else {
        root = stack.top();
        stack.pop();
        root = root->right;
      }
    }
  }
};
// @lc code=end
