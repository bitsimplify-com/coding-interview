def merge(intervals):
	out = []
	for i in sorted(intervals, key=lambda i: i[0]):
		if out and i[0] <= out[-1][-1]:
			out[-1][-1] = max(out[-1][-1], i[-1])
		else:
	                out += i,
	return out

n = int(input())
intervals = []
for x in range(n):
	pair = list(map(int, input().split()))
	intervals.append(pair)
answer = merge(intervals)
for x in answer:
	print(x[0], x[-1])
