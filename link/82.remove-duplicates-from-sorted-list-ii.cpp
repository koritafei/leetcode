/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (39.33%)
 * Likes:    2733
 * Dislikes: 122
 * Total Accepted:    319.2K
 * Total Submissions: 811.4K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given the head of a sorted linked list, delete all nodes that have duplicate
 * numbers, leaving only distinct numbers from the original list. Return the
 * linked list sorted as well.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,3,4,4,5]
 * Output: [1,2,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,1,1,2,3]
 * Output: [2,3]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [0, 300].
 * -100 <= Node.val <= 100
 * The list is guaranteed to be sorted in ascending order.
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
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode*             dummy = new ListNode(0);
    ListNode*             tail  = dummy;
    unordered_map<int, int> m;
    ListNode*             t = head;
    while (t) {
      m[t->val]++;
      t = t->next;
    }
    t = head;

    while (t) {
      if (m[t->val] == 1) {
        ListNode* tmp = t;
        t             = t->next;
        tmp->next     = tail->next;
        tail->next    = tmp;
        tail          = tmp;
      } else {
        t = t->next;
      }
    }
    head = dummy->next;
    delete (dummy);
    return head;
  }
};
// @lc code=end
