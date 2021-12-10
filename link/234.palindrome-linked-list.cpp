/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (44.94%)
 * Likes:    7170
 * Dislikes: 489
 * Total Accepted:    813.9K
 * Total Submissions: 1.8M
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

#include <stack>

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
  bool isPalindrome(ListNode *head) {
    if (head == nullptr) {
      return true;
    }

    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }

    // 奇数时slow为中点， fast->next = nullptr
    // 偶数时slow为后半段起点，fast = nullptr;
    std::stack<int> stack;
    ListNode       *r = slow;
    if (fast != nullptr) {
      r = r->next;
    }

    while (r) {
      stack.push(r->val);
      r = r->next;
    }

    r = head;
    while (r != slow) {
      if (r->val == stack.top()) {
        stack.pop();
        r = r->next;
      } else {
        return false;
      }
    }

    return true;
  }
};
// @lc code=end
