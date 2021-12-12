/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
 *
 * https://leetcode.com/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Medium (53.67%)
 * Likes:    4121
 * Dislikes: 293
 * Total Accepted:    363.6K
 * Total Submissions: 677K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * Given the root of a complete binary tree, return the number of the nodes in
 * the tree.
 *
 * According to Wikipedia, every level, except possibly the last, is completely
 * filled in a complete binary tree, and all nodes in the last level are as far
 * left as possible. It can have between 1 and 2^h nodes inclusive at the last
 * level h.
 *
 * Design an algorithm that runs in less than O(n) time complexity.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,4,5,6]
 * Output: 6
 *
 *
 * Example 2:
 *
 *
 * Input: root = []
 * Output: 0
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 5 * 10^4].
 * 0 <= Node.val <= 5 * 10^4
 * The tree is guaranteed to be complete.
 *
 *
 */

#include <cmath>

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
  int countNodes(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    TreeNode *left = root, *right = root;
    int       lh = 0, rh = 0;

    while (left) {
      left = left->left;
      lh++;
    }

    while (right) {
      right = right->right;
      rh++;
    }

    if (lh == rh) {
      return (int)pow(2, lh) - 1;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
// @lc code=end
