/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (43.51%)
 * Likes:    1903
 * Dislikes: 376
 * Total Accepted:    252K
 * Total Submissions: 578.9K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given the head of a linked list and a value x, partition it such that all
 * nodes less than x come before nodes greater than or equal to x.
 *
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,4,3,2,5,2], x = 3
 * Output: [1,2,2,4,3,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [2,1], x = 2
 * Output: [1,2]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [0, 200].
 * -100 <= Node.val <= 100
 * -200 <= x <= 200
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
  ListNode* partition(ListNode* head, int x) {
    if (head == nullptr) {
      return head;
    }

    ListNode* dummy1 = new ListNode(0);
    ListNode* tail1  = dummy1;
    ListNode* dummy2 = new ListNode(0);
    ListNode* tail2  = dummy2;

    while (head) {
      if (head->val < x) {
        ListNode* t = head;
        head        = head->next;
        t->next     = tail1->next;
        tail1->next = t;
        tail1       = t;
      } else {
        ListNode* t = head;
        head        = head->next;
        t->next     = tail2->next;
        tail2->next = t;
        tail2       = t;
      }
    }

    tail1->next = dummy2->next;
    head        = dummy1->next;
    delete (dummy1);
    delete (dummy2);
    return head;
  }
};
// @lc code=end
