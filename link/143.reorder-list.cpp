/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (44.46%)
 * Likes:    4405
 * Dislikes: 177
 * Total Accepted:    392.1K
 * Total Submissions: 879.3K
 * Testcase Example:  '[1,2,3,4]'
 *
 * You are given the head of a singly linked-list. The list can be represented
 * as:
 *
 *
 * L0 → L1 → … → Ln - 1 → Ln
 *
 *
 * Reorder the list to be on the following form:
 *
 *
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 *
 *
 * You may not modify the values in the list's nodes. Only nodes themselves may
 * be changed.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4]
 * Output: [1,4,2,3]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2,3,4,5]
 * Output: [1,5,2,4,3]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [1, 5 * 10^4].
 * 1 <= Node.val <= 1000
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
  void reorderList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return;
    }

    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }

    fast       = slow->next;
    slow->next = nullptr;

    // 翻转后半部分
    ListNode *next  = reverseList(fast);
    ListNode *dummy = new ListNode(-1);
    ListNode *curr;
    ListNode *p = dummy;

    while (head && next) {
      curr       = head->next;
      head->next = p->next;
      p->next    = head;
      head       = curr;
      p          = p->next;

      curr       = next->next;
      next->next = p->next;
      p->next    = next;
      next       = curr;
      p          = p->next;
    }

    if (head) {
      p->next = head;
    }

    if (next) {
      p->next = next;
    }

    head = dummy->next;
    delete dummy;
  }

private:
  ListNode *reverseList(ListNode *head) {
    ListNode *dummy = new ListNode(-1);
    ListNode *next;
    while (head) {
      next        = head->next;
      head->next  = dummy->next;
      dummy->next = head;
      head        = next;
    }
    head = dummy->next;
    delete (dummy);

    return head;
  }
};
// @lc code=end
