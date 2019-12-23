#include<iostream>
#include<vector>
#include<string>

bool isPalindrome(std::string& s, int l, int r) {
	while (l < r) {
		if (s[l++] != s[r--]) {
			return false;
		}
	}
	return true;
}

void partition(std::string& s, int start, std::vector<std::string>& par,
	       std::vector<std::vector<std::string>>& pars) {
	int n = s.length();
	if (start == n) {
		pars.push_back(par);
	} else {
		for (int i = start; i < n; i++) {
			if (isPalindrome(s, start, i)) {
				par.push_back(s.substr(start, i - start + 1));
				partition(s, i + 1, par, pars);
				par.pop_back();
			}
		}
	}
}

std::vector<std::vector<std::string>> run(std::string s) {
	std::vector<std::vector<std::string>> pars;
	std::vector<std::string> par;
	partition(s, 0, par, pars);
	return pars;
}

int main(){
	std::string s;
	std::cin >> s;
	std::vector<std::vector<std::string>> ans = run(s);
	for(std::vector<std::string> vec : ans){
		for(std::string s : vec){
			std::cout << s << " ";
		}
		std::cout << "\n";
	}
	return 0;
}
