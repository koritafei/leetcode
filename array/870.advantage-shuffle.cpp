/*
 * @lc app=leetcode id=870 lang=cpp
 *
 * [870] Advantage Shuffle
 *
 * https://leetcode.com/problems/advantage-shuffle/description/
 *
 * algorithms
 * Medium (50.98%)
 * Likes:    1145
 * Dislikes: 72
 * Total Accepted:    50K
 * Total Submissions: 98K
 * Testcase Example:  '[2,7,11,15]\n[1,10,4,11]'
 *
 * You are given two integer arrays nums1 and nums2 both of the same length.
 * The advantage of nums1 with respect to nums2 is the number of indices i for
 * which nums1[i] > nums2[i].
 *
 * Return any permutation of nums1 that maximizes its advantage with respect to
 * nums2.
 *
 *
 * Example 1:
 * Input: nums1 = [2,7,11,15], nums2 = [1,10,4,11]
 * Output: [2,11,7,15]
 * Example 2:
 * Input: nums1 = [12,24,8,32], nums2 = [13,25,32,11]
 * Output: [24,32,8,12]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums1.length <= 10^5
 * nums2.length == nums1.length
 * 0 <= nums1[i], nums2[i] <= 10^9
 *
 *
 */

#include <algorithm>
#include <queue>
#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<int> advantageCount(std::vector<int>& nums1,
                                  std::vector<int>& nums2) {
    int              len1 = nums1.size(), len2 = nums2.size();
    std::vector<int> res;
    if (len1 == 0 || len2 == 0 || len1 != len2) {
      return res;
    }

    res = std::vector<int>(len1, 0);

    std::vector<std::pair<int, int>> tmp;

    for (int i = 0; i < len1; i++) {
      tmp.push_back(std::make_pair(i, nums2[i]));
    }

    std::sort(nums1.begin(), nums1.end());

    std::sort(tmp.begin(),
              tmp.end(),
              [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
                return p1.second < p2.second;
              });

    int left = 0, right = len1 - 1;

    for (int i = len2 - 1; i >= 0; i--) {
      if (tmp[i].second >= nums1[right]) {
        res[tmp[i].first] = nums1[left++];
      } else {
        res[tmp[i].first] = nums1[right--];
      }
    }

    return res;
  }
};
// @lc code=end
