/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 *
 * https://leetcode.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Medium (45.04%)
 * Likes:    3507
 * Dislikes: 133
 * Total Accepted:    253.6K
 * Total Submissions: 562K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * You are given the root of a binary search tree (BST), where the values of
 * exactly two nodes of the tree were swapped by mistake. Recover the tree
 * without changing its structure.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,3,null,null,2]
 * Output: [3,1,null,null,2]
 * Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3
 * makes the BST valid.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [3,1,4,null,null,2]
 * Output: [2,1,4,null,null,3]
 * Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2
 * and 3 makes the BST valid.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [2, 1000].
 * -2^31 <= Node.val <= 2^31 - 1
 *
 *
 *
 * Follow up: A solution using O(n) space is pretty straight-forward. Could you
 * devise a constant O(1) space solution?
 */

#include <stack>
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
  void recoverTree(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    std::vector<TreeNode *> err = std::vector<TreeNode *>(2, nullptr);
    std::stack<TreeNode *>  stack;

    TreeNode *prev = nullptr;
    TreeNode *head = root;

    while (stack.size() || head) {
      if (head) {
        stack.push(head);
        head = head->left;
      } else {
        head = stack.top();
        stack.pop();
        if (prev && prev->val > head->val) {
          err[0] = err[0] == nullptr ? prev : err[0];
          err[1] = head;
        }
        prev = head;
        head = head->right;
      }
    }

    std::swap(err[0]->val, err[1]->val);
  }
};
// @lc code=end
