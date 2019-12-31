#include <iostream>
#include <map>
#include <string>

std::pair<std::string, int> longest_k_substring(std::string s, int k) {
  int result = 0;
  std::string result_str;
  int i = 0;
  std::map<char, int> map;

  for (int j = 0; j < s.length(); j++) {
    char c = s[j];
    map[c] += 1;

    if (map.size() <= k) {
      if (result < j - i + 1) {
        result = j - i + 1;
        result_str = std::string(s.begin() + i, s.begin() + j + 1);
      }
    } else {
      while (map.size() > k) {
        // Prune from the left
        char l = s[i];
        int count = map[l];
        if (count == 1) {
          map.erase(l);
        } else {
          map[l] -= 1;
        }
        i++;
      }
    }
  }
  return {result_str, result};
}

int main() {
  std::string s;
  int p;
  int num_iter;
  std::cin >> num_iter;
  while (num_iter--) {
    std::cin >> s >> p;
    auto res = longest_k_substring(s, p);
    std::cout << res.first << ' ' << res.second << '\n';
  }
  return 0;
}
