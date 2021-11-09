/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (47.34%)
 * Likes:    4096
 * Dislikes: 267
 * Total Accepted:    276.7K
 * Total Submissions: 583.3K
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
  std::vector<TreeNode *> generateTrees(int n) {
    std::vector<TreeNode *> res;
    if (n == 0) {
      return res;
    }

    return generateTrees(1, n);
  }

private:
  std::vector<TreeNode *> generateTrees(int lo, int hi) {
    std::vector<TreeNode *> res;
    if (lo > hi) {
      res.push_back(nullptr);
      return res;
    }

    // 穷举所有的可能
    for (int i = lo; i <= hi; i++) {
      std::vector<TreeNode *> leftTree  = generateTrees(lo, i - 1);
      std::vector<TreeNode *> rightTree = generateTrees(i + 1, hi);

      // 将所有的节点连成tree，放入数组
      for (auto left : leftTree) {
        for (auto right : rightTree) {
          TreeNode *root = new TreeNode(i);
          root->left     = left;
          root->right    = right;
          res.push_back(root);
        }
      }
    }

    return res;
  }
};
// @lc code=end
