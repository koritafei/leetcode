/*
 * @lc app=leetcode id=1373 lang=cpp
 *
 * [1373] Maximum Sum BST in Binary Tree
 *
 * https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/
 *
 * algorithms
 * Hard (37.90%)
 * Likes:    750
 * Dislikes: 103
 * Total Accepted:    23.8K
 * Total Submissions: 62.7K
 * Testcase Example:  '[1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]'
 *
 * Given a binary tree root, return the maximum sum of all keys of any sub-tree
 * which is also a Binary Search Tree (BST).
 *
 * Assume a BST is defined as follows:
 *
 *
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 *
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
 * Output: 20
 * Explanation: Maximum sum in a valid Binary search tree is obtained in root
 * node with key equal to 3.
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input: root = [4,3,null,1,2]
 * Output: 2
 * Explanation: Maximum sum in a valid Binary search tree is obtained in a
 * single root node with key equal to 2.
 *
 *
 * Example 3:
 *
 *
 * Input: root = [-4,-2,-5]
 * Output: 0
 * Explanation: All values are negatives. Return an empty BST.
 *
 *
 * Example 4:
 *
 *
 * Input: root = [2,1,3]
 * Output: 6
 *
 *
 * Example 5:
 *
 *
 * Input: root = [5,4,8,3,null,6,3]
 * Output: 7
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 4 * 10^4].
 * -4 * 10^4 <= Node.val <= 4 * 10^4
 *
 *
 */

#include <climits>
#include <iostream>
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
  int maxSumBST(TreeNode *root) {
    traverse(root);
    return maxSum;
  }

private:
  // isBST(0,1是), min_val(最小节点值), max_val(最大节点值), sum(子树和)
  std::vector<int> traverse(TreeNode *root) {
    std::vector<int> res(4, 0);

    if (root == nullptr) {
      res[0] = 1;
      res[1] = INT_MAX;
      res[2] = INT_MIN;
      res[3] = 0;

      return res;
    }

    // 左右子树
    std::vector<int> left  = traverse(root->left);
    std::vector<int> right = traverse(root->right);

    // BST 更新, BST 根节点值大于左子树最大值，右子树最小值
    if (left[0] && right[0] && root->val > left[2] && root->val < right[1]) {
      int sum = left[3] + right[3] + root->val;
      res[0]  = 1;
      res[1]  = std::min(root->val, left[1]);
      res[2]  = std::max(root->val, right[2]);
      res[3]  = sum;

      maxSum = (maxSum > sum ? maxSum : sum);
    } else {
      res[0] = 0;
      res[1] = INT_MAX;
      res[2] = INT_MIN;
      res[3] = 0;
    }

    return res;
  }

  int maxSum = 0;
};
// @lc code=end
