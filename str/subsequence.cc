
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

bool isSubsequence(std::string s, std::string t) {
  int m = s.size(), n = t.size();

  std::unordered_map<int, std::vector<int>> map;
  for (int i = 0; i < n; i++) {
    map[t[i]].push_back(i);
  }

  int j = 0;  // t索引位置
  for (int i = 0; i < m; i++) {
    char c = s[i];
    // 字符c不存在
    if (map.count(c) == 0) {
      return false;
    }

    std::vector<int>::iterator pos =
        std::lower_bound(map[c].begin(), map[c].end(), j);
    if (pos == map[c].end()) {
      return false;
    }

    j = *pos;
  }

  return true;
}
