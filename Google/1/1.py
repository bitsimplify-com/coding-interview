def binary_search(arr, low, high, key): 
    if high < low:
        return -1
    mid = int((low + high)/2)
      
    if key == arr[mid]:
        return mid
    if key > arr[mid]:
        return binary_search(arr, (mid + 1), high, key);
    return binary_search(arr, low, (mid -1), key);
  
 
def main():
    array = [5, 6, 7, 9, 10, 11, 1, 2, 3, 4]
    pivot = 6
    key = 2
    n = len(array)
    array_size = n-1
    left_half = binary_search(array, array[0], array[pivot-1], key);
    if left_half  != -1:
        print(left_half)
        return
    left_half = binary_search(array, array[pivot], array[array_size], key);
    if left_half  != -1:
        print(left_half)
    else:
        print("Not found")


if __name__ == '__main__':
    main()
