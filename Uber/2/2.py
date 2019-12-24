def dfs(matrix, dp, x, y):
    if (dp[x][y]):
        return dp[x][y]
    dirs = [[-1, 0], [1, 0], [0, 1], [0, -1]]
    rows = len(matrix)
    cols = len(matrix[0])
    for dir in dirs:
	    xx = x + dir[0]
	    yy = y + dir[1]
	    if (xx < 0 or xx >= rows or yy < 0 or yy >= cols):
	    	continue
	    if (matrix[xx][yy] <= matrix[x][y]):
	    	continue
	    dp[x][y] = max(dp[x][y], dfs(matrix, dp, xx, yy))
    dp[x][y] += 1
    return dp[x][y]

def longestIncreasingPath(matrix):
    rows = len(matrix)
    cols = len(matrix[0])
    dp = [[0 for j in range(rows)] for i in range(cols)]
    ret = 0
    for i in range(0, rows):
        for j in range (0, cols):
            ret = max(ret, dfs(matrix, dp, i, j))
    return ret

m, n = map(int, input().split())
matrix = []
for x in range(0, m):
    matrix.append(list(map(int, input().split())))

print(longestIncreasingPath(matrix))
