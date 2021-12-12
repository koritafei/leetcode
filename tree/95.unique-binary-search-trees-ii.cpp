/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (47.75%)
 * Likes:    4202
 * Dislikes: 274
 * Total Accepted:    281.1K
 * Total Submissions: 588.4K
 * Testcase Example:  '3'
 *
 * Given an integer n, return all the structurally unique BST's (binary search
 * trees), which has exactly n nodes of unique values from 1 to n. Return the
 * answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3
 * Output:
 * [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: [[1]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 8
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
  std::vector<TreeNode *> generateTrees(int n) {
    if (n <= 0) {
      return std::vector<TreeNode *>();
    }
    return buildTree(1, n);
  }

private:
  std::vector<TreeNode *> buildTree(int low, int high) {
    std::vector<TreeNode *> res;

    if (low > high) {
      res.push_back(nullptr);
      return res;
    }

    // root节点可能选项
    for (int i = low; i <= high; i++) {
      std::vector<TreeNode *> left  = buildTree(low, i - 1);
      std::vector<TreeNode *> right = buildTree(i + 1, high);

      for (auto iter : left) {
        for (auto it : right) {
          TreeNode *root = new TreeNode(i);
          root->left     = iter;
          root->right    = it;
          res.push_back(root);
        }
      }
    }

    return res;
  }
};
// @lc code=end
