/*
 * @lc app=leetcode id=43 lang=cpp
 * @lcpr version=30113
 *
 * [43] Multiply Strings
 */

// @lcpr-template-start
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// @lcpr-template-end
// @lc code=start
class Solution {
public:
  std::string multiply(std::string num1, std::string num2) {
    int              len1 = num1.size(), len2 = num2.size();
    int              len = len1 + len2;
    std::vector<int> res(len, 0);
    for (int i = len1 - 1; i >= 0; i--) {
      for (int j = len2 - 1; j >= 0; j--) {
        int p1 = i + j, p2 = i + j + 1;
        int multi = (num1[i] - '0') * (num2[j] - '0');
        int sum   = multi + res[p2];
        res[p2]   = sum % 10;
        res[p1] += sum / 10;
      }
    }

    std::string result;
    int         i = 0;
    while (i < len && res[i] == 0) {
      i++;
    }
    for (; i < len; i++) {
      result.push_back('0' + res[i]);
    }

    return result.size() == 0 ? "0" : result;
  }
};
// @lc code=end

/*
// @lcpr case=start
// "2"\n"3"\n
// @lcpr case=end

// @lcpr case=start
// "123"\n"456"\n
// @lcpr case=end

 */
