/*
 * @lc app=leetcode id=1373 lang=cpp
 *
 * [1373] Maximum Sum BST in Binary Tree
 *
 * https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/
 *
 * algorithms
 * Hard (38.14%)
 * Likes:    807
 * Dislikes: 106
 * Total Accepted:    25.2K
 * Total Submissions: 66K
 * Testcase Example:  '[1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]'
 *
 * Given a binary tree root, return the maximum sum of all keys of any sub-tree
 * which is also a Binary Search Tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 *
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
 * Output: 20
 * Explanation: Maximum sum in a valid Binary search tree is obtained in root
 * node with key equal to 3.
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input: root = [4,3,null,1,2]
 * Output: 2
 * Explanation: Maximum sum in a valid Binary search tree is obtained in a
 * single root node with key equal to 2.
 *
 *
 * Example 3:
 *
 *
 * Input: root = [-4,-2,-5]
 * Output: 0
 * Explanation: All values are negatives. Return an empty BST.
 *
 *
 * Example 4:
 *
 *
 * Input: root = [2,1,3]
 * Output: 6
 *
 *
 * Example 5:
 *
 *
 * Input: root = [5,4,8,3,null,6,3]
 * Output: 7
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 4 * 10^4].
 * -4 * 10^4 <= Node.val <= 4 * 10^4
 *
 *
 */

#include <climits>
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
  int maxSumBST(TreeNode *root) {
    maxSum = 0;
    traverse(root);

    return maxSum;
  }

private:
  // sum, isBIS(0-n,1-y), maxvalue, minvalue
  std::vector<int> traverse(TreeNode *root) {
    if (root == nullptr) {
      return std::vector<int>{0, 1, INT_MIN, INT_MAX};
    }

    std::vector<int> left  = traverse(root->left);
    std::vector<int> right = traverse(root->right);

    std::vector<int> vec(4);
    if (left[1] == 1 && right[1] == 1 && root->val < right[3] &&
        root->val > left[2]) {
      vec[0] = left[0] + right[0] + root->val;
      vec[1] = 1;
      vec[2] = std::max(right[2], root->val);
      vec[3] = std::min(left[3], root->val);
      maxSum = std::max(maxSum, vec[0]);

    } else {
      return std::vector<int>{0, 0, INT_MIN, INT_MAX};
    }

    return vec;
  }

  int maxSum;
};
// @lc code=end
