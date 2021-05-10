/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (40.65%)
 * Likes:    4788
 * Dislikes: 429
 * Total Accepted:    575.8K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,2,1]'
 *
 * Given the head of a singly linked list, return true if it is a
 * palindrome.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,2,1]
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [1, 10^5].
 * 0 <= Node.val <= 9
 *
 *
 *
 * Follow up: Could you do it in O(n) time and O(1) space?
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
  bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return true;
    }

    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }

    fast       = slow->next;
    slow->next = nullptr;
    stack<int> s;
    while (fast) {
      s.push(fast->val);
      fast = fast->next;
    }

    while (head && !s.empty()) {
      if (head->val != s.top()) {
        return false;
      }
      head = head->next;
      s.pop();
    }

    if (head && !head->next) {
      return true;
    }

    if (head || !s.empty()) {
      return false;
    }

    return true;
  }
};
// @lc code=end
