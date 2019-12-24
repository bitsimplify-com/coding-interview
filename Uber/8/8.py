:x

def dfs(s, path, res):
    if not s:
        res.append(path)
        for i in xrange(1, len(s)+1):
            if isPar(s[:i]):
                dfs(s[i:], path+[s[:i]], res)

def isPar(s):
    return s == s[::-1]

def partition(s):
    res = []
    dfs(s, [], res)
    return res


s = input()
answer = partition(s)
for ans in answer:
    print(ans)
