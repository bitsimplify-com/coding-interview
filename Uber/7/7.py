def pancakeSort(A):
    res = []
    for x in range(len(A), 1, -1):
        i = A.index(x)
        res.extend([i + 1, x])
        A = A[:i:-1] + A[:i]
    return res

n = int(input())
A = list(map(int, input().split()))
ans = pancakeSort(A)
print(ans)
