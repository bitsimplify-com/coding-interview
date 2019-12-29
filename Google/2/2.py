def print_repeating(array, n):      
    for i in range(0, n):
        index = array[i]
        array[index] += n
 
    for i in range(0,n):
        if (array[i]/n) > 1:
            print (i , end = " ")
  
def main():
  array = [5, 6, 7, 7, 8, 8, 1, 2, 3, 4]
  arr_size = len(array)
  print_repeating( arr, arr_size)
