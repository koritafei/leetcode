/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (42.68%)
 * Likes:    5132
 * Dislikes: 245
 * Total Accepted:    429.5K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Given the head of a singly linked list and two integers left and right where
 * left <= right, reverse the nodes of the list from position left to position
 * right, and return the reversed list.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5], left = 2, right = 4
 * Output: [1,4,3,2,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [5], left = 1, right = 1
 * Output: [5]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is n.
 * 1 <= n <= 500
 * -500 <= Node.val <= 500
 * 1 <= left <= right <= n
 *
 *
 *
 * Follow up: Could you do it in one pass?
 */

#include "linkNode.h"

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
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (head == nullptr) {
      return nullptr;
    }

    ListNode *dummy = new ListNode(-1);
    dummy->next     = head;

    ListNode *a = dummy, *b = head;
    while (--left) {
      if (a == nullptr) {
        return head;
      }
      a = a->next;
    }

    while (right--) {
      if (b == nullptr) {
        break;
      }
      b = b->next;
    }

    // 反转(a,b)
    reverseBetween(a, b);

    head = dummy->next;
    delete dummy;

    return head;
  }

private:
  ListNode *reverseBetween(ListNode *a, ListNode *b) {
    ListNode *dummy = a;
    ListNode *curr  = a->next;

    while (curr->next != b) {
      ListNode *tmp = curr->next;
      curr->next    = tmp->next;

      tmp->next   = dummy->next;
      dummy->next = tmp;
    }

    return a;
  }
};
// @lc code=end
