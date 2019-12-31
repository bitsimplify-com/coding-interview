#include <bits/stdc++.h>
using namespace std;

struct cmp {
  bool operator()(int A, int B) { return A > B; }
};

void kth_largest(int k, int num_iter) {
  priority_queue<int, vector<int>, cmp> H;
  int count = 0;
  int N;
  while (1) {
    cin >> N;
    if (H.size() < k)
      H.push(N);
    else {
      if (N > H.top()) {
        H.pop();
        H.push(N);
      }
    }
    count++;
    if (count == num_iter) {
      // Print the k-th largest element at the termination.
      cout << H.top() << endl;
      break;
    }
  }
}

int main() {
  int num_iter;
  std::cin >> num_iter;
  int nth;
  std::cin >> nth;
  kth_largest(nth, num_iter);
  return 0;
}
