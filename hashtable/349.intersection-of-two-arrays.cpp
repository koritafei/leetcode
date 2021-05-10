/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (64.92%)
 * Likes:    1280
 * Dislikes: 1488
 * Total Accepted:    455.7K
 * Total Submissions: 701.8K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two arrays, write a function to compute their intersection.
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 *
 *
 * Note:
 *
 *
 * Each element in the result must be unique.
 * The result can be in any order.
 *
 *
 *
 *
 */

#include <iostream>
#include <map>
#include <set>
#include <vector>

// @lc code=start
class Solution {
public:
  std::vector<int> intersection(std::vector<int>& nums1,
                                std::vector<int>& nums2) {
    std::set<int> rest;
    std::set<int> m;
    for (auto item : nums1) {
      m.insert(item);
    }

    for (auto item : nums2) {
      if (m.find(item) != m.end()) {
        rest.insert(item);
      }
    }

    std::vector<int> result;
    result.assign(rest.begin(), rest.end());

    return result;
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
  auto             res   = solution.intersection(nums1, nums2);
  print(res);
}
