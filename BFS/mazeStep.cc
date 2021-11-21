#include <climits>
#include <list>
#include <vector>

// 解法一，每次遍历一层，确定前进的一步
class Solution {
public:
  int MazeStep(std::vector<std::vector<char>> &maze,
               int                             sx,
               int                             sy,
               int                             ex,
               int                             ey) {
    int row = maze.size(), col = 0;
    if (0 == row) {
      return 0;
    } else {
      col = maze[0].size();
    }

    visited = std::vector<std::vector<bool>>(row + 1,
                                             std::vector<bool>(col + 1, false));

    std::list<std::pair<int, int>> que;

    int step = 0;
    que.push_back(std::make_pair(sx, sy));
    visited[sx][sy] = true;

    while (que.size()) {
      int sz = que.size();
      for (int i = 0; i < sz; i++) {
        std::pair<int, int> front = que.front();
        que.pop_front();
        if (front.first == ex && front.second == ey) {
          return step;
        }

        for (auto item : dir) {
          int dx = item[0] + front.first;
          int dy = item[1] + front.second;

          if (isInArea(row, col, dx, dy) && !visited[dx][dy] &&
              '#' != maze[dx][dy]) {
            que.push_back(std::make_pair(dx, dy));
            visited[dx][dy] = true;
          }
        }
      }

      step++;
    }

    return -1;  // 不可达
  }

private:
  bool isInArea(int row, int col, int x, int y) {
    return x >= 0 && x < row && y >= 0 && y < col;
  }

  std::vector<std::vector<int>>  dir = {{-1, 0}, {0, 1}, {1, 0}, {-1, 0}};
  std::vector<std::vector<bool>> visited;
};

// 解法二
class MazeStep {
public:
  int mazestep(std::vector<std::vector<char>> &maze,
               int                             sx,
               int                             sy,
               int                             ex,
               int                             ey) {
    int row = maze.size(), col = 0;
    if (0 == row) {
      return 0;
    }
    col = maze[0].size();

    // 构造前进数组
    std::vector<std::vector<int>> step =
        std::vector<std::vector<int>>(row + 1,
                                      std::vector<int>(col + 1, INT_MAX));
    std::list<std::pair<int, int>> que;
    que.push_back(std::make_pair(sx, sy));
    step[sx][sy] = 0;

    while (que.size()) {
      std::pair<int, int> front = que.front();
      que.pop_front();

      if (front.first == ex && front.second == sy) {
        break;
      }

      for (auto item : dir) {
        int dx = front.first + item[0];
        int dy = front.second + item[1];

        if (isInArea(row, col, dx, dy) && '#' != maze[dx][dy] &&
            INT_MAX == step[dx][dy]) {
          que.push_back(std::make_pair(dx, dy));
          step[dx][dy] = step[front.first][front.second] + 1;
        }
      }
    }

    return step[ex][ey];
  }

private:
  bool isInArea(int row, int col, int x, int y) {
    return x >= 0 && x < row && y >= 0 && y < col;
  }

  std::vector<std::vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {-1, 0}};
};