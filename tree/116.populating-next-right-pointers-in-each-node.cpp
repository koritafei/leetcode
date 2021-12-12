/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
 *
 * algorithms
 * Medium (53.71%)
 * Likes:    4908
 * Dislikes: 206
 * Total Accepted:    608.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,4,5,6,7]'
 *
 * You are given a perfect binary tree where all leaves are on the same level,
 * and every parent has two children. The binary tree has the following
 * definition:
 *
 *
 * struct Node {
 * ⁠ int val;
 * ⁠ Node *left;
 * ⁠ Node *right;
 * ⁠ Node *next;
 * }
 *
 *
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL.
 *
 * Initially, all next pointers are set to NULL.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,4,5,6,7]
 * Output: [1,#,2,3,#,4,5,6,7,#]
 * Explanation: Given the above perfect binary tree (Figure A), your function
 * should populate each next pointer to point to its next right node, just like
 * in Figure B. The serialized output is in level order as connected by the
 * next pointers, with '#' signifying the end of each level.
 *
 *
 * Example 2:
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
 * The number of nodes in the tree is in the range [0, 2^12 - 1].
 * -1000 <= Node.val <= 1000
 *
 *
 *
 * Follow-up:
 *
 *
 * You may only use constant extra space.
 * The recursive approach is fine. You may assume implicit stack space does not
 * count as extra space for this problem.
 *
 *
 */

#include <iostream>

class Node {
public:
  int   val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {
  }

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {
  }

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {
  }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
  Node* connect(Node* root) {
    if (root == nullptr) {
      return nullptr;
    }
    connect(root->left, root->right);
    return root;
  }

private:
  void connect(Node* node1, Node* node2) {
    if (!node1 || !node2) {
      return;
    }

    node1->next = node2;
    connect(node1->left, node1->right);
    connect(node2->left, node2->right);
    connect(node1->right, node2->left);
  }
};
// @lc code=end
