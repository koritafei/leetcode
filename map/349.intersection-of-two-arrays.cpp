/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (67.68%)
 * Likes:    2162
 * Dislikes: 1787
 * Total Accepted:    578.8K
 * Total Submissions: 854.3K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two integer arrays nums1 and nums2, return an array of their
 * intersection. Each element in the result must be unique and you may return
 * the result in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 * Explanation: [4,9] is also accepted.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 1000
 *
 *
 */

#include <map>
#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<int> intersection(std::vector<int>& nums1,
                                std::vector<int>& nums2) {
    std::map<int, bool> freq;
    for (int ch : nums2) {
      freq[ch] = true;
    }
    std::vector<int> res;

    for (int ch : nums1) {
      if (freq.count(ch) && freq[ch]) {
        res.push_back(ch);
        freq[ch] = false;
      }
    }

    return res;
  }
};
// @lc code=end
