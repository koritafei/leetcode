/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (27.78%)
 * Likes:    9734
 * Dislikes: 999
 * Total Accepted:    1.2M
 * Total Submissions: 4.4M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 *
 * Notice that the solution set must not contain duplicate triplets.
 *
 *
 * Example 1:
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Example 2:
 * Input: nums = []
 * Output: []
 * Example 3:
 * Input: nums = [0]
 * Output: []
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 *
 *
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int                 len = nums.size();
    if (len < 3) {
      return result;
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < len; i++) {
      int target = -nums[i];
      int left   = i + 1;
      int right  = len - 1;
      while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum == target) {
          vector<int> t{nums[i], nums[left], nums[right]};
          result.push_back(t);

          while (left < right && nums[left] == t[1]) {
            left++;
          }

          while (left < right && nums[right] == t[2]) {
            right--;
          }
        } else if (sum < target) {
          left++;
        } else {
          right--;
        }
      }

      while (i < len - 1 && nums[i] == nums[i + 1]) {
        i++;
      }
    }

    return result;
  }
};
// @lc code=end

int main(int argc, char** argv) {
  std::vector<int> in = {-1, 0, 1, 2, -1, -4};
  Solution         solution;
  auto             res = solution.threeSum(in);
  for (auto item : res) {
    for (auto i : item) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
