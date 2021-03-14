/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (51.98%)
 * Likes:    2077
 * Dislikes: 509
 * Total Accepted:    472K
 * Total Submissions: 908.1K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two arrays, write a function to compute their intersection.
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2,2]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [4,9]
 *
 *
 * Note:
 *
 *
 * Each element in the result should appear as many times as it shows in both
 * arrays.
 * The result can be in any order.
 *
 *
 * Follow up:
 *
 *
 * What if the given array is already sorted? How would you optimize your
 * algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is
 * better?
 * What if elements of nums2 are stored on disk, and the memory is limited such
 * that you cannot load all elements into the memory at once?
 *
 *
 */

#include <iostream>
#include <unordered_map>
#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_map<int, int> m;
    std::vector<int>             res;

    for (auto item : nums1) {
      m[item]++;
    }

    for (auto item : nums2) {
      if (m.find(item) != m.end() && m[item] != 0) {
        m[item]--;
        res.push_back(item);
      }
    }

    return res;
  }
};
// @lc code=end

void print(std::vector<int>& s) {
  for (auto item : s) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char** argv) {
  Solution         solution;
  std::vector<int> nums1 = {1, 2, 2, 1};
  std::vector<int> nums2 = {2, 2};
  auto             res   = solution.intersect(nums1, nums2);
  print(res);
}
