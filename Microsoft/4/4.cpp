#include <bits/stdc++.h>
using namespace std;

void merge(int ar1[], int ar2[], int m, int n) {
  for (int i = n - 1; i >= 0; i--) {
    int j, last = ar1[m - 1];
    for (j = m - 2; j >= 0 && ar1[j] > ar2[i]; j--)
      ar1[j + 1] = ar1[j];
    if (j != m - 2 || last > ar2[i]) {
      ar1[j + 1] = ar2[i];
      ar2[i] = last;
    }
  }
}

int main(void) {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  int b[m];
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  merge(a, b, n, m);

  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  for (int i = 0; i < m; i++)
    cout << b[i] << " ";
  return 0;
}
