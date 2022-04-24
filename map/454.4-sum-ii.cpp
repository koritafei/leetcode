/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 *
 * https://leetcode.com/problems/4sum-ii/description/
 *
 * algorithms
 * Medium (55.63%)
 * Likes:    2560
 * Dislikes: 91
 * Total Accepted:    195.3K
 * Total Submissions: 350.9K
 * Testcase Example:  '[1,2]\n[-2,-1]\n[-1,2]\n[0,2]'
 *
 * Given four integer arrays nums1, nums2, nums3, and nums4 all of length n,
 * return the number of tuples (i, j, k, l) such that:
 *
 *
 * 0 <= i, j, k, l < n
 * nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 *
 *
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
 * Output: 2
 * Explanation:
 * The two tuples are:
 * 1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) +
 * (-1) + 2 = 0
 * 2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) +
 * (-1) + 0 = 0
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * n == nums1.length
 * n == nums2.length
 * n == nums3.length
 * n == nums4.length
 * 1 <= n <= 200
 * -2^28 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 2^28
 *
 *
 */

#include <unordered_map>
#include <vector>

// @lc code=start
class Solution {
public:
  int fourSumCount(std::vector<int>& nums1,
                   std::vector<int>& nums2,
                   std::vector<int>& nums3,
                   std::vector<int>& nums4) {
    std::unordered_map<int, std::vector<std::pair<int, int>>> sum;

    int res = 0;
    for (int i = 0; i < nums3.size(); i++) {
      for (int j = 0; j < nums4.size(); j++) {
        sum[nums3[i] + nums4[j]].push_back(std::make_pair(i, j));
      }
    }

    for (int i = 0; i < nums1.size(); i++) {
      for (int j = 0; j < nums2.size(); j++) {
        int t = nums1[i] + nums2[j];
        if (sum.find(0 - t) != sum.end()) {
          res += sum[0 - t].size();
        }
      }
    }

    return res;
  }
};
// @lc code=end
