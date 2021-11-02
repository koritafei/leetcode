/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (44.98%)
 * Likes:    9096
 * Dislikes: 393
 * Total Accepted:    1M
 * Total Submissions: 2.3M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * You are given an array of k linked-lists lists, each linked-list is sorted
 * in ascending order.
 *
 * Merge all the linked-lists into one sorted linked-list and return it.
 *
 *
 * Example 1:
 *
 *
 * Input: lists = [[1,4,5],[1,3,4],[2,6]]
 * Output: [1,1,2,3,4,4,5,6]
 * Explanation: The linked-lists are:
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * merging them into one sorted list:
 * 1->1->2->3->4->4->5->6
 *
 *
 * Example 2:
 *
 *
 * Input: lists = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: lists = [[]]
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] is sorted in ascending order.
 * The sum of lists[i].length won't exceed 10^4.
 *
 *
 */

#include <queue>
#include <vector>
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
  ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    // 构建一个小根堆
    std::priority_queue<ListNode*, std::vector<ListNode*>, greater> pq;
    for (auto head : lists) {
      if (head != nullptr) {
        pq.push(head);
      }
    }

    ListNode* dummy = new ListNode();
    ListNode* p     = dummy;

    while (pq.size()) {
      ListNode* node = pq.top();
      pq.pop();
      if (node->next != nullptr) {
        pq.push(node->next);
      }

      p->next = node;
      p       = node;
    }

    p = dummy->next;
    delete dummy;
    return p;
  }

private:
  struct greater {
    bool operator()(const ListNode* t1, const ListNode* t2) {
      return t1->val >= t2->val;
    }
  };
};
// @lc code=end
