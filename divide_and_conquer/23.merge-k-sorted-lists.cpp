/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (40.84%)
 * Likes:    5437
 * Dislikes: 307
 * Total Accepted:    710.7K
 * Total Submissions: 1.7M
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

#include <iostream>
#include <vector>

using namespace std;

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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    int len = lists.size();

    return mergeLists(lists, 0, len);
  }

private:
  ListNode* mergeLists(vector<ListNode*>& lists, int begin, int end) {
    if (begin == end) {
      return nullptr;
    } else if (end - begin == 1) {
      return lists[begin];  // 一定要注意区间的开闭，起始位置的含义
    } else {
      int       middle = (begin + end) / 2;
      ListNode* left   = mergeLists(lists, begin, middle);
      ListNode* right  = mergeLists(lists, middle, end);

      return mergeTwoLists(left, right);
    }
  }

  ListNode* mergeTwoLists(ListNode* first, ListNode* second) {
    ListNode* dummy = new ListNode();
    ListNode* p     = dummy;
    while (first && second) {
      if (first->val <= second->val) {
        p->next = first;
        first   = first->next;
      } else if (second->val < first->val) {
        p->next = second;
        second  = second->next;
      }
      p = p->next;
    }
    if (first) {
      p->next = first;
    }
    if (second) {
      p->next = second;
    }

    p = dummy->next;
    delete dummy;

    return p;
  }
};

int main(int argc, char** argv) {
  ListNode* p1 = new ListNode(1);
  ListNode* p2 = new ListNode(4);
  ListNode* p3 = new ListNode(5);
  p1->next     = p2;
  p2->next     = p3;

  ListNode* p4 = new ListNode(1);
  ListNode* p5 = new ListNode(3);
  ListNode* p6 = new ListNode(4);
  p4->next     = p5;
  p5->next     = p6;

  ListNode* p7 = new ListNode(2);
  ListNode* p8 = new ListNode(6);
  p7->next     = p8;

  vector<ListNode*> v = {p1, p4, p7};
  Solution          s;
  ListNode*         l = s.mergeKLists(v);
}

// @lc code=end
