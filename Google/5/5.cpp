#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  std::vector<int> a;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    a.push_back(k);
  }
  int key;
  cin >> key;
  cout << upper_bound(a.begin(), a.end(), key) -
              lower_bound(a.begin(), a.end(), key)
       << endl;
}
