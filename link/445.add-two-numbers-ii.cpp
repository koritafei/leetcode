/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (56.35%)
 * Likes:    2205
 * Dislikes: 197
 * Total Accepted:    225.9K
 * Total Submissions: 400.8K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the
 * lists is not allowed.
 *
 *
 *
 * Example:
 *
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (!l1 && !l2) {
      return l1;
    }
    stack<int> s1;
    stack<int> s2;
    int        next  = 0;
    ListNode*  dummy = new ListNode(0);
    ListNode*  tail  = dummy;

    while (l1) {
      s1.push(l1->val);
      l1 = l1->next;
    }

    while (l2) {
      s2.push(l2->val);
      l2 = l2->next;
    }

    while (!s1.empty() && !s2.empty()) {
      int val = s1.top() + s2.top() + next;
      s1.pop();
      s2.pop();
      ListNode* t = new ListNode(val % 10);
      next        = val / 10;
      t->next     = dummy->next;
      dummy->next = t;
    }

    while (!s1.empty()) {
      int val = s1.top() + next;
      s1.pop();
      ListNode* t = new ListNode(val % 10);
      next        = val / 10;
      t->next     = dummy->next;
      dummy->next = t;
    }

    while (!s2.empty()) {
      int val = s2.top() + next;
      s2.pop();
      ListNode* t = new ListNode(val % 10);
      next        = val / 10;
      t->next     = dummy->next;
      dummy->next = t;
    }

    if (next) {
      ListNode* t = new ListNode(next);
      t->next     = dummy->next;
      dummy->next = t;
    }

    l1 = dummy->next;
    delete (dummy);
    return l1;
  }
};
// @lc code=end
