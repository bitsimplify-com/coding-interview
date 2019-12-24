def findNullTriplets(list):
    size = len(list)
    ans = []
    tempSet = set()
    for i in range(size - 1):
        for j in range(i + 1, size):
            x = -(list[i] + list[j])
            if x in tempSet:
                ans.append([x, list[i], list[j]])
            else:
                tempSet.add(list[j])
    return ans

n = input()
elements = list(map(int, input().split()))
answers = findNullTriplets(elements)
for ans in answers:
    print(ans)
