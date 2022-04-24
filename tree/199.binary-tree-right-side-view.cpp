/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (58.43%)
 * Likes:    5395
 * Dislikes: 300
 * Total Accepted:    570.8K
 * Total Submissions: 975.8K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given the root of a binary tree, imagine yourself standing on the right side
 * of it, return the values of the nodes you can see ordered from top to
 * bottom.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,null,5,null,4]
 * Output: [1,3,4]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,null,3]
 * Output: [1,3]
 *
 *
 * Example 3:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 *
 *
 */

#include <queue>
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
  std::vector<int> rightSideView(TreeNode* root) {
    std::queue<TreeNode*> queue;
    std::vector<int>      result;
    if (root == nullptr) {
      return result;
    }
    queue.push(root);

    while (queue.size() > 0) {
      int sz = queue.size();
      for (int i = 0; i < sz; i++) {
        TreeNode* curr = queue.front();
        queue.pop();

        if (curr->left) {
          queue.push(curr->left);
        }

        if (curr->right) {
          queue.push(curr->right);
        }

        if (i == sz - 1) {
          result.push_back(curr->val);
        }
      }
    }

    return result;
  }
};
// @lc code=end
