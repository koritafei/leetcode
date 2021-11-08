/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (52.65%)
 * Likes:    3414
 * Dislikes: 57
 * Total Accepted:    337.4K
 * Total Submissions: 640.6K
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

struct TreeNode {
  int       val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {
  }
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
  }
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {
  }
};

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
  TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder) {
    int leni = inorder.size();
    int lenp = postorder.size();

    if (leni <= 0 || lenp <= 0 || leni != lenp) {
      return nullptr;
    }

    return buildTree(inorder, 0, leni - 1, postorder, 0, lenp - 1);
  }

private:
  TreeNode *buildTree(std::vector<int> &inorder,
                      int               lo1,
                      int               hi1,
                      std::vector<int> &postorder,
                      int               lo2,
                      int               hi2) {
    if (lo1 > hi1) {
      return nullptr;
    }

    TreeNode *root  = new TreeNode(postorder[hi2]);
    int       index = hi2;
    for (int i = lo1; i <= hi1; i++) {
      if (inorder[i] == postorder[hi2]) {
        index = i;
        break;
      }
    }

    // 左子树长度
    int leftlen = index - lo1;
    root->left =
        buildTree(inorder, lo1, index - 1, postorder, lo2, lo2 + leftlen - 1);
    root->right =
        buildTree(inorder, index + 1, hi1, postorder, lo2 + leftlen, hi2 - 1);

    return root;
  }
};
// @lc code=end
