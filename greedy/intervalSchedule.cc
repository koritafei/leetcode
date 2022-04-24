#include <algorithm>
#include <vector>

int intervalSchedule(std::vector<std::vector<int>> intvs) {
  if (0 == intvs.size()) {
    return 0;
  }

  sort(intvs.begin(), intvs.end(), [](std::vector<int> a, std::vector<int> b) {
    return a[1] < b[1];
  });

  int count = 1;  // 必有一个区间不相交
  int x_end = intvs[0][1];
  for (auto item : intvs) {
    int startx = item[0];
    if (startx >= x_end) {
      count++;
      x_end = item[1];
    }
  }

  return count;
}
