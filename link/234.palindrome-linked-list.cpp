/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (44.60%)
 * Likes:    6854
 * Dislikes: 483
 * Total Accepted:    789.6K
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

struct ListNode {
  int       val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {
  }
  ListNode(int x) : val(x), next(nullptr) {
  }
  ListNode(int x, ListNode *next) : val(x), next(next) {
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
  bool isPalindrome(ListNode *head) {
    ListNode *slow = head, *fast = head;
    // slow为后半段第一个节点
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // 长度为奇数时，slow正好为中点
    if (fast) {
      slow = slow->next;
    }

    // 逆置
    ListNode *second = reserve(slow);

    // 判断是否问回文串
    return isPalindrome(head, second);
  }

private:
  bool isPalindrome(ListNode *head, ListNode *second) {
    while (second) {
      if (head->val != second->val) {
        return false;
      }
      head   = head->next;
      second = second->next;
    }

    return true;
  }

  ListNode *reserve(ListNode *head) {
    ListNode *dummy = new ListNode();
    while (head) {
      ListNode *p = head;
      head        = head->next;
      p->next     = dummy->next;
      dummy->next = p;
    }

    head = dummy->next;
    delete dummy;

    return head;
  }
};
// @lc code=end
