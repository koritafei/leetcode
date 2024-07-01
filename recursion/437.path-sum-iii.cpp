/*
 * @lc app=leetcode id=437 lang=cpp
 * @lcpr version=30204
 *
 * [437] Path Sum III
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
  int pathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) {
      return 0;
    }
    return _pathSum(root, targetSum) + pathSum(root->left, targetSum) +
           pathSum(root->right, targetSum);
  }

private:
  int _pathSum(TreeNode* root, int64_t targetSum) {
    if (nullptr == root) {
      return 0;
    }

    return (targetSum == root->val) +
           _pathSum(root->left, targetSum - root->val) +
           _pathSum(root->right, targetSum - root->val);
  }
};
// @lc code=end

/*
// @lcpr case=start
// [10,5,-3,3,2,null,11,3,-2,null,1]\n8\n
// @lcpr case=end

// @lcpr case=start
// [5,4,8,11,null,13,4,7,2,null,null,5,1]\n22\n
// @lcpr case=end

 */
