/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
 *
 * https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
 *
 * algorithms
 * Medium (51.04%)
 * Likes:    2126
 * Dislikes: 55
 * Total Accepted:    320.4K
 * Total Submissions: 627.5K
 * Testcase Example:  '[1,2,3]'
 *
 * You are given the root of a binary tree containing digits from 0 to 9 only.
 *
 * Each root-to-leaf path in the tree represents a number.
 *
 *
 * For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
 *
 *
 * Return the total sum of all root-to-leaf numbers.
 *
 * A leaf node is a node with no children.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3]
 * Output: 25
 * Explanation:
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * Therefore, sum = 12 + 13 = 25.
 *
 *
 * Example 2:
 *
 *
 * Input: root = [4,9,0,5,1]
 * Output: 1026
 * Explanation:
 * The root-to-leaf path 4->9->5 represents the number 495.
 * The root-to-leaf path 4->9->1 represents the number 491.
 * The root-to-leaf path 4->0 represents the number 40.
 * Therefore, sum = 495 + 491 + 40 = 1026.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 1000].
 * 0 <= Node.val <= 9
 * The depth of the tree will not exceed 10.
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
  int sumNumbers(TreeNode* root) {
    int  res = 0;
    auto tmp = treeEdge(root);
    for (auto item : tmp) {
      res += atoi(item.c_str());
    }

    return res;
  }

private:
  vector<string> treeEdge(TreeNode* root) {
    vector<string> res;
    if (root == nullptr) {
      return res;
    }

    if (root->left == nullptr && root->right == nullptr) {
      res.push_back(to_string(root->val));
      return res;
    }

    auto left = treeEdge(root->left);
    for (auto item : left) {
      res.push_back(to_string(root->val) + item);
    }

    auto right = treeEdge(root->right);
    for (auto item : right) {
      res.push_back(to_string(root->val) + item);
    }

    return res;
  }
};
// @lc code=end
