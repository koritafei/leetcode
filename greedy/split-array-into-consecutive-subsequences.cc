#include <unordered_map>
#include <vector>

class Solution {
public:
  bool isPossible(std::vector<int>& nums) {
    std::unordered_map<int, int> freq;  // 频率统计
    std::unordered_map<int, std::vector<std::vector<int>>> need;  // 需求列表

    for (auto item : nums) {
      freq[item]++;
    }

    for (auto item : nums) {
      if (0 == freq[item]) {
        continue;
      }
      // 首先判断是否可以连接到某个队列之后
      if (need.count(item) && need[item].size() > 0) {
        // 随机选择一个队列加入
        freq[item]--;
        std::vector<int> tmp = need[item].back();
        need[item].pop_back();
        tmp.push_back(item);
        need[item + 1].push_back(tmp);
      } else if (freq[item] > 0 && freq[item + 1] > 0 && freq[item + 2] > 0) {
        freq[item]--;
        freq[item + 1]--;
        freq[item + 2]--;
        std::vector<int> tmp{item, item + 1, item + 2};
        need[item + 3].push_back(tmp);
      } else {
        return false;  // 不可构成子序列
      }
    }

    std::vector<std::vector<int>> res;
    for (auto it : need) {
      for (auto i : it.second) {
        res.push_back(i);
      }
    }

    return true;
  }
};
