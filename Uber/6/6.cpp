#include<iostream>
#include<vector>
#include<unordered_set>

std::vector<std::vector<int>> findNullTriplets(std::vector<int> list) {
	std::vector<std::vector<int>> ans;
	std::unordered_set<int> tempSet;
	for (int i = 0; i < list.size() - 1; i++) {
		for (int j = i + 1; j < list.size(); j++) {
			int x = -(list[i] + list[j]);
			if (tempSet.find(x) != tempSet.end()) {
				ans.push_back({x, list[i], list[j]});
			} else
				tempSet.insert(list[j]);
		}
	}
	return ans;
}

int main(){
	int n;
	std::cin >> n;
	std::vector<int> vec(n);
	for(int i = 0;i < n;i++){
		std::cin >> vec[i];
	}
	std::vector<std::vector<int>> answers = findNullTriplets(vec);
	for(std::vector<int> ans : answers){
		for(int x : ans){
			std::cout << x << " ";
		}
		std::cout << "\n";
	}
	return 0;
}
