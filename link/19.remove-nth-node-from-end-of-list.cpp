/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (37.13%)
 * Likes:    7352
 * Dislikes: 374
 * Total Accepted:    1.1M
 * Total Submissions: 2.9M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given the head of a linked list, remove the n^th node from the end of the
 * list and return its head.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1], n = 1
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1,2], n = 1
 * Output: [1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is sz.
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 *
 *
 *
 * Follow up: Could you do this in one pass?
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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == nullptr || n < 1) {
      return head;
    }

    ListNode* dummy = new ListNode(-1);
    dummy->next     = head;
    ListNode* p     = FindKthNode(dummy, n + 1);

    p->next = p->next->next;

    p = dummy->next;
    delete dummy;
    return p;
  }

private:
  ListNode* FindKthNode(ListNode* head, int k) {
    ListNode* p = head;
    for (int i = 1; i <= k; i++) {
      p = p->next;
    }

    ListNode* q = head;
    while (p != nullptr) {
      p = p->next;
      q = q->next;
    }

    return q;
  }
};
// @lc code=end

int main(int argc, char** argv) {
  // [1,2,3,4,5], n = 2
  ListNode* head  = new ListNode(1);
  ListNode* h1    = new ListNode(2);
  ListNode* head2 = new ListNode(3);
  ListNode* head3 = new ListNode(4);
  ListNode* head4 = new ListNode(5);

  head->next  = h1;
  h1->next    = head2;
  head2->next = head3;
  head3->next = head4;

  Solution solution;
  solution.removeNthFromEnd(head, 2);
}
