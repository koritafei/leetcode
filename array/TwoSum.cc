/**
 * @file TwoSum.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief leetcode Two Sum
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target. You may assume that each input would have
 * exactly one solution, and you may not use the same element twice. Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * @version 0.1
 * @date 2020-06-14
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> res;                    // 存储结果
    std::unordered_map<int, int> store; // 结果设计为，<值， index>
    size_t len = nums.size();
    for (size_t i = 0; i < len; i++) {
      if (store.count(target - nums[i])) {
        res.push_back(store[target - nums[i]]);
        res.push_back(i);
        return res;
      }
      store[nums[i]] = i;
    }
    return res;
  }
};

int main(int argc, char **argv) {
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  Solution solution;
  std::vector<int> res;
  res = solution.twoSum(nums, target);
  for (auto item : res) {
    std::cout << item;
  }
  std::cout << std::endl;
  return 0;
}
