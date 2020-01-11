n=int(input())
n = list(str(n))
if n == sorted(n, reverse = True):
    print("Not possible")
else:
    for i in range(len(n)-1, -1, -1):
        if(n[i-1] < n[i]):
            n[i:len(n)] = sorted(n[i:len(n)])
            break
    for j in range(i, len(n)):
        if(n[i-1] < n[j]):
            n[i-1], n[j] = n[j], n[i-1]
            break
    print(int("".join(n)))