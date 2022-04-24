#include <iostream>
#include <vector>

void printVec(std::vector<std::vector<int>> &matrix) {
  for (auto it : matrix) {
    for (auto i : it) {
      std::cout << i << ' ';
    }
    std::cout << std::endl;
  }
}

std::vector<std::vector<int>> matrixT(std::vector<std::vector<int>> &vec) {
  int                           row = vec.size(), col = vec[0].size();
  std::vector<std::vector<int>> matrix(col, std::vector<int>(row));

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      matrix[j][i] = vec[i][j];
    }
  }

  return matrix;
}

int main(int argc, char **argv) {
  std::vector<std::vector<int>> vec = {{1, 2, 3, 4}, {5, 6, 7, 8}};
  printVec(vec);

  auto m = matrixT(vec);
  printVec(m);

  return 0;
}
