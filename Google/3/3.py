# dictionary to keep the result
import sys
result = {'string':'', 'distinct': 0, 'length': 0}

def update_result(s, k):
    if len(set(s)) == k:
        if len(s) > result['length']:
            result['string'] = s
            result['distinct'] = len(set(s))
            result['length'] = len(s)

def longest_substring_k(s, k):
    if len(set(s)) >= k:
        for i in range(len(s)):
            if i < len(s)-1:
                s1 = s[i:i+k]
                s2 = s[i+k:]
                update_result(s1,k)

                for j in range(len(s2)):
                    s3 = s1+s2[:j+1]
                    update_result(s3,k)
    else:
        result['string'] = s
        result['distinct'] = len(set(s))
        result['length'] = len(s)

num_inputs=0
started = False 
for line in sys.stdin:
    if num_inputs==0 and started == False:
        num_inputs = int(line)
        started = True
        continue

    m, n = line.split()
    n = int(n)
    longest_substring_k(m, n)
    print(result['string'], result['length'])

