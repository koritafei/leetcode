#include <vector>

class Solution {
public:
  int LakeCount(std::vector<std::vector<char>> &board) {
    int row = board.size(), col = 0;
    if (0 == row) {
      return 0;
    } else {
      col = board[0].size();
    }

    int res = 0;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if ('W' == board[i][j]) {
          res++;
          dfs(board, row, col, i, j);
        }
      }
    }
    return res;
  }

private:
  void dfs(std::vector<std::vector<char>> &board,
           int                             row,
           int                             col,
           int                             x,
           int                             y) {
    board[x][y] = '.';

    for (auto item : dir) {
      int dx = x + item[0];
      int dy = y + item[1];
      if (isInArea(row, col, dx, dy) && 'W' == board[dx][dy]) {
        dfs(board, row, col, dx, dy);
      }
    }
  }

  std::vector<std::vector<int>> dir =
      {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

  bool isInArea(int row, int col, int x, int y) {
    return x >= 0 && x < row && y >= 0 && y < col;
  }
};
