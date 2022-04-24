#include <vector>

class Difference {
public:
  // 构造差分数组
  void diffSum(std::vector<int> nums) {
    int len = nums.size();
    diff[0] = nums[0];
    for (int i = 0; i < len; i++) {
      diff[i] = nums[i] - nums[i - 1];
    }
  }

  // 区间操作
  void increment(int i, int j, int val) {
    diff[i] += val;
    if (j + 1 < diff.size()) {
      diff[j + 1] -= val;
    }
  }

  // 还原数组
  std::vector<int> result() {
    int              len = diff.size();
    std::vector<int> res(len);
    res[0] = diff[0];
    for (int i = 1; i < len; i++) {
      res[i] = res[i - 1] + diff[i];
    }

    return res;
  }

private:
  std::vector<int> diff;  // 差分数组
};
