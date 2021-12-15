/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (52.60%)
 * Likes:    4006
 * Dislikes: 97
 * Total Accepted:    518.3K
 * Total Submissions: 983.7K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given the root of a binary tree and an integer targetSum, return all
 * root-to-leaf paths where the sum of the node values in the path equals
 * targetSum. Each path should be returned as a list of the node values, not
 * node references.
 *
 * A root-to-leaf path is a path starting from the root and ending at any leaf
 * node. A leaf is a node with no children.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * Output: [[5,4,11,2],[5,8,4,5]]
 * Explanation: There are two paths whose sum equals targetSum:
 * 5 + 4 + 11 + 2 = 22
 * 5 + 8 + 4 + 5 = 22
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,3], targetSum = 5
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1,2], targetSum = 0
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 5000].
 * -1000 <= Node.val <= 1000
 * -1000 <= targetSum <= 1000
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
  std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
    std::vector<std::vector<int>> res;
    std::vector<int>              path;
    if (root == nullptr) {
      return res;
    }

    if (!root->left && !root->right) {
      if (targetSum == root->val) {
        path.push_back(root->val);
        res.push_back(path);
        return res;
      }
    }

    std::vector<std::vector<int>> left =
        pathSum(root->left, targetSum - root->val);
    for (auto it : left) {
      std::vector<int> l;
      l.push_back(root->val);
      for (auto i : it) {
        l.push_back(i);
      }
      res.push_back(l);
    }

    std::vector<std::vector<int>> right =
        pathSum(root->right, targetSum - root->val);
    for (auto it : right) {
      std::vector<int> l;
      l.push_back(root->val);
      for (auto i : it) {
        l.push_back(i);
      }
      res.push_back(l);
    }

    return res;
  }
};
// @lc code=end
