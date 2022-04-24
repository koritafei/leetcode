#include <algorithm>

#include "treenode.h"

class Solution {
public:
  int maxDistance(TreeNode *root) {
    int distance = 0;

    return maxDistance(root, distance);
  }

private:
  int maxDistance(TreeNode *root, int distance) {
    if (nullptr == root) {
      distance = 0;
      return 0;
    }

    int lMax = maxDistance(root->left, distance);  // 左子树上的最大距离
    int maxfromLeft = distance;  // 左子树上的最远节点到当前节点的左子树最远距离
    int rmax = maxDistance(root->right, distance);  // 右子树的最大距离
    int maxfromright =
        distance;  // 右子树上最远的节点到当前节点右子树的最远距离

    int curDistance =
        maxfromLeft + maxfromright + 1;  // 左子树最远距离+右子树最远距离+1
    distance =
        std::max(maxfromLeft, maxfromright) + 1;  // 最远的节点到当前节点的距离

    return std::max(std::max(lMax, rmax), curDistance);  // 最远距离
  }
};