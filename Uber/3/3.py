def peakTime(start, end):
	n = len(start)
	if(n == 0):
		return -1
	lastExitTime = 0
	for i in range(0, n):
		lastExitTime = max(lastExitTime, start[i])
		lastExitTime = max(lastExitTime, end[i])
	vehicleCount = (lastExitTime + 2) * [0]
	current = 0
	index = 0
	for i in range(0, n):
		vehicleCount[start[i]] += 1
		vehicleCount[end[i] + 1] -= 1
	maxVehicleCount = -1
	for i in range(0, lastExitTime + 1):
		current += vehicleCount[i]
		if(maxVehicleCount < current):
			maxVehicleCount = current
			index = i
	return maxVehicleCount

a = int(input())
start = end = []
for x in range(a):
	startTime, endTime = map(int, input().split())
	start.append(startTime)
	end.append(endTime)

time = peakTime(start, end)
print(time)
