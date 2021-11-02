/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
 *
 * https://leetcode.com/problems/middle-of-the-linked-list/description/
 *
 * algorithms
 * Easy (70.66%)
 * Likes:    3558
 * Dislikes: 94
 * Total Accepted:    433.7K
 * Total Submissions: 613.9K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the head of a singly linked list, return the middle node of the linked
 * list.
 *
 * If there are two middle nodes, return the second middle node.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5]
 * Output: [3,4,5]
 * Explanation: The middle node of the list is node 3.
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2,3,4,5,6]
 * Output: [4,5,6]
 * Explanation: Since the list has two middle nodes with values 3 and 4, we
 * return the second one.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [1, 100].
 * 1 <= Node.val <= 100
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
  ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }
};
// @lc code=end
