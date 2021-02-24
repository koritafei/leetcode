/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (59.15%)
 * Likes:    3748
 * Dislikes: 231
 * Total Accepted:    708.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 *
 * Example 1:
 *
 *
 * Input: [3,2,3]
 * Output: 3
 *
 * Example 2:
 *
 *
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 *
 *
 */

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int len = nums.size();
    int k   = len / 2;
    k++;

    return getKElement(nums, 0, len, k);
  }

private:
  // 查找第k大元素
  int getKElement(vector<int>& nums, int begin, int end, int k) {
    int left = begin, right = end;
    while (left < right) {
      int i = left, j = right - 1;
      int key = nums[left];
      while (i <= j) {
        while (i <= j && nums[i] >= key) {
          i++;
        }
        while (i <= j && nums[j] < key) {
          j--;
        }
        if (i < j) {
          swap(nums[i++], nums[j--]);
        }
      }
      swap(nums[j], nums[left]);
      if (j == k - 1) {
        return nums[j];
      } else if (j > k - 1) {
        right = j;
      } else {
        left = j + 1;
      }
    }
    return INT_MIN;
  }
};
// @lc code=end

int main(int argc, char** argv) {
  vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
  Solution    solution;
  cout << solution.majorityElement(nums) << endl;  // 2
  nums = {2};
  cout << solution.majorityElement(nums) << endl;  // 2
  nums = {2, 2, 3};
  cout << solution.majorityElement(nums) << endl;  // 2
  nums = {3, 2, 2};
  cout << solution.majorityElement(nums) << endl;  // 2
  nums = {2, 2, 3, 3, 3, 3, 2};
  cout << solution.majorityElement(nums) << endl;  // 3
}