#include<iostream>
#include<vector>

int peakTime(std::vector<int> start, std::vector<int> end) {
	if (start.size() == 0) {
		return -1;
	}
	int lastExitTime = 0;
	for (int i = 0; i < start.size(); i++) {
		lastExitTime = std::max(lastExitTime, start[i]);
		lastExitTime = std::max(lastExitTime, end[i]);
	}
	int vehicleCount[lastExitTime + 2] = {0};
	int current = 0;
	int index = 0;
	for (int i = 0; i < start.size(); i++) {
		vehicleCount[start[i]] += 1;
		vehicleCount[end[i] + 1] -= 1;
	}
	int maxVehicleCount = -1;
	for (int i = 0; i <= lastExitTime; i++) {
		current += vehicleCount[i];
		if (maxVehicleCount < current) {
			maxVehicleCount = current;
			index = i;
		}
	}
	return maxVehicleCount;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<int> start, end;
	while (n--) {
		int startTime, endTime;
		std::cin >>  startTime >> endTime;
		start.push_back(startTime);
		end.push_back(endTime);
	}
	std::cout << peakTime(start, end) << "\n";
	return 0;
}
