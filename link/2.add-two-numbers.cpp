/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (35.54%)
 * Likes:    11089
 * Dislikes: 2659
 * Total Accepted:    1.8M
 * Total Submissions: 5.1M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 *
 * Example 1:
 *
 *
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 *
 *
 * Example 2:
 *
 *
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 *
 *
 * Example 3:
 *
 *
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have
 * leading zeros.
 *
 *
 */

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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr && l2 == nullptr) {
      return nullptr;
    }
    ListNode* dummy = new ListNode(0);
    ListNode* tail  = dummy;
    int       next  = 0;
    while (l1 && l2) {
      int       val = l1->val + l2->val + next;
      ListNode* t   = new ListNode(val % 10);
      next          = val / 10;
      t->next       = tail->next;
      tail->next    = t;
      tail          = t;
      l1            = l1->next;
      l2            = l2->next;
    }

    while (l1) {
      int       val = l1->val + next;
      ListNode* t   = new ListNode(val % 10);
      next          = val / 10;
      t->next       = tail->next;
      tail->next    = t;
      tail          = t;
      l1            = l1->next;
    }

    while (l2) {
      int       val = l2->val + next;
      ListNode* t   = new ListNode(val % 10);
      next          = val / 10;
      t->next       = tail->next;
      tail->next    = t;
      tail          = t;
      l2            = l2->next;
    }

    if (next) {
      ListNode* t = new ListNode(next);
      t->next     = tail->next;
      tail->next  = t;
      tail        = t;
    }

    l1 = dummy->next;
    delete (dummy);
    return l1;
  }
};
// @lc code=end
