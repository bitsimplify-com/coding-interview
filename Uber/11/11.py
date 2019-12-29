def pr_N_mostFrequentNumber(arr, n, k):
	um = {}
	for i in range(n):
		if arr[i] in um:
			um[arr[i]] += 1
		else:
			um[arr[i]] = 1
		a = [0] * (len(um))
	j = 0
	for i in um:
		a[j] = [i, um[i]]
		j += 1
	a = sorted(a, key = lambda x : x[0], reverse = True)
	a = sorted(a, key = lambda x : x[1], reverse = True)
	for i in range(k):
		print(a[i][0])

n = int(input())
arr = list(map(int, input().split()))
k = int(input())
pr_N_mostFrequentNumber(arr, n, k)
