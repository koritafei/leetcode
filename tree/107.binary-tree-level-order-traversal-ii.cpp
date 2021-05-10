/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Medium (55.26%)
 * Likes:    2041
 * Dislikes: 239
 * Total Accepted:    410K
 * Total Submissions: 742K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return the bottom-up level order traversal
 * of its nodes' values. (i.e., from left to right, level by level from leaf to
 * root).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[15,7],[9,20],[3]]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [1]
 * Output: [[1]]
 *
 *
 * Example 3:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 2000].
 * -1000 <= Node.val <= 1000
 *
 *
 */

#include <iostream>
#include <list>
#include <vector>

using namespace std;

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
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> result;
    int                 level = maxDepth(root);
    result.resize(level);
    levelOrderBottom(root, result, level - 1);
    return result;
  }

private:
  int maxDepth(TreeNode *root) {
    // 计算 树的深度
    if (root == nullptr) {
      return 0;
    }
    return std::max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
  }

  void levelOrderBottom(TreeNode *root, vector<vector<int>> &res, int level) {
    if (root == nullptr) {
      return;
    }

    list<pair<TreeNode *, int>> list;
    int                         index = level;
    list.push_back(pair<TreeNode *, int>(root, level));
    vector<int> tmp;
    while (!list.empty()) {
      auto r = list.front();
      list.pop_front();
      root = r.first;

      if (index == r.second) {
        tmp.push_back(root->val);
      } else {
        res[index] = tmp;
        index--;
        tmp.clear();
        tmp.push_back(root->val);
      }

      if (root->left != nullptr) {
        list.push_back(pair<TreeNode *, int>(root->left, r.second - 1));
      }

      if (root->right != nullptr) {
        list.push_back(pair<TreeNode *, int>(root->right, r.second - 1));
      }
    }

    res[0] = tmp;
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

  vector<vector<int>> res = solution.levelOrderBottom(root);
  for (auto item : res) {
    for (auto i : item) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
}
