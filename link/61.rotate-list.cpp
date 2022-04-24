/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 *
 * https://leetcode.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (33.05%)
 * Likes:    3368
 * Dislikes: 1206
 * Total Accepted:    441.4K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given the head of a linked list, rotate the list to the right by k
 * places.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [4,5,1,2,3]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [0,1,2], k = 4
 * Output: [2,0,1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [0, 500].
 * -100 <= Node.val <= 100
 * 0 <= k <= 2 * 10^9
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
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || k <= 0) {
      return head;
    }

    int       count = 1;
    ListNode* curr  = head;
    while (curr->next) {
      curr = curr->next;
      count++;
    }

    k = k % count;
    if (count <= 1 || k <= 0) {
      return head;
    }

    ListNode* dummy = new ListNode();
    dummy->next     = head;
    ListNode* prev  = dummy;
    ListNode* p     = head;
    for (int i = 1; i <= k && p; i++) {
      p = p->next;
    }

    ListNode* q = head;
    while (p) {
      prev = q;
      p    = p->next;
      q    = q->next;
    }

    prev->next = nullptr;
    head       = q;
    while (q->next) {
      q = q->next;
    }

    q->next = dummy->next;
    delete dummy;
    return head;
  }
};
// @lc code=end
