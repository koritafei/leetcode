/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (37.35%)
 * Likes:    15139
 * Dislikes: 3292
 * Total Accepted:    2.3M
 * Total Submissions: 6.3M
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    int       k     = 0;  // 保存进位
    ListNode* p1    = l1;
    ListNode* p2    = l2;
    ListNode* curr  = dummy;
    while (p1 && p2) {
      int sum        = p1->val + p2->val + k;
      k              = sum / 10;
      ListNode* node = new ListNode(sum % 10);
      curr->next     = node;
      curr           = node;
      p1             = p1->next;
      p2             = p2->next;
    }

    while (p1) {
      int sum        = p1->val + k;
      k              = sum / 10;
      ListNode* node = new ListNode(sum % 10);
      curr->next     = node;
      curr           = node;
      p1             = p1->next;
    }

    while (p2) {
      int sum        = p2->val + k;
      k              = sum / 10;
      ListNode* node = new ListNode(sum % 10);
      curr->next     = node;
      curr           = node;
      p2             = p2->next;
    }

    if (k) {
      ListNode* node = new ListNode(k);
      curr->next     = node;
    }

    curr = dummy->next;
    delete dummy;
    return curr;
  }
};
// @lc code=end
