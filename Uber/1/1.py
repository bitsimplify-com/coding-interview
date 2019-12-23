def isPointWithinGrid(Grid, row, col, visited, RowSize, ColSize):
    return ((row >= 0) and (row < RowSize) and (col >= 0) and (col < ColSize) and (Grid[row][col] and not visited[row][col]))

def DepthFirstSearch(Grid, row, col, visited, count, RowSize, ColSize):
    rowDir = [0, 0, -1, 1]
    colDir = [-1, 1, 0, 0]
    visited[row][col] = True
    for k in range(4):
        if (isPointWithinGrid(Grid, row + rowDir[k], col + colDir[k], visited, RowSize, ColSize)):
            count[0] += 1
            DepthFirstSearch(Grid, row + rowDir[k], col + colDir[k], visited, count, RowSize, ColSize)

def maxNumberOfConnectedOne(Grid):
    RowSize = len(Grid)
    if(RowSize == 0):
        return 0
    ColSize = len(Grid[0])
    visited = [[0] * ColSize for i in range(RowSize)]
    result = -1
    for i in range(RowSize):
        for j in range(ColSize):
            if (Grid[i][j] and not visited[i][j]):
                count = [1]
                DepthFirstSearch(Grid, i, j, visited , count, RowSize, ColSize)
                result = max(result , count[0])
    return result

n = int(input())
Grid = []
for x in range(n):
    Grid.append(list(map(int, input().split())));
print(maxNumberOfConnectedOne(Grid))
