#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

void swap(char *a, char *b) {
  char temp = *a;
  *a = *b;
  *b = temp;
}

void findNext(char number[], int n) {
  int i, j;
  for (i = n - 1; i > 0; i--)
    if (number[i] > number[i - 1])
      break;
  if (i == 0) {
    cout << "Next number is not possible";
    return;
  }
  int x = number[i - 1], smallest = i;
  for (j = i + 1; j < n; j++)
    if (number[j] > x && number[j] < number[smallest])
      smallest = j;
  swap(&number[smallest], &number[i - 1]);

  sort(number + i, number + n);

  cout << number;

  return;
}

int main() {
  string digi;
  cin >> digi;
  char digits[digi.length() + 1];
  strcpy(digits, digi.c_str());
  int n = strlen(digits);
  findNext(digits, n);
  return 0;
}
