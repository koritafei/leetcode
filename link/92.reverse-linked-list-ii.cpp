/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (40.66%)
 * Likes:    3413
 * Dislikes: 176
 * Total Accepted:    335.3K
 * Total Submissions: 824.5K
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
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* dummy1 = new ListNode(0);
    ListNode* dummy2 = new ListNode(0);
    ListNode* dummy3 = new ListNode(0);

    ListNode* tail1 = dummy1;
    ListNode* tail2 = dummy2;
    ListNode* tail3 = dummy3;

    int count = 1;
    while (count++ < left) {
      ListNode* t1 = head;
      head         = head->next;
      t1->next     = tail1->next;
      tail1->next  = t1;
      tail1        = t1;
    }

    while (count++ <= right+1) {
      ListNode* t2 = head;
      head         = head->next;
      t2->next     = dummy2->next;
      dummy2->next = t2;
    }

    while (tail2->next) {
      tail2 = tail2->next;
    }

    while (head) {
      ListNode* t3 = head;
      head         = head->next;
      t3->next     = tail1->next;
      tail3->next  = t3;
      tail3        = t3;
    }

    tail1->next = dummy2->next;
    tail2->next = dummy3->next;
    head        = dummy1->next;
    delete (dummy1);
    delete (dummy2);
    delete (dummy3);

    return head;
  }
};
// @lc code=end
