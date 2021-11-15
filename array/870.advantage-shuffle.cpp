/*
 * @lc app=leetcode id=870 lang=cpp
 *
 * [870] Advantage Shuffle
 *
 * https://leetcode.com/problems/advantage-shuffle/description/
 *
 * algorithms
 * Medium (50.98%)
 * Likes:    1128
 * Dislikes: 71
 * Total Accepted:    49.6K
 * Total Submissions: 97.2K
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
    int len = nums1.size();
    for (int i = 0; i < nums2.size(); ++i) {
      maxpq.push(std::make_pair(i, nums2[i]));
    }

    std::vector<int> res(len, 0);

    sort(nums1.begin(), nums1.end());
    int left = 0, right = len - 1;  // 分别对应nums1中的最大值和最小值

    while (!maxpq.empty()) {
      std::pair<int, int> tmp = maxpq.top();
      maxpq.pop();
      int index = tmp.first, value = tmp.second;
      if (nums1[right] > value) {
        res[index] = nums1[right--];
      } else {
        res[index] = nums1[left++];
      }
    }

    return res;
  }

private:
  struct greater {
    bool operator()(std::pair<int, int> a, std::pair<int, int> b) {
      return b.second >= a.second;
    }
  };

  std::priority_queue<std::pair<int, int>,
                      std::vector<std::pair<int, int>>,
                      greater>
      maxpq;
};
// @lc code=end
