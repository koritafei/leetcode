/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 *
 * https://leetcode.com/problems/dungeon-game/description/
 *
 * algorithms
 * Hard (35.73%)
 * Likes:    3552
 * Dislikes: 70
 * Total Accepted:    157.8K
 * Total Submissions: 440.9K
 * Testcase Example:  '[[-2,-3,3],[-5,-10,1],[10,30,-5]]'
 *
 * The demons had captured the princess and imprisoned her in the bottom-right
 * corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D
 * grid. Our valiant knight was initially positioned in the top-left room and
 * must fight his way through dungeon to rescue the princess.
 *
 * The knight has an initial health point represented by a positive integer. If
 * at any point his health point drops to 0 or below, he dies immediately.
 *
 * Some of the rooms are guarded by demons (represented by negative integers),
 * so the knight loses health upon entering these rooms; other rooms are either
 * empty (represented as 0) or contain magic orbs that increase the knight's
 * health (represented by positive integers).
 *
 * To reach the princess as quickly as possible, the knight decides to move
 * only rightward or downward in each step.
 *
 * Return the knight's minimum initial health so that he can rescue the
 * princess.
 *
 * Note that any room can contain threats or power-ups, even the first room the
 * knight enters and the bottom-right room where the princess is imprisoned.
 *
 *
 * Example 1:
 *
 *
 * Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
 * Output: 7
 * Explanation: The initial health of the knight must be at least 7 if he
 * follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN.
 *
 *
 * Example 2:
 *
 *
 * Input: dungeon = [[0]]
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * m == dungeon.length
 * n == dungeon[i].length
 * 1 <= m, n <= 200
 * -1000 <= dungeon[i][j] <= 1000
 *
 *
 */

#include <vector>

// @lc code=start
class Solution {
public:
  int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
    int row = dungeon.size(), col = dungeon[0].size();

    std::vector<std::vector<int>> dp(row + 1, std::vector<int>(col + 1, 0));

    // base case
    dp[row - 1][col - 1] =
        dungeon[row - 1][col - 1] >= 0 ? 1 : -dungeon[row - 1][col - 1] + 1;
    for (int i = col - 2; i >= 0; i--) {
      int tmp        = dp[row - 1][i + 1] - dungeon[row - 1][i];
      dp[row - 1][i] = tmp <= 0 ? 1 : tmp;
    }

    for (int i = row - 2; i >= 0; i--) {
      int tmp        = dp[i + 1][col - 1] - dungeon[i][col - 1];
      dp[i][col - 1] = tmp <= 0 ? 1 : tmp;
    }

    // 计算dp
    for (int i = row - 2; i >= 0; i--) {
      for (int j = col - 2; j >= 0; j--) {
        int tmp  = std::min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
        dp[i][j] = tmp <= 0 ? 1 : tmp;
      }
    }

    return dp[0][0];
  }
};
// @lc code=end
