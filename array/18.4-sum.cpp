/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (34.64%)
 * Likes:    3046
 * Dislikes: 403
 * Total Accepted:    396.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 *
 * Notice that the solution set must not contain duplicate quadruplets.
 *
 *
 * Example 1:
 * Input: nums = [1,0,-1,0,-2,2], target = 0
 * Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * Example 2:
 * Input: nums = [], target = 0
 * Output: []
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 200
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
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
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    int                 len = nums.size();
    if (len < 4) {
      return result;
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < len - 3; i++) {
      int targeter = target - nums[i];

      for (int j = i + 1; j < len - 2; j++) {
        int tmp   = targeter - nums[j];
        int left  = j + 1;
        int right = len - 1;

        while (left < right) {
          int sum = nums[left] + nums[right];
          if (sum == tmp) {
            vector<int> t{nums[i], nums[j], nums[left], nums[right]};
            result.push_back(t);
            while (left < len && nums[left] == t[2]) {
              left++;
            }
            while (right > 0 && nums[right] == t[3]) {
              right--;
            }
          } else if (sum > tmp) {
            right--;
            while (right > 0 && nums[right] == nums[right + 1]) {
              right--;
            }
          } else {
            left++;
            while (left < len && nums[left] == nums[left - 1]) {
              left++;
            }
          }
        }

        while (j < len - 2 && nums[j] == nums[j + 1]) {
          j++;
        }
      }

      while (i < len - 3 && nums[i] == nums[i + 1]) {
        i++;
      }
    }

    return result;
  }
};
// @lc code=ends

int main(int argc, char** argv) {
  std::vector<int> in = {0, 0, 0, 0};
  Solution         solution;
  int              target = 0;
  auto             res    = solution.fourSum(in, target);
  for (auto item : res) {
    for (auto i : item) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
