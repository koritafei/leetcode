/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (50.52%)
 * Likes:    2675
 * Dislikes: 53
 * Total Accepted:    298K
 * Total Submissions: 589.4K
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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int len1 = inorder.size();
    int len2 = postorder.size();
    if (len1 < 1 || len2 < 1 || len1 != len2) {
      return nullptr;
    }

    return buildTree(inorder, 0, len1 - 1, postorder, 0, len2 - 1);
  }

private:
  TreeNode* buildTree(vector<int>& inorder,
                      int          start,
                      int          end,
                      vector<int>& postorder,
                      int          pstart,
                      int          pend) {
    if (start > end) {
      return nullptr;
    }
    int rootVal = postorder[pend];
    int index   = start;
    for (int i = start; i <= end; i++) {
      if (inorder[i] == rootVal) {
        index = i;
        break;
      }
    }

    TreeNode* root     = new TreeNode(rootVal);
    int       leftSize = index - start;

    root->left  = buildTree(inorder,
                           start,
                           index - 1,
                           postorder,
                           pstart,
                           pstart + leftSize - 1);
    root->right = buildTree(inorder,
                            index + 1,
                            end,
                            postorder,
                            pstart + leftSize,
                            pend - 1);

    return root;
  }
};
// @lc code=end
