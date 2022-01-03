/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
 *
 * https://leetcode.com/problems/find-duplicate-subtrees/description/
 *
 * algorithms
 * Medium (54.94%)
 * Likes:    2715
 * Dislikes: 274
 * Total Accepted:    125.1K
 * Total Submissions: 227.5K
 * Testcase Example:  '[1,2,3,4,null,2,4,null,null,4]'
 *
 * Given the root of a binary tree, return all duplicate subtrees.
 *
 * For each kind of duplicate subtrees, you only need to return the root node
 * of any one of them.
 *
 * Two trees are duplicate if they have the same structure with the same node
 * values.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,4,null,2,4,null,null,4]
 * Output: [[2,4],[4]]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [2,1,1]
 * Output: [[1]]
 *
 *
 * Example 3:
 *
 *
 * Input: root = [2,2,2,3,null,3,null]
 * Output: [[2,3],[3]]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of the nodes in the tree will be in the range [1, 10^4]
 * -200 <= Node.val <= 200
 *
 *
 */

#include <map>
#include <string>
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
  std::vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    traveser(root);
    return res;
  }

private:
  std::string traveser(TreeNode* root) {
    if (root == nullptr) {
      return "#";
    }

    std::string left  = traveser(root->left);
    std::string right = traveser(root->right);

    std::string str = left + "," + right + "," + std::to_string(root->val);

    if (map.find(str) != map.end()) {
      int freq = map[str];
      if (freq == 1) {
        res.push_back(root);
      }
    }

    map[str]++;

    return str;
  }

  std::vector<TreeNode*>     res;
  std::map<std::string, int> map;
};
// @lc code=end
