/*
 * @lc app=leetcode id=514 lang=cpp
 *
 * [514] Freedom Trail
 *
 * https://leetcode.com/problems/freedom-trail/description/
 *
 * algorithms
 * Hard (45.60%)
 * Likes:    617
 * Dislikes: 31
 * Total Accepted:    25K
 * Total Submissions: 54.9K
 * Testcase Example:  '"godding"\n"gd"'
 *
 * In the video game Fallout 4, the quest "Road to Freedom" requires players to
 * reach a metal dial called the "Freedom Trail Ring" and use the dial to spell
 * a specific keyword to open the door.
 *
 * Given a string ring that represents the code engraved on the outer ring and
 * another string key that represents the keyword that needs to be spelled,
 * return the minimum number of steps to spell all the characters in the
 * keyword.
 *
 * Initially, the first character of the ring is aligned at the "12:00"
 * direction. You should spell all the characters in key one by one by rotating
 * ring clockwise or anticlockwise to make each character of the string key
 * aligned at the "12:00" direction and then by pressing the center button.
 *
 * At the stage of rotating the ring to spell the key character key[i]:
 *
 *
 * You can rotate the ring clockwise or anticlockwise by one place, which
 * counts as one step. The final purpose of the rotation is to align one of
 * ring's characters at the "12:00" direction, where this character must equal
 * key[i].
 * If the character key[i] has been aligned at the "12:00" direction, press the
 * center button to spell, which also counts as one step. After the pressing,
 * you could begin to spell the next character in the key (next stage).
 * Otherwise, you have finished all the spelling.
 *
 *
 *
 * Example 1:
 *
 *
 * Input: ring = "godding", key = "gd"
 * Output: 4
 * Explanation:
 * For the first key character 'g', since it is already in place, we just need
 * 1 step to spell this character.
 * For the second key character 'd', we need to rotate the ring "godding"
 * anticlockwise by two steps to make it become "ddinggo".
 * Also, we need 1 more step for spelling.
 * So the final output is 4.
 *
 *
 * Example 2:
 *
 *
 * Input: ring = "godding", key = "godding"
 * Output: 13
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= ring.length, key.length <= 100
 * ring and key consist of only lower case English letters.
 * It is guaranteed that key could always be spelled by rotating ring.
 *
 *
 */

#include <climits>
#include <cmath>
#include <string>
#include <unordered_map>
#include <vector>

// @lc code=start
class Solution {
public:
  int findRotateSteps(std::string ring, std::string key) {
    int m = ring.size();
    int n = key.size();
    // 备忘录初始化为0
    memo.resize(m + 1, std::vector<int>(n + 1, 0));

    //记录圆环上字符索引位置
    for (int i = 0; i < m; i++) {
      charToIndex[ring[i]].push_back(i);
    }

    // 圆盘最初指向12点钟方向，从0开始
    return dp(ring, 0, key, 0);
  }

private:
  int dp(std::string s, int indexs, std::string key, int indexk) {
    if (indexk == key.size()) {
      return 0;
    }

    if (memo[indexs][indexk] != 0) {
      return memo[indexs][indexk];
    }

    int n = s.size();
    // 做选择
    int res = INT_MAX;

    for (auto k : charToIndex[key[indexk]]) {
      // 转动指针次数
      int delta = abs(k - indexs);
      // 选择顺时针或逆时针
      delta = std::min(delta, n - delta);
      // 子问题求解
      int subProblem = dp(s, k, key, indexk + 1);

      // 整体求解
      res = std::min(res, 1 + delta + subProblem);
    }

    // 结果加入备忘录
    memo[indexs][indexk] = res;

    return res;
  }

  std::unordered_map<char, std::vector<int>> charToIndex;
  std::vector<std::vector<int>>              memo;
};
// @lc code=end
