/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
 *
 * https://leetcode.com/problems/find-duplicate-subtrees/description/
 *
 * algorithms
 * Medium (53.43%)
 * Likes:    2025
 * Dislikes: 244
 * Total Accepted:    96K
 * Total Submissions: 179.5K
 * Testcase Example:  '[1,2,3,4,null,2,4,null,null,4]'
 *
 * Given the root of a binary tree, return all duplicate subtrees.
 *
 * For each kind of duplicate subtrees, you only need to return the root node
 * of any one of them.
 *
 * Two trees are duplicate if they have the same structure with the same node
 * values.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,4,null,2,4,null,null,4]
 * Output: [[2,4],[4]]
 *
 *
 * Example 2:
 *
 *
 * Input: root = [2,1,1]
 * Output: [[1]]
 *
 *
 * Example 3:
 *
 *
 * Input: root = [2,2,2,3,null,3,null]
 * Output: [[2,3],[3]]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of the nodes in the tree will be in the range [1, 10^4]
 * -200 <= Node.val <= 200
 *
 *
 */

#include <iostream>
#include <unordered_map>
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
  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    traversal(root);

    return result;
  }

private:
  unordered_map<string, int> memo;    // 记录所有子树与子树出现次数
  vector<TreeNode *>         result;  // 记录重复子树的根节点

  string traversal(TreeNode *root) {
    if (root == nullptr) {
      return "#";
    }

    string left    = traversal(root->left);
    string right   = traversal(root->right);
    string subtree = left + "," + right + "," + to_string(root->val);
    int    freq    = memo[subtree];

    // cout << subtree << '\t' << freq << endl;

    // 子串出现一次，表示含重复子树,将当前子树的根节点加入结果集
    if (1 == freq) {
      result.push_back(root);
    }

    // 子树出现次数+1
    memo[subtree] = freq + 1;

    // for (auto iter : memo) {
    //   cout << iter.first << "\t" << iter.second << endl;
    // }

    return subtree;
  }
};
// @lc code=end

int main(int argc, char **argv) {
  TreeNode *root = new TreeNode(1);
  TreeNode *l1   = new TreeNode(2);
  TreeNode *l2   = new TreeNode(3);
  TreeNode *l3   = new TreeNode(4);
  TreeNode *l4   = new TreeNode(2);
  TreeNode *l5   = new TreeNode(4);
  TreeNode *l6   = new TreeNode(4);

  root->left  = l1;
  root->right = l2;
  l1->left    = l3;
  l2->left    = l4;
  l2->right   = l5;
  l4->left    = l6;

  Solution solution;
  solution.findDuplicateSubtrees(root);
}
