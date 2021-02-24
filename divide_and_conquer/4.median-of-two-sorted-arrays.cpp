/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
  public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // 1. 求总长度
    int nums1Len = nums1.size();
    int nums2Len = nums2.size();
    int len      = nums1Len + nums2Len;
    int  middle = len / 2;
    int  j = 0, k = 0;
    int  right = 0, left = 0;
    int  count = 0;
    bool flag  = false;

    // 3. 依据merge算法，求中间点数据的数值。
    while (j < nums1Len && k < nums2Len) {
      if (nums1[j] < nums2[k]) {
        if (count == middle) {
          right = nums1[j];
          flag  = true;
          break;
        }
        j++;
      } else {
        if (count == middle) {
          right = nums2[k];
          flag  = true;
          break;
        }
        k++;
      }
      count++;
    }

    // 处理其余字段
    if (!flag) {
      if (j < nums1Len) {
        right = nums1[j + middle - count];
      } else {
        // nums2剩余
        right = nums2[k + middle - count];
      }
    }

    if (len % 2) {
      // 奇数
      return right * 1.0;
    } else {
      if (j - 1 >= 0) {
        left =
            (k - 1 >= 0 ? std::max(nums1[j - 1], nums2[k - 1]) : nums1[j - 1]);
      } else {
        left = (k - 1 >= 0 ? nums2[k - 1] : 0);
      }

      return (right + left) * 1.0 / 2;
    }
  }
};

// @lc code=end

int main(int argc, char** argv) {
  Solution    solution;
  vector<int> nums1 = {1};
  vector<int> nums2 = {};
  cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
}
