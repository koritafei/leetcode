#include <set>
#include <string>
#include <vector>

class Solution {
public:
  int numDistinctIslands(std::vector<std::vector<char>>& grid) {
    int row = grid.size(), col = 0;
    if (0 == row) {
      return 0;
    } else {
      col = grid[0].size();
    }

    std::set<std::string> set;

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if ('1' == grid[i][j]) {
          std::string res;
          dfs(grid, row, col, i, j, res);
          set.insert(res);
        }
      }
    }

    return set.size();
  }

private:
  std::vector<std::vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  bool isInArea(int row, int col, int x, int y) {
    return x >= 0 && x < row && y >= 0 && y < col;
  }

  void dfs(std::vector<std::vector<char>>& grid,
           int                             row,
           int                             col,
           int                             x,
           int                             y,
           std::string&                    track) {
    grid[x][y] = '0';
    track.push_back(0 + '0');
    for (int i = 0; i < 4; i++) {
      int dx = x + dir[i][0];
      int dy = y + dir[i][1];
      if (isInArea(row, col, dx, dy) && 1 == grid[dx][dy]) {
        track.push_back(i + 1 + '0');
        dfs(grid, row, col, dx, dy, track);
        track.append(std::to_string(-(i + 1)));
      }
    }
  }
};