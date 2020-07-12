#include <bits/stdc++.h>
using namespace std;

int max(int a, int b);
int lcs(char *X, char *Y, int m, int n) {
  if (m == 0 || n == 0)
    return 0;
  if (X[m - 1] == Y[n - 1])
    return 1 + lcs(X, Y, m - 1, n - 1);
  else
    return max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));
}

int max(int a, int b) { return (a > b) ? a : b; }
int main() {
  int n, m;
  cin >> n >> m;
  char X[n];
  char Y[m];
  for (int i = 0; i < n; i++) {
    cin >> X[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> Y[i];
  }
  cout << lcs(X, Y, n, m);

  return 0;
}
