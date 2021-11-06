/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (42.51%)
 * Likes:    4931
 * Dislikes: 242
 * Total Accepted:    420.1K
 * Total Submissions: 987.9K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Given the head of a singly linked list and two integers left and right where
 * left <= right, reverse the nodes of the list from position left to position
 * right, and return the reversed list.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5], left = 2, right = 4
 * Output: [1,4,3,2,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [5], left = 1, right = 1
 * Output: [5]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is n.
 * 1 <= n <= 500
 * -500 <= Node.val <= 500
 * 1 <= left <= right <= n
 *
 *
 *
 * Follow up: Could you do it in one pass?
 */

#include <stdio.h>

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

void print(ListNode* head) {
  ListNode* p = head;
  while (p) {
    printf("%d ", p->val);
    p = p->next;
  }
}

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
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (head == nullptr || m >= n) {
      return head;
    }

    if (m == n) return head;
    n -= m;
    ListNode prehead(0);
    prehead.next  = head;
    ListNode* pre = &prehead;
    while (--m) pre = pre->next;
    ListNode* pstart = pre->next;
    int       len    = n - m;
    while (len--) {
      ListNode* p  = pstart->next;
      pstart->next = p->next;
      p->next      = pre->next;
      pre->next    = p;
    }
    return prehead.next;
  }
};

// @lc code=end

int main(int argc, char** argv) {
  ListNode* p1 = new ListNode(3);
  ListNode* p2 = new ListNode(5);
  p1->next     = p2;

  Solution  solution;
  ListNode* t = solution.reverseBetween(p1, 1, 2);
  print(t);
}
