#include <iostream>
#include <string>
#include <vector>

void dfs(std::vector<std::vector<int> > &g, int i, int j) {
  if (i >= 0 && j >= 0 && i < g.size() && j < g.size() && g[i][j] == 0) {
    g[i][j] = 1;
    dfs(g, i - 1, j), dfs(g, i + 1, j), dfs(g, i, j - 1), dfs(g, i, j + 1);
  }
}
int regionsBySlashes(std::vector<std::string> &grid, int regions = 0) {
  std::vector<std::vector<int> > g(grid.size() * 3,
                                  std::vector<int>(grid.size() * 3, 0));
  for (int i = 0; i < grid.size(); ++i)
    for (int j = 0; j < grid.size(); ++j) {
      if (grid[i][j] == '/')
        g[i * 3][j * 3 + 2] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3] = 1;
      if (grid[i][j] == '\\')
        g[i * 3][j * 3] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3 + 2] = 1;
    }
  for (int i = 0; i < g.size(); ++i)
    for (int j = 0; j < g.size(); ++j)
      if (g[i][j] == 0)
        dfs(g, i, j), ++regions;
  return regions;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::string> grid(n);
  for (int i = 0; i < n; i++) {
    std::cin >> grid[i];
  }
  std::cout << regionsBySlashes(grid) << "\n";
  return 0;
}
