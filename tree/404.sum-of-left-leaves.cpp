/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
 *
 * https://leetcode.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (52.27%)
 * Likes:    1735
 * Dislikes: 166
 * Total Accepted:    237.5K
 * Total Submissions: 454.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Find the sum of all left leaves in a given binary tree.
 *
 * Example:
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 * There are two left leaves in the binary tree, with values 9 and 15
 * respectively. Return 24.
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
  int sumOfLeftLeaves(TreeNode* root) {
    return sumOfLeftLeave(root, false);
  }

private:
  int sumOfLeftLeave(TreeNode* root, bool isLeft = false) {
    if (!root) {
      return 0;
    }

    if (!root->left && !root->right) {
      return isLeft ? root->val : 0;
    }

    return sumOfLeftLeave(root->left, true) +
           sumOfLeftLeave(root->right, false);
  }
};
// @lc code=end
