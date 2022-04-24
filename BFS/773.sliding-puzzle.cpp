/*
 * @lc app=leetcode id=773 lang=cpp
 *
 * [773] Sliding Puzzle
 *
 * https://leetcode.com/problems/sliding-puzzle/description/
 *
 * algorithms
 * Hard (62.47%)
 * Likes:    1249
 * Dislikes: 34
 * Total Accepted:    63.3K
 * Total Submissions: 101.2K
 * Testcase Example:  '[[1,2,3],[4,0,5]]'
 *
 * On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty
 * square represented by 0. A move consists of choosing 0 and a 4-directionally
 * adjacent number and swapping it.
 *
 * The state of the board is solved if and only if the board is
 * [[1,2,3],[4,5,0]].
 *
 * Given the puzzle board board, return the least number of moves required so
 * that the state of the board is solved. If it is impossible for the state of
 * the board to be solved, return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: board = [[1,2,3],[4,0,5]]
 * Output: 1
 * Explanation: Swap the 0 and the 5 in one move.
 *
 *
 * Example 2:
 *
 *
 * Input: board = [[1,2,3],[5,4,0]]
 * Output: -1
 * Explanation: No number of moves will make the board solved.
 *
 *
 * Example 3:
 *
 *
 * Input: board = [[4,1,2],[5,0,3]]
 * Output: 5
 * Explanation: 5 is the smallest number of moves that solves the board.
 * An example path:
 * After move 0: [[4,1,2],[5,0,3]]
 * After move 1: [[4,1,2],[0,5,3]]
 * After move 2: [[0,1,2],[4,5,3]]
 * After move 3: [[1,0,2],[4,5,3]]
 * After move 4: [[1,2,0],[4,5,3]]
 * After move 5: [[1,2,3],[4,5,0]]
 *
 *
 * Example 4:
 *
 *
 * Input: board = [[3,2,4],[1,5,0]]
 * Output: 14
 *
 *
 *
 * Constraints:
 *
 *
 * board.length == 2
 * board[i].length == 3
 * 0 <= board[i][j] <= 5
 * Each value board[i][j] is unique.
 *
 *
 */

#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

// @lc code=start
class Solution {
public:
  int slidingPuzzle(std::vector<std::vector<int>>& board) {
    int         row = 2, col = 3;
    std::string start = "", target = "123450";
    // 将2*3矩阵转换为字符串
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        start.push_back(board[i][j] + '0');
      }
    }

    // 记录一维数组与二维数组的映射
    std::vector<std::vector<int>> neighbor =
        {{1, 3}, {0, 4, 2}, {1, 5}, {0, 4}, {3, 1, 5}, {4, 2}};

    // BFS框架
    std::queue<std::string>         que;
    std::unordered_set<std::string> visited;
    que.push(start);
    visited.insert(start);

    int step = 0;
    while (!que.empty()) {
      int sz = que.size();

      for (int i = 0; i < sz; i++) {  // 保证处理完成一批可能的转换后替换
        std::string cur = que.front();
        que.pop();

        if (cur == target) {
          // 是否达到目标
          return step;
        }

        int idx = 0;  // 查找数字0所在位置
        for (; cur[idx] != '0'; idx++)
          ;

        // 将0和相邻数字交换
        for (int adj : neighbor[idx]) {
          std::string new_string = cur;
          std::swap(new_string[adj], new_string[idx]);

          // 防止重复
          if (!visited.count(new_string)) {
            que.push(new_string);
            visited.insert(new_string);
          }
        }
      }
      step++;
    }

    return -1;
  }
};
// @lc code=end
