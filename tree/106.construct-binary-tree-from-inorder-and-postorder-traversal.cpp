/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (53.83%)
 * Likes:    3860
 * Dislikes: 67
 * Total Accepted:    360.2K
 * Total Submissions: 668.8K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given two integer arrays inorder and postorder where inorder is the inorder
 * traversal of a binary tree and postorder is the postorder traversal of the
 * same tree, construct and return the binary tree.
 *
 *
 * Example 1:
 *
 *
 * Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
 * Output: [3,9,20,null,null,15,7]
 *
 *
 * Example 2:
 *
 *
 * Input: inorder = [-1], postorder = [-1]
 * Output: [-1]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= inorder.length <= 3000
 * postorder.length == inorder.length
 * -3000 <= inorder[i], postorder[i] <= 3000
 * inorder and postorder consist of unique values.
 * Each value of postorder also appears in inorder.
 * inorder is guaranteed to be the inorder traversal of the tree.
 * postorder is guaranteed to be the postorder traversal of the tree.
 *
 *
 */

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
  TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
    return buildTree(inorder,
                     0,
                     inorder.size() - 1,
                     postorder,
                     0,
                     postorder.size() - 1);
  }

private:
  TreeNode* buildTree(std::vector<int>& inorder,
                      int               is,
                      int               ie,
                      std::vector<int>& postorder,
                      int               ps,
                      int               pe) {
    if (ps > pe) {
      return nullptr;
    }

    int       val  = postorder[pe];
    TreeNode* root = new TreeNode(val);

    int index = is;
    for (; index <= ie; index++) {
      if (inorder[index] == val) {
        break;
      }
    }

    int leftlen = index - is;
    root->left =
        buildTree(inorder, is, index - 1, postorder, ps, ps + leftlen - 1);
    root->right =
        buildTree(inorder, index + 1, ie, postorder, ps + leftlen, pe - 1);

    return root;
  }
};
// @lc code=end
