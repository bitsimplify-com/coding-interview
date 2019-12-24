#include<iostream>
#include<vector>
#include<algorithm>

std::vector<std::pair<int, int>> merge(std::vector<std::pair<int, int>>& ins) {
	if (ins.empty()) return std::vector<std::pair<int, int>>{};
	std::vector<std::pair<int, int>> res;
	sort(ins.begin(), ins.end(),
	     [](std::pair<int, int> a, std::pair<int, int> b) { return a.first < b.first; });
	res.push_back(ins[0]);
	for (int i = 1; i < ins.size(); i++) {
		if (res.back().second < ins[i].first)
			res.push_back(ins[i]);
		else
			res.back().second =
			    std::max(res.back().second, ins[i].second);
	}
	return res;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> intervals;
	while (n--) {
		int start, end;
		std::cin >> start >> end;
		intervals.push_back({start, end});
	}
	std::vector<std::pair<int, int>> answer = merge(intervals);
	for (std::pair<int, int> x : answer) {
		std::cout << x.first << " " << x.second << "\n";
	}
}
