#include<iostream>
#include<vector>

int dfs(std::vector<std::vector<int>> matrix, std::vector<std::vector<int>> dp, int x, int y) {
	if (dp[x][y]) return dp[x][y];
	int cols = matrix.size();
	int rows = matrix[0].size();
	std::vector<std::vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
	for (auto& dir : dirs) {
		int xx = x + dir[0], yy = y + dir[1];
		if (xx < 0 || xx >= rows || yy < 0 || yy >= cols) continue;
		if (matrix[xx][yy] <= matrix[x][y]) continue;
		dp[x][y] = std::max(dp[x][y], dfs(matrix, dp, xx, yy));
	}
	return ++dp[x][y];
};
int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
	int rows = matrix.size();
	if (!rows) return 0;
	int cols = matrix[0].size();
	std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));
	int ret = 0;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			ret = std::max(ret, dfs(matrix, dp, i, j));
		}
	}
	return ret;
}

int main(){
	int m, n;
	std::cin >> m >> n;
	std::vector<int> row(n);
	std::vector<std::vector<int>> grid(m, row);
	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			std::cin >> grid[i][j];
		}
	}
	std::cout << longestIncreasingPath(grid) << "\n";
	return 0;
}
