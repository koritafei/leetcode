/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (49.23%)
 * Likes:    2592
 * Dislikes: 85
 * Total Accepted:    399.5K
 * Total Submissions: 811.1K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given the root of a binary tree and an integer targetSum, return all
 * root-to-leaf paths where each path's sum equals targetSum.
 *
 * A leaf is a node with no children.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * Output: [[5,4,11,2],[5,8,4,5]]
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
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> res;
    if (root == nullptr) {
      return res;
    }

    if (root->left == nullptr && root->right == nullptr) {
      if (root->val == targetSum) {
        vector<int> a;
        a.push_back(root->val);
        res.push_back(a);
        return res;
      }
    }

    auto left = pathSum(root->left, targetSum - root->val);
    for (auto item : left) {
      std::vector<int> l;
      l.push_back(root->val);
      for (auto i : item) {
        l.push_back(i);
      }
      res.push_back(l);
    }

    auto right = pathSum(root->right, targetSum - root->val);
    for (auto item : right) {
      std::vector<int> r;
      r.push_back(root->val);
      for (auto i : item) {
        r.push_back(i);
      }
      res.push_back(r);
    }

    return res;
  }
};
// @lc code=end
