/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
 *
 * https://leetcode.com/problems/delete-node-in-a-bst/description/
 *
 * algorithms
 * Medium (48.05%)
 * Likes:    4469
 * Dislikes: 142
 * Total Accepted:    235.2K
 * Total Submissions: 489.3K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n3'
 *
 * Given a root node reference of a BST and a key, delete the node with the
 * given key in the BST. Return the root node reference (possibly updated) of
 * the BST.
 *
 * Basically, the deletion can be divided into two stages:
 *
 *
 * Search for a node to remove.
 * If the node is found, delete the node.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: root = [5,3,6,2,4,null,7], key = 3
 * Output: [5,4,6,2,null,null,7]
 * Explanation: Given key to delete is 3. So we find the node with value 3 and
 * delete it.
 * One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
 * Please notice that another valid answer is [5,2,6,null,4,null,7] and it's
 * also accepted.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: root = [5,3,6,2,4,null,7], key = 0
 * Output: [5,3,6,2,4,null,7]
 * Explanation: The tree does not contain a node with value = 0.
 *
 *
 * Example 3:
 *
 *
 * Input: root = [], key = 0
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 10^4].
 * -10^5 <= Node.val <= 10^5
 * Each node has a unique value.
 * root is a valid binary search tree.
 * -10^5 <= key <= 10^5
 *
 *
 *
 * Follow up: Could you solve it with time complexity O(height of tree)?
 *
 */

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
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) {
      return root;
    }

    if (key == root->val) {
      // 不存在左孩子
      if (root->left == nullptr) {
        return root->right;
      }

      // 不存在右孩子
      if (root->right == nullptr) {
        return root->left;
      }

      // 存在左右孩子
      // 获取右子树的最小节点
      TreeNode* minNode = getMin(root->right);
      root->right       = deleteNode(root->right, minNode->val);

      // 右子树最小节点替换当前节点
      minNode->left  = root->left;
      minNode->right = root->right;
      root           = minNode;
    } else if (key > root->val) {
      root->right = deleteNode(root->right, key);
    } else if (key < root->val) {
      root->left = deleteNode(root->left, key);
    }

    return root;
  }

private:
  TreeNode* getMin(TreeNode* root) {
    while (root->left) {
      root = root->left;
    }

    return root;
  }
};
// @lc code=end
