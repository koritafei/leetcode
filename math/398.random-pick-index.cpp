/*
 * @lc app=leetcode id=398 lang=cpp
 *
 * [398] Random Pick Index
 *
 * https://leetcode.com/problems/random-pick-index/description/
 *
 * algorithms
 * Medium (62.01%)
 * Likes:    835
 * Dislikes: 948
 * Total Accepted:    150.6K
 * Total Submissions: 242.6K
 * Testcase Example:
 * '["Solution","pick","pick","pick"]\n[[[1,2,3,3,3]],[3],[1],[3]]'
 *
 * Given an integer array nums with possible duplicates, randomly output the
 * index of a given target number. You can assume that the given target number
 * must exist in the array.
 *
 * Implement the Solution class:
 *
 *
 * Solution(int[] nums) Initializes the object with the array nums.
 * int pick(int target) Picks a random index i from nums where nums[i] ==
 * target. If there are multiple valid i's, then each index should have an
 * equal probability of returning.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["Solution", "pick", "pick", "pick"]
 * [[[1, 2, 3, 3, 3]], [3], [1], [3]]
 * Output
 * [null, 4, 0, 2]
 *
 * Explanation
 * Solution solution = new Solution([1, 2, 3, 3, 3]);
 * solution.pick(3); // It should return either index 2, 3, or 4 randomly. Each
 * index should have equal probability of returning.
 * solution.pick(1); // It should return 0. Since in the array only nums[0] is
 * equal to 1.
 * solution.pick(3); // It should return either index 2, 3, or 4 randomly. Each
 * index should have equal probability of returning.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 2 * 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * target is an integer from nums.
 * At most 10^4 calls will be made to pick.
 *
 *
 */

#include <cmath>
#include <vector>

// @lc code=start
class Solution {
public:
  Solution(std::vector<int>& nums) {
    nums_ = std::vector<int>(nums.begin(), nums.end());
  }

  int pick(int target) {
    long             count = nums_.size();
    int              res   = 0;
    std::vector<int> tindex;
    for (int i = 0; i < count; i++) {
      if (nums_[i] == target) {
        tindex.push_back(i);
      }
    }

    count = tindex.size();
    int k = 0;
    for (int i = 0; i < count; i++) {
      if (0 == random() % (++k)) {
        res = tindex[i];
      }
    }

    return res;
  }

private:
  std::vector<int> nums_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end
