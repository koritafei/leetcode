/**
 * @file AddTwoNumbers.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief 计算链表和
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * Example:

 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * @version 0.1
 * @date 2020-06-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "linkNode.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      // 1. 翻转链表计算，在翻转
      

      return nullptr;
    }
private:
    ListNode *resver(ListNode* head){
      ListNode *dummy;
      while(head){
        ListNode *tmp = head->next;
        ListNode *next = dummy->next;
        dummy->next = head;
        head->next = next;
        head = tmp;
      }
      head = dummy->next;
      delete dummy;
      return head;
    }
};


int main(){

}
