#include <stack>
#include <vector>

#include "treenode.h"

class Traver {
public:
  std::vector<int> traverse(TreeNode *root) {
    pushLeftNode(root);
    TreeNode *visit;  // 上一次遍历完成根节点

    while (stack.size()) {
      TreeNode *curr = stack.top();

      // 左子树遍历完成处理右子树
      if ((nullptr == curr->left || visit == curr->left) ||
          (nullptr != curr->right)) {
        // 中序遍历位置
        pushLeftNode(curr->right);
      }

      // 右子树遍历完成
      if (nullptr == curr->right || visit == curr->right) {
        // 后序遍历位置
        // 以p为根的子树遍历完成出栈
        stack.pop();
        visit = curr;
      }
    }
  }

private:
  void pushLeftNode(TreeNode *node) {
    while (node != nullptr) {
      // 先序遍历位置
      stack.push(node);
      node = node->left;
    }
  }

  std::stack<TreeNode *> stack;  // 模拟系统栈实现
  std::vector<int>       res;    // 存储结果集
};
