#include <iostream>
#include <vector>

// 两个长度相等的排序数组中求上中位数
int getUpMedian(std::vector<int> &nums, std::vector<int> &vec) {
  if (nums.empty() || vec.empty()) {
    return -1;
  }
  int start1 = 0, end1 = nums.size() - 1;
  int start2 = 0, end2 = vec.size() - 1;
  int mid1 = 0, mid2 = 0;
  int offset = 0;
  while (start1 < end1) {
    mid1 = start1 + (end1 - start1) / 2;
    mid2 = start2 + (end2 - start2) / 2;
    // offset标记end的便宜位置，偶数为1，奇数为0
    offset = ((end1 - start1 + 1) & 1) ^ 1;

    if (nums[mid1] < vec[mid2]) {
      start1 = mid1 + offset;
      end2   = mid2;
    } else if (nums[mid1] > vec[mid2]) {
      start2 = mid2 + offset;
      end1   = mid1;
    } else {
      return nums[mid1];
    }
  }

  return std::min(nums[start1], vec[start2]);
}
