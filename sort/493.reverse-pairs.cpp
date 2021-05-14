/**
 * @ Description  :
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-05-10 16:25:42
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-05-10 17:12:12
 * @ FilePath     : /leetcode/sort/493.reverse-pairs.cpp
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */
/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 *
 * https://leetcode.com/problems/reverse-pairs/description/
 *
 * algorithms
 * Hard (27.02%)
 * Likes:    1386
 * Dislikes: 145
 * Total Accepted:    54.9K
 * Total Submissions: 200.5K
 * Testcase Example:  '[1,3,2,3,1]'
 *
 * Given an integer array nums, return the number of reverse pairs in the
 * array.
 *
 * A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] >
 * 2 * nums[j].
 *
 *
 * Example 1:
 * Input: nums = [1,3,2,3,1]
 * Output: 2
 * Example 2:
 * Input: nums = [2,4,3,5,1]
 * Output: 3
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 5 * 10^4
 * 2^31 <= nums[i] <= 2^31 - 1
 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int reversePairs(vector<int>& nums) {
    int len = nums.size();
    if (len < 2) {
      return 0;
    }
    int count = 0;

    mergeSort(nums, 0, len, count);

    return count;
  }

private:
  void mergeSort(std::vector<int>& vec, int start, int end, int& count) {
    if (start >= end - 1) {
      return;
    }
    int mid = start + (end - start) / 2;
    mergeSort(vec, start, mid, count);
    mergeSort(vec, mid, end, count);
    merge(vec, start, mid, end, count);
  }

  void merge(std::vector<int>& vec, int start, int mid, int end, int& count) {
    int len1 = mid - start;
    int len2 = end - mid;

    std::vector<int> v1(len1);
    std::vector<int> v2(len2);

    for (int i = 0; i < len1; i++) {
      v1[i] = vec[i + start];
    }

    for (int i = 0; i < len2; i++) {
      v2[i] = vec[i + mid];
    }

    int i = 0, j = 0;
    int k = start;
    while (i < len1 && j < len2) {
      if (v1[i] < v2[j]) {
        vec[k++] = v1[i++];
      } else {
        if ((long long)v1[i] > (long long)(2 * v2[j])) {
          count++;
        }
        vec[k++] = v2[j++];
      }
    }

    while (i < len1) {
      vec[k++] = v1[i++];
    }

    while (j < len2) {
      vec[k++] = v2[j++];
    }
  }
};
// @lc code=end

int main(int argc, char** argv) {
  Solution         s;
  std::vector<int> nums = {1, 3, 2, 3, 1};
  std::cout << s.reversePairs(nums) << std::endl;  // 2
  std::vector<int> nums2 = {2, 4, 3, 5, 1};
  std::cout << s.reversePairs(nums) << std::endl;  // 3
}
