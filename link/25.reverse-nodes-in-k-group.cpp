/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (49.18%)
 * Likes:    5640
 * Dislikes: 458
 * Total Accepted:    442.1K
 * Total Submissions: 898.6K
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
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (head == nullptr) {
      return head;
    }

    ListNode *curr = head;
    int       g    = k;
    while (g--) {
      if (curr == nullptr) {
        return head;
      }
      curr = curr->next;
    }

    ListNode *dummy = reserveTwoNode(head, curr);
    head->next      = reverseKGroup(curr, k);

    return dummy;
  }

private:
  ListNode *reserveTwoNode(ListNode *a, ListNode *b) {
    ListNode *dummy = new ListNode(-1);
    dummy->next     = a;
    ListNode *curr  = dummy->next;

    while (a->next != b) {
      ListNode *tmp = a->next;
      a->next       = tmp->next;
      tmp->next     = curr;
      dummy->next   = tmp;
      curr          = tmp;
    }

    curr = dummy->next;

    delete dummy;
    return curr;
  }
};
// @lc code=end

int main() {
  ListNode *l1 = new ListNode(1);
  ListNode *l2 = new ListNode(2);
  ListNode *l3 = new ListNode(3);
  ListNode *l4 = new ListNode(4);
  ListNode *l5 = new ListNode(5);

  l1->next = l2;
  l2->next = l3;
  l3->next = l4;
  l4->next = l5;

  Solution so;
  so.reverseKGroup(l1, 2);
}