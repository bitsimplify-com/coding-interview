def subArraySum(arr, n, sum):
    for i in range(n):
        curr_sum = arr[i]
        j = i + 1
        while j <= n:

            if curr_sum == sum:
                print("Sum found between")
                print("indexes %d and %d" % (i, j - 1))

                return 1

            if curr_sum > sum or j == n:
                break

            curr_sum = curr_sum + arr[j]
            j += 1

    print("No subarray found")
    return 0

arr = []
n = int(input());
arr = [int(x) for x in input().split()]
n = len(arr)
sum =int(input())
subArraySum(arr, n, sum)
