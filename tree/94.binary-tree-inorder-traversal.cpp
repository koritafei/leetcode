/*
 * @lc app=leetcode id=94 lang=cpp
 * @lcpr version=30113
 *
 * [94] Binary Tree Inorder Traversal
 */

// @lcpr-template-start
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
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
  std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> res;
    inorderTraversal(root, res);
    return res;
  }

private:
  void inorderTraversal(TreeNode* root, std::vector<int>& res) {
    if (root == nullptr) {
      return;
    }

    inorderTraversal(root->left, res);
    res.push_back(root->val);
    inorderTraversal(root->right, res);
  }
};
// @lc code=end

/*
// @lcpr case=start
// [1,null,2,3]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
