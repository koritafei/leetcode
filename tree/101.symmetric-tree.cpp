/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (48.19%)
 * Likes:    5728
 * Dislikes: 154
 * Total Accepted:    839K
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given the root of a binary tree, check whether it is a mirror of itself
 * (i.e., symmetric around its center).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,2,3,4,4,3]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1,2,2,null,3,null,3]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [1, 1000].
 * -100 <= Node.val <= 100
 *
 *
 *
 * Follow up: Could you solve it both recursively and iteratively?
 */

// #include <iostream>
// #include <list>
// #include <vector>

// using namespace std;

// struct TreeNode {
//   int       val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {
//   }
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
//   }
//   TreeNode(int x, TreeNode *left, TreeNode *right)
//       : val(x),
//         left(left),
//         right(right) {
//   }
// };

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
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }

    return isSymmetric(root->left, root->right);
  }

private:
  bool isSymmetric(TreeNode *left, TreeNode *right) {
    if (left == nullptr && right == nullptr) {
      return true;
    }

    if ((left != nullptr && right == nullptr) ||
        (left == nullptr && right != nullptr)) {
      return false;
    }

    if (left->val == right->val) {
      return isSymmetric(left->left, right->right) &&
             isSymmetric(left->right, right->left);
    }
    return false;
  }
};
// @lc code=end

// int main(int argc, char **argv) {
//   Solution  solution;
//   TreeNode *root  = new TreeNode(1);
//   TreeNode *left  = new TreeNode(3);
//   TreeNode *right = new TreeNode(2);
//   root->right     = right;
//   right->left     = left;
//   std::cout << solution.isSymmetric(root) << std::endl;
// }
