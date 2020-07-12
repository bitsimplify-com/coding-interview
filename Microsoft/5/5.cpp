#include <bits/stdc++.h>
using namespace std;
map<int, int> freqMap;
map<int, stack<int>> setMap;
int maxfreq = 0;
void push(int x) {
  int freq = freqMap[x] + 1;
  freqMap[x] = freq;
  if (freq > maxfreq)
    maxfreq = freq;
  setMap[freq].push(x);
}
int pop() {
  if (setMap[maxfreq].size() == 0) {
    return 0;
  }
  int top = setMap[maxfreq].top();
  setMap[maxfreq].pop();
  freqMap[top]--;
  if (setMap[maxfreq].size() == 0)
    maxfreq--;
  return top;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    push(x);
  }
  while (setMap[maxfreq].size() != 0) {
    cout << (pop()) << "\n";
  }
  return 0;
}
