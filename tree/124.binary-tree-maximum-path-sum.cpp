/*
 * @lc app=leetcode id=124 lang=cpp
 * @lcpr version=30204
 *
 * [124] Binary Tree Maximum Path Sum
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
using namespace std;
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
  int maxPathSum(TreeNode* root) {
    _maxPathSum(root);
    return ans;
  }

private:
  int _maxPathSum(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    int64_t left  = std::max(0, _maxPathSum(root->left));
    int64_t right = std::max(0, _maxPathSum(root->right));

    ans = std::max(ans, left + right + root->val);

    return std::max(left, right) + root->val;
  }
  int64_t ans = INT_MIN;
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [-10,9,20,null,null,15,7]\n
// @lcpr case=end

 */
