/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start

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

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) {
      return l2;
    }
    ListNode* head    = new ListNode(0);
    ListNode* h1      = l1;
    ListNode* h2      = l2;
    ListNode* newhead = head;

    int tmp = 0;
    while (h1 && h2) {
      int t             = h1->val + h2->val;
      int sum           = t + tmp;
      tmp               = sum / 10;
      ListNode* newnode = new ListNode(sum % 10);
      head->next        = newnode;
      head              = head->next;
      h1                = h1->next;
      h2                = h2->next;
    }

    while (h1) {
      int sum           = h1->val + tmp;
      tmp               = sum / 10;
      ListNode* newnode = new ListNode(sum % 10);
      head->next        = newnode;
      head              = head->next;
      h1                = h1->next;
    }

    while (h2) {
      int sum           = h2->val + tmp;
      tmp               = sum / 10;
      ListNode* newnode = new ListNode(sum % 10);
      head->next        = newnode;
      head              = head->next;
      h2                = h2->next;
    }

    if (tmp) {
      ListNode* newnode = new ListNode(tmp % 10);
      head->next        = newnode;
      head              = head->next;
    }
    head    = newhead;
    newhead = newhead->next;
    delete head;

    return newhead;
  }
};
// @lc code=end
