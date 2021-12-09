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
    std::vector<int> res;
    res.resize(nums1.size());
    std::sort(nums1.begin(), nums1.end());

    std::priority_queue<std::pair<int, int>,
                        std::vector<std::pair<int, int>>,
                        less>
        hp;

    for (int i = 0; i < nums2.size(); i++) {
      hp.push(std::make_pair(nums2[i], i));
    }

    int left = 0, right = nums1.size() - 1;
    while (hp.size()) {
      std::pair<int, int> p = hp.top();
      hp.pop();
      if (nums1[right] > p.first) {
        res[p.second] = nums1[right--];
      } else {
        res[p.second] = nums1[left++];
      }
    }

    return res;
  }

private:
  struct less {
    bool operator()(const std::pair<int, int>& v1,
                    const std::pair<int, int>& v2) {
      return v1.first < v2.first;
    }
  };
};
// @lc code=end
