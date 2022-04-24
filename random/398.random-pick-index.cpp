/*
 * @lc app=leetcode id=398 lang=cpp
 *
 * [398] Random Pick Index
 *
 * https://leetcode.com/problems/random-pick-index/description/
 *
 * algorithms
 * Medium (61.49%)
 * Likes:    814
 * Dislikes: 938
 * Total Accepted:    146.1K
 * Total Submissions: 237.1K
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

#include <vector>

// @lc code=start
class Solution {
public:
  Solution(std::vector<int>& nums) {
    _nums = std::move(nums);
  }

  int pick(int target) {
    int res = 0;
    int k   = 0;
    // 查找所有等于target的index位置
    std::vector<int> tindex;
    for (int i = 0; i < _nums.size(); i++) {
      if (target == _nums[i]) {
        tindex.push_back(i);
      }
    }

    for (int i = 0; i < tindex.size(); i++) {
      if (0 == rand() % (++k)) {
        res = tindex[i];
      }
    }

    return res;
  }

private:
  std::vector<int> _nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// @lc code=end
