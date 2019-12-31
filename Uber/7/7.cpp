#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> pancakeSort(std::vector<int> A) {
  std::vector<int> res;
  int x, i;
  for (x = A.size(); x > 0; --x) {
    for (i = 0; A[i] != x; ++i)
      ;
    std::reverse(A.begin(), A.begin() + i + 1);
    res.push_back(i + 1);
    std::reverse(A.begin(), A.begin() + x);
    res.push_back(x);
  }
  return res;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> A(n);
  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
  }
  std::vector<int> ans = pancakeSort(A);
  for (int x : ans) {
    std::cout << x << " ";
  }
  std::cout << "\n";
  return 0;
}
