/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (41.31%)
 * Likes:    3204
 * Dislikes: 885
 * Total Accepted:    645.3K
 * Total Submissions: 1.6M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 *
 * Note: A leaf is a node with no children.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: root = [2,null,3,null,4,null,5,null,6]
 * Output: 5
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 10^5].
 * -1000 <= Node.val <= 1000
 *
 *
 */

#include <queue>
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
  int minDepth(TreeNode *root) {
    if (!root) {
      return 0;
    }
    std::deque<TreeNode *> que;
    que.push_back(root);
    int depth = 1;
    while (que.size()) {
      int size = que.size();
      for (int i = 0; i < size; ++i) {
        TreeNode *curr = que.front();
        que.pop_front();
        if (curr->left == nullptr && curr->right == nullptr) {
          return depth;
        }
        if (curr->left) {
          que.push_back(curr->left);
        }

        if (curr->right) {
          que.push_back(curr->right);
        }
      }
      depth++;
    }

    return 0;
  }
};
// @lc code=end
