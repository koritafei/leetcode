/**
 * @ Description  : 全排列
 * @ Version      : 1.0
 * @ Author       : koritafei(koritafei@gmail.com)
 * @ Date         : 2021-05-14 13:50:42
 * @ LastEditors  : koritafei(koritafei@gmail.com)
 * @ LastEditTime : 2021-05-14 14:24:21
 * @ FilePath     : /leetcode/backtrace/perm.cc
 * @ Copyright (C) 2021 koritafei(koritafei@gmail.com). All rights reserved.
 * */

#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> perm(std::vector<int> &nums) {
    std::vector<int> tmp;
    perm(nums, 0, tmp);
    return res;
  }

private:
  void perm(std::vector<int> &nums, int i, std::vector<int> &tmp) {
    if (i == nums.size()) {
      res.push_back(tmp);
      return;
    }

    for (int j = 0; j < nums.size(); j++) {
      if (find(tmp.begin(), tmp.end(), nums[j]) != tmp.end()) {
        continue;
      }
      tmp.push_back(nums[j]);
      perm(nums, i + 1, tmp);
      tmp.pop_back();
    }
  }

  std::vector<std::vector<int>> res;
};

int main(int argc, char **argv) {
  std::vector<int> vec = {1, 2, 3};
  Solution         solution;
  auto             res = solution.perm(vec);
  for (auto vc : res) {
    for (auto i : vc) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
}