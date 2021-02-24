/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (56.12%)
 * Likes:    4266
 * Dislikes: 283
 * Total Accepted:    699.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 *
 * Example 1:
 *
 *
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 *
 *
 * Example 2:
 *
 *
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 *
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 *
 */

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    int len = nums.size();
    if (k <= 0 || k > len) {
      return INT_MIN;
    }
    int low = 0, high = len;
    while (low < high) {
      int i = low, j = high - 1;
      int key = nums[low];
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
      swap(nums[j], nums[low]);
      if (j == k - 1) {
        return nums[j];
      } else if (j > k - 1) {
        high = j;
      } else {
        low = j + 1;
      }
    }
    return INT_MIN;
  }
};
// @lc code=end

int main(int argc, char** argv) {
  vector<int> nums = {3, 2, 1, 5, 6, 4};
  int         k    = 2;
  Solution    solution;
  cout << solution.findKthLargest(nums, k) << endl;  // 5
}