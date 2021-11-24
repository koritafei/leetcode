#include <iostream>
#include <vector>

void selectSort(std::vector<int> &nums) {
  int i = 0;
  for (int i = 0; i < nums.size(); i++) {
    int minIndex = i;
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[j] < nums[minIndex]) {
        minIndex = j;
      }
    }
    std::swap(nums[minIndex], nums[i]);
  }
}

void print(std::vector<int> &nums) {
  for (auto item : nums) {
    std::cout << item << ' ';
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> nums = {1, 9, 6, 4, 2};
  print(nums);
  selectSort(nums);
  print(nums);
}
