/*
 * @lc app=leetcode id=16 lang=cpp
 * @lcpr version=30113
 *
 * [16] 3Sum Closest
 */

// @lcpr-template-start

#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
  int threeSumClosest(std::vector<int>& nums, int target) {
    int closet = INT_MAX;
    int res    = 0;

    std::sort(nums.begin(), nums.end());
    int len = nums.size();
    for (int i = 0; i < len; i++) {
      int left = i + 1, right = len - 1;
      while (left < right) {
        int t1 = nums[left], t2 = nums[right];
        int sum  = nums[i] + nums[left] + nums[right];
        int diff = std::abs(target - sum);
        if (diff == 0) {
          return target;
        } else if (diff < closet) {
          closet = diff;
          res    = sum;
        }

        if (sum < target) {
          while ((++left) < right && t1 == nums[left])
            ;
        } else if (sum > target) {
          while ((left < (--right) && t2 == nums[right]))
            ;
        }
      }

      while (i + 1 < len - 1 && nums[i] == nums[i + 1]) {
        i++;
      }
    }

    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [-1,2,1,-4]\n1\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n1\n
// @lcpr case=end

 */
