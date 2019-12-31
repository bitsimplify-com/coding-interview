#include <climits>
#include <iostream>
#include <vector>

int isPointWithinGrid(std::vector<std::vector<int>> Grid, int row, int col,
                      std::vector<std::vector<bool>> visited, int RowSize,
                      int ColSize) {
  return (row >= 0) && (row < RowSize) && (col >= 0) && (col < ColSize) &&
         (Grid[row][col] && !visited[row][col]);
}
void DepthFirstSearch(std::vector<std::vector<int>> Grid, int row, int col,
                      std::vector<std::vector<bool>> visited, int &count,
                      int RowSize, int ColSize) {
  static int rowDir[] = {0, 0, 1, -1};
  static int colDir[] = {1, -1, 0, 0};
  visited[row][col] = true;
  for (int k = 0; k < 4; ++k) {
    if (isPointWithinGrid(Grid, row + rowDir[k], col + colDir[k], visited,
                          RowSize, ColSize)) {
      count++;
      DepthFirstSearch(Grid, row + rowDir[k], col + colDir[k], visited, count,
                       RowSize, ColSize);
    }
  }
}
int maxNumberOfConnectedOne(std::vector<std::vector<int>> Grid) {
  int RowSize = Grid.size();
  if (Grid.size() == 0) {
    return 0;
  }
  int ColSize = Grid[0].size();
  std::vector<std::vector<bool>> visited(RowSize,
                                         std::vector<bool>(ColSize, false));
  int result = INT_MIN;
  for (int i = 0; i < RowSize; ++i) {
    for (int j = 0; j < ColSize; ++j) {
      if (Grid[i][j] && !visited[i][j]) {
        int count = 1;
        DepthFirstSearch(Grid, i, j, visited, count, RowSize, ColSize);
        result = std::max(result, count);
      }
    }
  }
  return result;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> row(n);
  std::vector<std::vector<int>> grid(n, row);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> grid[i][j];
    }
  }
  std::cout << maxNumberOfConnectedOne(grid) << "\n";
  return 0;
}
