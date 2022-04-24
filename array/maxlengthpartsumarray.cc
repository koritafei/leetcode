#include <map>
#include <vector>

class Solution {
public:
  int maxLength(std::vector<int> &nums, int target) {
    int len = nums.size();
    if (len == 0) {
      return 0;
    }

    std::map<int, int> sumMap;
    int                res = INT_MIN;
    int                sum = 0;
    sumMap.insert(0, -1);

    for (int i = 0; i < len; i++) {
      sum += nums[i];

      if (sumMap.count(sum - target)) {
        res = std::max(res, i - sumMap[sum - target]);
      }

      if (!sumMap.count(sum)) {
        sumMap[sum] = i;
      }
    }

    return res;
  }
};
