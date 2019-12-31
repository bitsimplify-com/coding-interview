#include <iostream>
void print_repeating(int array[], int n) {
  for (int i = 0; i < n; i++) {
    int bucket = array[i]; // Using the array itself as buckets
    array[bucket % n] += n;
  }
  for (int i = 0; i < n; i++) {
    if ((array[i] / n) > 1) // Integer division
      std::cout << i << ' ';
  }
  std::cout << "\n";
}

int main() {
  int array[] = {5, 6, 7, 7, 8, 8, 1, 2, 3, 4};
  int array_size = sizeof(array) / sizeof(array[0]);
  print_repeating(array, array_size);
  return 0;
}
