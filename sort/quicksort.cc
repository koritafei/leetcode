#include <vector>

int partation(std::vector<int> &nums, int left, int right) {
  if (left == right) {
    return left;
  }

  int key = nums[left];           // 将起始位置作为需要比较的key
  int lo = left, hi = right + 1;  // 先--在处理
  while (true) {
    // 保证nums[left ... lo]都小于key
    while (nums[++lo] < key) {
      if (lo == right) {
        break;
      }
    }

    // 保证nums[hi...right]都大于key
    while (nums[--hi] > key) {
      if (hi == left) {
        break;
      }
    }

    if (lo >= hi) {
      break;
    }

    // 此处一定存在nums[lo] > key, nums[hi] < key
    // 交换两个元素即可
    std::swap(nums[lo], nums[hi]);
  }

  std::swap(key, nums[hi]);  // 将key放知道正确位置
  return hi;
}

void quicksort(std::vector<int> &nums, int left, int right) {
  if (left >= right) {
    return;
  }
  int index = partation(nums, left, right);

  quicksort(nums, left, index - 1);
  quicksort(nums, index + 1, right);
}
