/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 *
 * https://leetcode.com/problems/open-the-lock/description/
 *
 * algorithms
 * Medium (55.06%)
 * Likes:    2407
 * Dislikes: 82
 * Total Accepted:    139.2K
 * Total Submissions: 252.6K
 * Testcase Example:  '["0201","0101","0102","1212","2002"]\n"0202"'
 *
 * You have a lock in front of you with 4 circular wheels. Each wheel has 10
 * slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can
 * rotate freely and wrap around: for example we can turn '9' to be '0', or '0'
 * to be '9'. Each move consists of turning one wheel one slot.
 *
 * The lock initially starts at '0000', a string representing the state of the
 * 4 wheels.
 *
 * You are given a list of deadends dead ends, meaning if the lock displays any
 * of these codes, the wheels of the lock will stop turning and you will be
 * unable to open it.
 *
 * Given a target representing the value of the wheels that will unlock the
 * lock, return the minimum total number of turns required to open the lock, or
 * -1 if it is impossible.
 *
 *
 * Example 1:
 *
 *
 * Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
 * Output: 6
 * Explanation:
 * A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" ->
 * "1201" -> "1202" -> "0202".
 * Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202"
 * would be invalid,
 * because the wheels of the lock become stuck after the display becomes the
 * dead end "0102".
 *
 *
 * Example 2:
 *
 *
 * Input: deadends = ["8888"], target = "0009"
 * Output: 1
 * Explanation:
 * We can turn the last wheel in reverse to move from "0000" -> "0009".
 *
 *
 * Example 3:
 *
 *
 * Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"],
 * target = "8888"
 * Output: -1
 * Explanation:
 * We can't reach the target without getting stuck.
 *
 *
 * Example 4:
 *
 *
 * Input: deadends = ["0000"], target = "8888"
 * Output: -1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= deadends.length <= 500
 * deadends[i].length == 4
 * target.length == 4
 * target will not be in the list deadends.
 * target and deadends[i] consist of digits only.
 *
 *
 */

#include <list>
#include <map>
#include <string>
#include <unordered_set>
#include <vector>

// @lc code=start
class Solution {
public:
  int openLock(std::vector<std::string> &deadends, std::string target) {
    std::unordered_set<std::string> dead(deadends.begin(), deadends.end());
    std::unordered_set<std::string> visited;  // 存储已遍历过的密码
    std::list<std::string>          que;      // 队列

    int res = 0;
    que.push_back("0000");
    visited.insert("0000");

    while (que.size()) {
      int sz = que.size();

      for (int i = 0; i < sz; i++) {
        std::string cur = que.front();
        que.pop_front();

        if (dead.find(cur) != dead.end()) {
          continue;
        }

        if (cur == target) {
          return res;
        }

        for (int i = 0; i < 4; i++) {
          std::string up = plusOne(cur, i);
          if (visited.find(up) == visited.end()) {
            visited.insert(up);
            que.push_back(up);
          }

          std::string down = minusOne(cur, i);
          if (visited.find(down) == visited.end()) {
            visited.insert(down);
            que.push_back(down);
          }
        }
      }

      res++;
    }

    return -1;
  }

private:
  std::string plusOne(std::string str, int j) {
    if (str[j] == '9') {
      str[j] = '0';
    } else {
      str[j] += 1;
    }

    return str;
  }

  std::string minusOne(std::string str, int i) {
    if (str[i] == '0') {
      str[i] = '9';
    } else {
      str[i] -= 1;
    }

    return str;
  }
};
// @lc code=end
