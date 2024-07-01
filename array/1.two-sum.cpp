/*
 * @lc app=leetcode id=1 lang=cpp
 * @lcpr version=30113
 *
 * [1] Two Sum
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
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    int                          len = nums.size();
    std::vector<int>             res;
    std::unordered_map<int, int> map;

    for (int i = 0; i < len; i++) {
      if (map.find(target - nums[i]) != map.end()) {
        res.push_back(i);
        res.push_back(map[target - nums[i]]);
      }

      map.insert(std::make_pair(nums[i], i));
    }

    return res;
  }
};
// @lc code=end

/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */
