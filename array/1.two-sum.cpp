/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> m;  // num<->index
    vector<int>   res;
    int           len = nums.size();
    for (int i = 0; i < len; i++) {
      int num = target - nums[i];
      if (m.count(num)) {
        res.push_back(m[num]);
        res.push_back(i);
        return res;
      }
      m[nums[i]] = i;
    }

    return res;
  }
};

// @lc code=end

int main(int argc, char* argv[]) {
  vector<int> nums   = {2, 7, 11, 15};
  int         target = 9;
  Solution    solution;
  vector<int> res = solution.twoSum(nums, target);
  for (auto item : res) {
    cout << item << " ";
  }
  cout << endl;
}