/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (47.86%)
 * Likes:    3563
 * Dislikes: 164
 * Total Accepted:    709.1K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,1,2]'
 *
 * Given the head of a sorted linked list, delete all duplicates such that each
 * element appears only once. Return the linked list sorted as well.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,1,2]
 * Output: [1,2]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,1,2,3,3]
 * Output: [1,2,3]
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

struct ListNode {
  int       val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {
  }
  ListNode(int x) : val(x), next(nullptr) {
  }
  ListNode(int x, ListNode* next) : val(x), next(next) {
  }
};

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
    if (nullptr == head) {
      return head;
    }
    ListNode *slow = head, *fast = head->next;

    while (fast) {
      if (slow->val != fast->val) {
        slow->next = fast;
        slow       = slow->next;
      }
      fast = fast->next;
    }

    slow->next = nullptr;
    return head;
  }
};
// @lc code=end
