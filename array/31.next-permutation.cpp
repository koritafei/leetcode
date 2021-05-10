/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (33.82%)
 * Likes:    5150
 * Dislikes: 1767
 * Total Accepted:    490K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 *
 * If such an arrangement is not possible, it must rearrange it as the lowest
 * possible order (i.e., sorted in ascending order).
 *
 * The replacement must be in place and use only constant extra memory.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3]
 * Output: [1,3,2]
 * Example 2:
 * Input: nums = [3,2,1]
 * Output: [1,2,3]
 * Example 3:
 * Input: nums = [1,1,5]
 * Output: [1,5,1]
 * Example 4:
 * Input: nums = [1]
 * Output: [1]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 100
 *
 *
 */

// @lc code=start
class Solution {
public:
  void nextPermutation(std::vector<int>& nums) {
    nextPermutation(nums.begin(), nums.end());
  }

private:
  void nextPermutation(std::vector<int>::iterator begin,
                       std::vector<int>::iterator end) {
    if (begin == end) {
      return;
    }

    std::vector<int>::iterator it = end;
    if (begin == --it) {
      return;
    }

    while (true) {
      std::vector<int>::iterator it1, it2;
      it1 = it;
      if (*--it < *it1) {
        it2 = end;
        while (*it >= *--it2)
          ; // 查找第一个比当前小元素小的位置
        std::iter_swap(it, it2);
        std::reverse(it1, end);
        return;
      }
      if (it == begin) {
        std::reverse(begin, end);
        return;
      }
    }
  }
};
// @lc code=end
