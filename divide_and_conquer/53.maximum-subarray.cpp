/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (46.89%)
 * Likes:    9091
 * Dislikes: 431
 * Total Accepted:    1.1M
 * Total Submissions: 2.4M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 *
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution using the divide and conquer approach, which is more subtle.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1]
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [0]
 * Output: 0
 *
 *
 * Example 4:
 *
 *
 * Input: nums = [-1]
 * Output: -1
 *
 *
 * Example 5:
 *
 *
 * Input: nums = [-2147483647]
 * Output: -2147483647
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 2 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
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
  int maxSubArray(vector<int>& nums) {
    int len = nums.size();

    return maxSubArray(nums, 0, len);
  }

private:
  int maxSubArray(vector<int>& nums, int begin, int end) {
    if (begin == end) {
      return Nan;
    }
    if (end - begin == 1) {
      return nums[begin];
    }
    int middle = (begin + end) / 2;
    int left   = maxSubArray(nums, begin, middle);
    int right  = maxSubArray(nums, middle, end);
    int cross  = maxCrossSum(nums, begin, middle, end);
    return max(max(left, right), cross);
  }

  int maxCrossSum(vector<int>& nums, int begin, int middle, int end) {
    int max_left  = INT_MIN;
    int max_right = INT_MIN;
    int sum       = 0;
    for (int i = middle - 1; i >= begin; i--) {
      sum += nums[i];
      if (sum > max_left) {
        max_left = sum;
      }
    }
    sum = 0;
    for (int i = middle; i < end; i++) {
      sum += nums[i];
      if (sum > max_right) {
        max_right = sum;
      }
    }
    return max_left + max_right;
  }

  const int Nan = -1;
};

int main(int argc, char** argv) {
  vector<int> nums = {
      -2, 1, -3, 4, -1, 2, 1, -5,
  };
  Solution solution;
  cout << solution.maxSubArray(nums) << endl;
}

// @lc code=end
