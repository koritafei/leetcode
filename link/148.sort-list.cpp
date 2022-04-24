/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (49.24%)
 * Likes:    5477
 * Dislikes: 197
 * Total Accepted:    411.7K
 * Total Submissions: 834.9K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Given the head of a linked list, return the list after sorting it in
 * ascending order.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [4,2,1,3]
 * Output: [1,2,3,4]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [-1,5,3,4,0]
 * Output: [-1,0,3,4,5]
 *
 *
 * Example 3:
 *
 *
 * Input: head = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [0, 5 * 10^4].
 * -10^5 <= Node.val <= 10^5
 *
 *
 *
 * Follow up: Can you sort the linked list in O(n logn) time and O(1) memory
 * (i.e. constant space)?
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
  ListNode *sortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *slow = head, *fast = head->next;  // 防止链表越界
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }

    // 分成两段
    fast       = slow->next;
    slow->next = nullptr;

    ListNode *left  = sortList(head);
    ListNode *right = sortList(fast);

    ListNode *newhead = mergeTwoLists(left, right);

    return newhead;
  }

private:
  ListNode *mergeTwoLists(ListNode *a, ListNode *b) {
    if (!a && !b) {
      return nullptr;
    }
    ListNode *dummy = new ListNode(-1);
    ListNode *curr  = dummy;
    ListNode *next;
    while (a && b) {
      if (a->val < b->val) {
        next       = a->next;
        a->next    = curr->next;
        curr->next = a;
        curr       = curr->next;
        a          = next;
      } else {
        next       = b->next;
        b->next    = curr->next;
        curr->next = b;
        curr       = curr->next;
        b          = next;
      }
    }

    if (a) {
      curr->next = a;
    }

    if (b) {
      curr->next = b;
    }

    curr = dummy->next;
    delete dummy;

    return curr;
  }
};
// @lc code=end
