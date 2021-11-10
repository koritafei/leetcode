/*
 * @lc app=leetcode id=382 lang=cpp
 *
 * [382] Linked List Random Node
 *
 * https://leetcode.com/problems/linked-list-random-node/description/
 *
 * algorithms
 * Medium (55.26%)
 * Likes:    1060
 * Dislikes: 266
 * Total Accepted:    113.6K
 * Total Submissions: 205.4K
 * Testcase Example:
 '["Solution","getRandom","getRandom","getRandom","getRandom","getRandom"]\n' +
  '[[[1,2,3]],[],[],[],[],[]]'
 *
 * Given a singly linked list, return a random node's value from the linked
 * list. Each node must have the same probability of being chosen.
 *
 * Implement the Solution class:
 *
 *
 * Solution(ListNode head) Initializes the object with the integer array
 * nums.
 * int getRandom() Chooses a node randomly from the list and returns its value.
 * All the nodes of the list should be equally likely to be choosen.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["Solution", "getRandom", "getRandom", "getRandom", "getRandom",
 * "getRandom"]
 * [[[1, 2, 3]], [], [], [], [], []]
 * Output
 * [null, 1, 3, 2, 2, 3]
 *
 * Explanation
 * Solution solution = new Solution([1, 2, 3]);
 * solution.getRandom(); // return 1
 * solution.getRandom(); // return 3
 * solution.getRandom(); // return 2
 * solution.getRandom(); // return 2
 * solution.getRandom(); // return 3
 * // getRandom() should return either 1, 2, or 3 randomly. Each element should
 * have equal probability of returning.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the linked list will be in the range [1, 10^4].
 * -10^4 <= Node.val <= 10^4
 * At most 10^4 calls will be made to getRandom.
 *
 *
 *
 * Follow up:
 *
 *
 * What if the linked list is extremely large and its length is unknown to
 * you?
 * Could you solve this efficiently without using extra space?
 *
 *
 */

#include <cmath>

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
  Solution(ListNode *head) {
    _head = head;
  }

  int getRandom() {
    ListNode *p   = _head;
    int       i   = 0;
    int       res = 0;

    while (p) {
      if (rand() % (++i) == 0) {
        res = p->val;
      }

      p = p->next;
    }
    return res;
  }

private:
  ListNode *_head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end
