/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 *
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (37.05%)
 * Likes:    7968
 * Dislikes: 485
 * Total Accepted:    641.5K
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,2,3]'
 *
 * A path in a binary tree is a sequence of nodes where each pair of adjacent
 * nodes in the sequence has an edge connecting them. A node can only appear in
 * the sequence at most once. Note that the path does not need to pass through
 * the root.
 *
 * The path sum of a path is the sum of the node's values in the path.
 *
 * Given the root of a binary tree, return the maximum path sum of any
 * non-empty path.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3]
 * Output: 6
 * Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 =
 * 6.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [-10,9,20,null,null,15,7]
 * Output: 42
 * Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 +
 * 7 = 42.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 3 * 10^4].
 * -1000 <= Node.val <= 1000
 *
 *
 */

#include <algorithm>
#include <climits>

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
  int maxPathSum(TreeNode* root) {
    ans = INT_MIN;
    _maxPathSum(root);
    return ans;
  }

private:
  /**
   * @brief 计算最大路径和
   * @param  root
   * @return int 返回当前节点左右子树和的最大值
   * */
  int _maxPathSum(TreeNode* root) {
    if (nullptr == root) {
      return 0;
    }

    int left  = std::max(0, _maxPathSum(root->left));
    int right = std::max(0, _maxPathSum(root->right));

    ans = std::max(ans, left + right + root->val);

    return std::max(left, right) + root->val;
  }

  int ans;  // 最长路径和
};
// @lc code=end
