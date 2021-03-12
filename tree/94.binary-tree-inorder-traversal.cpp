/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (65.43%)
 * Likes:    4356
 * Dislikes: 192
 * Total Accepted:    926.9K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given the root of a binary tree, return the inorder traversal of its nodes'
 * values.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,null,2,3]
 * Output: [1,3,2]
 *
 *
 * Example 2:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: root = [1]
 * Output: [1]
 *
 *
 * Example 4:
 *
 *
 * Input: root = [1,2]
 * Output: [2,1]
 *
 *
 * Example 5:
 *
 *
 * Input: root = [1,null,2]
 * Output: [1,2]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
 *
 *
 *
 *
 * Follow up:
 *
 * Recursive solution is trivial, could you do it iteratively?
 *
 *
 *
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

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

struct TreeNode {
  int       val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {
  }
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
  }
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x),
        left(left),
        right(right) {
  }
};

class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    inorderTraversal(root, res);
    return res;
  }

private:
  // // 递归
  // void inorderTraversal(TreeNode *root, vector<int> &res) {
  //   if (root == nullptr) {
  //     return;
  //   }

  //   inorderTraversal(root->left, res);
  //   res.push_back(root->val);
  //   inorderTraversal(root->right, res);
  // }

  // 非递归方式
  void inorderTraversal(TreeNode *root, vector<int> &res) {
    stack<TreeNode *> stack;
    while (!stack.empty() || root != nullptr) {
      if (root != nullptr) {
        stack.push(root);
        root = root->left;
      } else {
        root = stack.top();
        stack.pop();
        res.push_back(root->val);
        root = root->right;
      }
    }
  }
};
// @lc code=end

int main(int argc, char **argv) {
  Solution  solution;
  TreeNode *root  = new TreeNode(1);
  TreeNode *left  = new TreeNode(3);
  TreeNode *right = new TreeNode(2);
  root->right     = right;
  right->left     = left;

  vector<int> res = solution.inorderTraversal(root);
  for (auto item : res) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}
