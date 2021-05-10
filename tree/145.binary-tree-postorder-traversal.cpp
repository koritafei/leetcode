/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Medium (57.10%)
 * Likes:    2422
 * Dislikes: 112
 * Total Accepted:    463.3K
 * Total Submissions: 803.1K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the postorder traversal of its
 * nodes' values.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,2,3]
 * Output: [3,2,1]
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
 * Output: [2,1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of the nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 *
 *
 *
 *
 * Follow up:
 *
 * Recursive solution is trivial, could you do it iteratively?
 *
 *
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
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    postorderTraversal(root, res);
    return res;
  }

private:
  // // 递归形式
  // void postorderTraversal(TreeNode *root, vector<int> &res) {
  //   if (root == nullptr) {
  //     return;
  //   }

  //   postorderTraversal(root->left, res);
  //   postorderTraversal(root->right, res);
  //   res.push_back(root->val);
  // }

  // 非递归形式
  void postorderTraversal(TreeNode *root, vector<int> &res) {
    if (root == nullptr) {
      return;
    }

    stack<TreeNode *> stack1;
    stack<TreeNode *> stack2;
    stack1.push(root);
    while (!stack1.empty()) {
      root = stack1.top();
      stack1.pop();
      stack2.push(root);
      if (root->left != nullptr) {
        stack1.push(root->left);
      }
      if (root->right != nullptr) {
        stack1.push(root->right);
      }
    }
    while (!stack2.empty()) {
      res.push_back(stack2.top()->val);
      stack2.pop();
    }
  }
};
// @lc code=end
