/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
 *
 * https://leetcode.com/problems/maximum-binary-tree/description/
 *
 * algorithms
 * Medium (82.27%)
 * Likes:    2861
 * Dislikes: 280
 * Total Accepted:    178.7K
 * Total Submissions: 217.2K
 * Testcase Example:  '[3,2,1,6,0,5]'
 *
 * You are given an integer array nums with no duplicates. A maximum binary
 * tree can be built recursively from nums using the following algorithm:
 *
 *
 * Create a root node whose value is the maximum value in nums.
 * Recursively build the left subtree on the subarray prefix to the left of the
 * maximum value.
 * Recursively build the right subtree on the subarray suffix to the right of
 * the maximum value.
 *
 *
 * Return the maximum binary tree built from nums.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [3,2,1,6,0,5]
 * Output: [6,3,5,null,2,0,null,null,1]
 * Explanation: The recursive calls are as follow:
 * - The largest value in [3,2,1,6,0,5] is 6. Left prefix is [3,2,1] and right
 * suffix is [0,5].
 * ⁠   - The largest value in [3,2,1] is 3. Left prefix is [] and right suffix
 * is [2,1].
 * ⁠       - Empty array, so no child.
 * ⁠       - The largest value in [2,1] is 2. Left prefix is [] and right
 * suffix is [1].
 * ⁠           - Empty array, so no child.
 * ⁠           - Only one element, so child is a node with value 1.
 * ⁠   - The largest value in [0,5] is 5. Left prefix is [0] and right suffix
 * is [].
 * ⁠       - Only one element, so child is a node with value 0.
 * ⁠       - Empty array, so no child.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,2,1]
 * Output: [3,null,2,null,1]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 1000
 * 0 <= nums[i] <= 1000
 * All integers in nums are unique.
 *
 *
 */

#include <limits.h>

#include <vector>

using namespace std;
struct TreeNode {
  int       val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {
  }
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
  }
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {
  }
};

// @lc code=start

class Solution {
public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    int len = nums.size();
    if (len < 0) {
      return nullptr;
    }

    return constructMaximumBinaryTree(nums, 0, len);
  }

private:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums, int lo, int hi) {
    if (lo >= hi) {
      return nullptr;
    }

    int index  = 0;
    int maxVal = INT_MIN;

    for (int i = lo; i < hi; i++) {
      if (maxVal <= nums[i]) {
        index  = i;
        maxVal = nums[i];
      }
    }

    TreeNode* root = new TreeNode(maxVal);
    root->left     = constructMaximumBinaryTree(nums, lo, index);
    root->right    = constructMaximumBinaryTree(nums, index + 1, hi);

    return root;
  }
};
// @lc code=end
