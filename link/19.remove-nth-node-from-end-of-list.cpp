/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (35.77%)
 * Likes:    4888
 * Dislikes: 290
 * Total Accepted:    811.1K
 * Total Submissions: 2.3M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given the head of a linked list, remove the n^th node from the end of the
 * list and return its head.
 *
 * Follow up: Could you do this in one pass?
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1], n = 1
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1,2], n = 1
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is sz.
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (n < 1 || head == nullptr) {
      return head;
    }

    ListNode* dummy = new ListNode(0);
    dummy->next     = head;

    ListNode* tail = head;
    ListNode* prev = dummy;
    while (n - 1 && tail) {
      tail = tail->next;
      n--;
    }
    if (tail == nullptr) {
      return head;
    }

    while (tail->next) {
      tail = tail->next;
      prev = prev->next;
    }

    ListNode* t = prev->next;
    prev->next  = t->next;
    t           = nullptr;

    head = dummy->next;
    delete (dummy);

    return head;
  }
};
// @lc code=end
