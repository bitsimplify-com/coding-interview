import sys
def dfs(g, i, j):
    if (i >= 0 and j >= 0 and i < len(g) and j < len(g) and g[i][j] == 0):
        g[i][j] = 1
        dfs(g, i - 1, j)
        dfs(g, i + 1, j)
        dfs(g, i, j - 1)
        dfs(g, i, j + 1)

def regionsBySlashes(grid, regions = 0):
    g = [[0 for j in range(len(grid) * 3)] for i in range(len(grid) * 3)]
    for i in range(0, len(grid)):
        for j in range(0, len(grid)):
            if grid[i][j] == '/':
                g[i * 3][j * 3 + 2] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3] = 1
            if grid[i][j] == '\\':
                g[i * 3][j * 3] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3 + 2] = 1
    for i in range(0, len(g)):
        for j in range(0, len(g)):
            if (g[i][j] == 0):
                dfs(g, i, j)
                regions += 1
    return regions

grid = []
num_inputs=0
started = False

for line in sys.stdin:
    if num_inputs==0 and started == False:
        num_inputs = int(line)
        started = True
        continue

    grid.append(line)

print(regionsBySlashes(grid))
