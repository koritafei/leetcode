#include <iostream>
#include <string>

class Solution {
public:
  std::string BestCowLine(std::string &s) {
    int         len = s.size();
    std::string res;
    int         left = 0, right = len - 1;
    while (left <= right) {
      bool flag = false;
      if (s[left] < s[right]) {
        flag = true;  // 每次选取最小的一端加入
      } else if (s[left] > s[right]) {
        flag = false;
      } else {
        for (int i = 0; left + i < right; i++) {
          if (s[left + i] < s[right - i]) {
            flag = true;
            break;
          } else if (s[right - i] < s[left + i]) {
            flag = false;
            break;
          }
        }
      }

      if (flag) {
        res.push_back(s[left++]);
      } else {
        res.push_back(s[right--]);
      }
    }

    return res;
  }
};

int main() {
  std::string s = "ACDBCB";
  Solution    sol;
  std::cout << sol.BestCowLine(s) << std::endl;
}
