/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (52.85%)
 * Likes:    5251
 * Dislikes: 131
 * Total Accepted:    497.2K
 * Total Submissions: 939.9K
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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int len1 = preorder.size();
    int len2 = inorder.size();
    if (len2 < 1 || len1 < 1 || len1 != len2) {
      return nullptr;
    }

    return buildTree(preorder, 0, len1 - 1, inorder, 0, len2 - 1);
  }

private:
  TreeNode* buildTree(vector<int>& preorder,
                      int          start1,
                      int          end1,
                      vector<int>& inorder,
                      int          start2,
                      int          end2) {
    if (start1 > end1) {
      return nullptr;
    }
    int rootVal = preorder[start1];
    int index   = start2;
    for (int i = start2; i <= end2; i++) {
      if (inorder[i] == rootVal) {
        index = i;
        break;
      }
    }

    int leftsize = index - start2;

    TreeNode* root = new TreeNode(rootVal);
    root->left     = buildTree(preorder,
                           start1 + 1,
                           start1 + leftsize,
                           inorder,
                           start2,
                           index - 1);
    root->right    = buildTree(preorder,
                            start1 + leftsize + 1,
                            end1,
                            inorder,
                            index + 1,
                            end2);
    return root;
  }
};
// @lc code=end
