#include "print.h"

void InsertSort(std::vector<int> &nums) {
  for (int i = 0; i < nums.size(); i++) {
    for (int j = i; j >= 0; j--) {
      if (j - 1 >= 0 && nums[j] < nums[j - 1]) {
        std::swap(nums[j], nums[j - 1]);
      }
    }
  }
}

int main() {
  std::vector<int> nums = {1, 9, 6, 4, 2};
  print(nums);
  InsertSort(nums);
  print(nums);
}