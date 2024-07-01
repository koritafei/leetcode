/*
 * @lc app=leetcode id=95 lang=cpp
 * @lcpr version=30122
 *
 * [95] Unique Binary Search Trees II
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
  vector<TreeNode *> generateTrees(int n) {
    if (0 == n) {
      return {};
    }

    return __generateTrees(1, n);
  }

private:
  std::vector<TreeNode *> __generateTrees(int left, int right) {
    if (left == right) {
      return {new TreeNode(left)};
    }
    if (left > right) {
      return {nullptr};
    }

    std::vector<TreeNode *> res;
    for (int i = left; i <= right; i++) {
      for (auto *left : __generateTrees(left, i - 1)) {
        for (auto *right : __generateTrees(i + 1, right)) {
          auto *curr  = new TreeNode(i);
          curr->left  = left;
          curr->right = right;
          res.push_back(curr);
        }
      }
    }

    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
