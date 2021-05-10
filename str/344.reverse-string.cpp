/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (70.45%)
 * Likes:    2169
 * Dislikes: 754
 * Total Accepted:    979.4K
 * Total Submissions: 1.4M
 * Testcase Example:  '["h","e","l","l","o"]'
 *
 * Write a function that reverses a string. The input string is given as an
 * array of characters char[].
 *
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 *
 * You may assume all the characters consist of printable ascii
 * characters.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: ["h","e","l","l","o"]
 * Output: ["o","l","l","e","h"]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
 *
 *
 *
 *
 */

#include <iostream>
#include <vector>

// @lc code=start
class Solution {
public:
  void reverseString(std::vector<char>& s) {
    int len = s.size();
    if (len < 2) {
      return;
    }

    int left = 0, right = len - 1;
    while (left < right) {
      std::swap(s[left++], s[right--]);
    }
  }
};
// @lc code=end

void print(std::vector<char>& s) {
  for (auto item : s) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char** argv) {
  std::vector<char> s = {'h', 'e', 'l', 'l', 'o'};
  print(s);
  Solution solution;
  solution.reverseString(s);
  print(s);
}
