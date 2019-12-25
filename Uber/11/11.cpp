#include<algorithm>
#include<iostream>
#include<unordered_map>
#include<vector>

bool compare(std::pair<int, int> p1, std::pair<int, int> p2) {
	if (p1.second == p2.second) return p1.first > p2.first;
	return p1.second > p2.second;
}

void print_N_mostFrequentNumber(int arr[], int n, int k) {
	std::unordered_map<int, int> um;
	for (int i = 0; i < n; i++) um[arr[i]]++;
	std::vector<std::pair<int, int> > freq_arr(um.begin(), um.end());
	sort(freq_arr.begin(), freq_arr.end(), compare);
	for (int i = 0; i < k; i++) std::cout << freq_arr[i].first << " ";
}

int main() {
	int n;
	std::cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	int k;
	std::cin >> k;
	print_N_mostFrequentNumber(arr, n, k);
	return 0;
}
