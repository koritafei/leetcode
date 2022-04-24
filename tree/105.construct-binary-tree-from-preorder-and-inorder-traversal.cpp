/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (55.87%)
 * Likes:    7098
 * Dislikes: 176
 * Total Accepted:    615.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given two integer arrays preorder and inorder where preorder is the preorder
 * traversal of a binary tree and inorder is the inorder traversal of the same
 * tree, construct and return the binary tree.
 *
 *
 * Example 1:
 *
 *
 * Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * Output: [3,9,20,null,null,15,7]
 *
 *
 * Example 2:
 *
 *
 * Input: preorder = [-1], inorder = [-1]
 * Output: [-1]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder and inorder consist of unique values.
 * Each value of inorder also appears in preorder.
 * preorder is guaranteed to be the preorder traversal of the tree.
 * inorder is guaranteed to be the inorder traversal of the tree.
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
  TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    return buildTree(preorder,
                     0,
                     preorder.size() - 1,
                     inorder,
                     0,
                     inorder.size() - 1);
  }

private:
  TreeNode* buildTree(std::vector<int>& preorder,
                      int               ps,
                      int               pe,
                      std::vector<int>& inorder,
                      int               is,
                      int               ie) {
    if (ps > pe) {
      return nullptr;
    }

    int       val  = preorder[ps];
    TreeNode* root = new TreeNode(val);

    int index = is;
    for (; index <= ie; index++) {
      if (inorder[index] == val) {
        break;
      }
    }

    int leftlen = index - is;

    root->left =
        buildTree(preorder, ps + 1, ps + leftlen, inorder, is, index - 1);
    root->right =
        buildTree(preorder, ps + leftlen + 1, pe, inorder, index + 1, ie);

    return root;
  }
};
// @lc code=end
