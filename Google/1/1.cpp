#include <iostream>

int binary_search(int arr[], int low, int high, int key) {
  if (high < low)
    return -1;

  int mid = (low + high) / 2;
  if (key == arr[mid])
    return mid;

  if (key > arr[mid])
    return binary_search(arr, (mid + 1), high, key);

  return binary_search(arr, low, (mid - 1), key);
}

int main() {
  int arr[] = {5, 6, 7, 9, 10, 11, 1, 2, 3, 4};
  int array_size = sizeof(arr) / sizeof(arr[0]);
  int pivot = 6;
  int key = 2;
  int left_half = binary_search(arr, 0, pivot - 1, key);
  if (left_half != -1)
    std::cout << left_half;
  left_half = binary_search(arr, pivot, array_size, key);
  if (left_half != -1)
    std::cout << left_half;
  else
    std::cout << "Not found";
}
