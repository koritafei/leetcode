/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (46.40%)
 * Likes:    3960
 * Dislikes: 169
 * Total Accepted:    342.1K
 * Total Submissions: 737.1K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Given the head of a linked list, return the list after sorting it in
 * ascending order.
 *
 * Follow up: Can you sort the linked list in O(n logn) time and O(1) memory
 * (i.e. constant space)?
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
  ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    fast       = slow->next;
    slow->next = nullptr;

    return mergeTwoLists(sortList(head), sortList(fast));
  }

private:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1 && !l2) {
      return l1;
    }

    ListNode* dummy = new ListNode(0);
    ListNode* tail  = dummy;

    while (l1 && l2) {
      if (l1->val <= l2->val) {
        ListNode* t = l1;
        l1          = l1->next;
        t->next     = tail->next;
        tail->next  = t;
        tail        = t;
      } else {
        ListNode* t = l2;
        l2          = l2->next;
        t->next     = tail->next;
        tail->next  = t;
        tail        = t;
      }
    }

    while (l1) {
      ListNode* t = l1;
      l1          = l1->next;
      t->next     = tail->next;
      tail->next  = t;
      tail        = t;
    }

    while (l2) {
      ListNode* t = l2;
      l2          = l2->next;
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
