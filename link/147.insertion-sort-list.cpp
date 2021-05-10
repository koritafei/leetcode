/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
 *
 * https://leetcode.com/problems/insertion-sort-list/description/
 *
 * algorithms
 * Medium (44.47%)
 * Likes:    973
 * Dislikes: 676
 * Total Accepted:    226.5K
 * Total Submissions: 509.3K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Given the head of a singly linked list, sort the list using insertion sort,
 * and return the sorted list's head.
 *
 * The steps of the insertion sort algorithm:
 *
 *
 * Insertion sort iterates, consuming one input element each repetition and
 * growing a sorted output list.
 * At each iteration, insertion sort removes one element from the input data,
 * finds the location it belongs within the sorted list and inserts it
 * there.
 * It repeats until no input elements remain.
 *
 *
 * The following is a graphical example of the insertion sort algorithm. The
 * partially sorted list (black) initially contains only the first element in
 * the list. One element (red) is removed from the input data and inserted
 * in-place into the sorted list with each iteration.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [4,2,1,3]
 * Output: [1,2,3,4]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [-1,5,3,4,0]
 * Output: [-1,0,3,4,5]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [1, 5000].
 * -5000 <= Node.val <= 5000
 *
 *
 */
#include <iostream>

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
  ListNode* insertionSortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode* dummy = new ListNode(0);

    ListNode* pre  = dummy;
    ListNode* curr = pre->next;

    while (head) {
      while (curr && curr->val < head->val) {
        curr = curr->next;
        pre  = pre->next;
      }
      ListNode* t = head;
      head        = head->next;
      t->next     = pre->next;
      pre->next   = t;
      pre         = dummy;
      curr        = pre->next;
    }

    head = dummy->next;
    delete (dummy);
    return head;
  }
};
// @lc code=end

int main(int argc, char** argv) {
  Solution  solution;
  ListNode* a1 = new ListNode(9);
  ListNode* a2 = new ListNode(8);
  ListNode* a3 = new ListNode(4);
  ListNode* a4 = new ListNode(6);
  ListNode* a5 = new ListNode(7);
  a1->next     = a2;
  a2->next     = a3;
  a3->next     = a4;
  a4->next     = a5;
  auto res     = solution.insertionSortList(a1);

  while (res) {
    std::cout << res->val << " ";
    res = res->next;
  }
  std::cout << std::endl;
}
