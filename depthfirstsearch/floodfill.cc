#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> floodfill(std::vector<std::vector<int>> &board,
                                          int                            sr,
                                          int                            sc,
                                          int newColor) {
    int oldColor = board[sr][sc];
    int row      = board.size();
    int col      = 0;

    if (row > 0) {
      col = board[0].size();
    }

    fillImage(board, row, col, sr, sc, oldColor, newColor);

    return board;
  }

private:
  void fillImage(std::vector<std::vector<int>> &board,
                 int                            row,
                 int                            col,
                 int                            sr,
                 int                            sc,
                 int                            oldColor,
                 int                            newColor) {
    // 越界
    if (!isInArea(sr, sc, row, col)) {
      return;
    }

    // 当前值不为oldColor
    if (oldColor != board[sr][sc]) {
      return;
    }
    board[sr][sc] = -1;
    fillImage(board, row, col, sr - 1, sc, oldColor, newColor);
    fillImage(board, row, col, sr + 1, sc, oldColor, newColor);
    fillImage(board, row, col, sr, sc - 1, oldColor, newColor);
    fillImage(board, row, col, sr, sc + 1, oldColor, newColor);

    board[sr][sc] = newColor;
  }

  bool isInArea(int sr, int sc, int row, int col) {
    return sr >= 0 && sr < row && sc >= 0 && sc < col;
  }
};