/*
 * @lc app=leetcode id=95 lang=cpp
 * @lcpr version=30204
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
  std::vector<TreeNode *> generateTrees(int n) {
    return __generateTrees(1, n);
  }

private:
  std::vector<TreeNode *> __generateTrees(int low, int high) {
    if (low == high) {
      return {new TreeNode(low)};
    }
    if (low > high) {
      return {nullptr};
    }

    std::vector<TreeNode *> ans;
    for (int i = low; i <= high; i++) {
      for (auto *left : __generateTrees(low, i - 1)) {
        for (auto *right : __generateTrees(i + 1, high)) {
          auto *root  = new TreeNode(i);
          root->left  = left;
          root->right = right;
          ans.emplace_back(root);
        }
      }
    }
    return ans;
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
