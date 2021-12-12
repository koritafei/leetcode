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
                      int               start1,
                      int               end1,
                      std::vector<int>& postorder,
                      int               start2,
                      int               end2) {
    if (start1 > end1) {
      return nullptr;
    }
    int rootVal = postorder[end2];
    int i       = start1;
    for (; i <= end1; i++) {
      if (rootVal == inorder[i]) {
        break;
      }
    }

    int       leftlen = i - start1;
    TreeNode* root    = new TreeNode(rootVal);

    root->left = buildTree(inorder,
                           start1,
                           i - 1,
                           postorder,
                           start2,
                           start2 + leftlen - 1);

    root->right =
        buildTree(inorder, i + 1, end1, postorder, start2 + leftlen, end2 - 1);

    return root;
  }
};
// @lc code=end
