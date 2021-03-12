/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (56.24%)
 * Likes:    4324
 * Dislikes: 103
 * Total Accepted:    787.4K
 * Total Submissions: 1.4M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given the root of a binary tree, return the level order traversal of its
 * nodes' values. (i.e., from left to right, level by level).
 *
 *
 * Example 1:
 *
 *
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[9,20],[15,7]]
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

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    levelOrder(root, res);
    return res;
  }

private:
  void levelOrder(TreeNode *root, vector<vector<int>> &res) {
    if (root == nullptr) {
      return;
    }

    list<pair<TreeNode *, int>> list;
    int                         level = 0;

    list.push_back(pair<TreeNode *, int>(root, 0));

    vector<int> tmp;
    while (!list.empty()) {
      auto r = list.front();
      list.pop_front();

      root = r.first;

      if (level == r.second) {
        tmp.push_back(root->val);
      } else {
        res.push_back(tmp);
        level++;
        tmp.clear();
        tmp.push_back(root->val);
      }

      if (root->left != nullptr) {
        list.push_back(pair<TreeNode *, int>(root->left, r.second + 1));
      }
      if (root->right != nullptr) {
        list.push_back(pair<TreeNode *, int>(root->right, r.second + 1));
      }
    }
    res.push_back(tmp);
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

  vector<vector<int>> res = solution.levelOrder(root);
  for (auto item : res) {
    for (auto i : item) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
