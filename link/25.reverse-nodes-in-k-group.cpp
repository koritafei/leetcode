/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (48.74%)
 * Likes:    5354
 * Dislikes: 455
 * Total Accepted:    429.3K
 * Total Submissions: 880.2K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 *
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes, in the end, should remain as it is.
 *
 * You may not alter the values in the list's nodes, only nodes themselves may
 * be changed.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [2,1,4,3,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2,3,4,5], k = 3
 * Output: [3,2,1,4,5]
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1,2,3,4,5], k = 1
 * Output: [1,2,3,4,5]
 *
 *
 * Example 4:
 *
 *
 * Input: head = [1], k = 1
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range sz.
 * 1 <= sz <= 5000
 * 0 <= Node.val <= 1000
 * 1 <= k <= sz
 *
 *
 *
 * Follow-up: Can you solve the problem in O(1) extra memory space?
 */

struct ListNode {
  int       val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {
  }
  ListNode(int x) : val(x), next(nullptr) {
  }
  ListNode(int x, ListNode* next) : val(x), next(next) {
  }
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == nullptr || k <= 0) {
      return head;
    }

    ListNode *a, *b;  // a逆置之后为每个k段的最后一个节点，b为下一个段的开始节点
    a = b = head;
    for (int i = 0; i < k; i++) {
      if (b == nullptr) {
        return head;
      }
      b = b->next;
    }

    ListNode* newHead = reverse(a, b);
    a->next           = reverseKGroup(b, k);

    return newHead;
  }

private:
  // 翻转[a,b)的元素
  ListNode* reverse(ListNode* a, ListNode* b) {
    ListNode *pre = nullptr, *curr = a, *next;
    while (curr != b) {
      next       = curr->next;
      curr->next = pre;
      pre        = curr;
      curr       = next;
    }

    return pre;
  }
};
// @lc code=end
