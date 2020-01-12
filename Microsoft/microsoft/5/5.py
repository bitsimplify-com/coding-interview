freqMap = {};
setMap = {};
maxfreq = 0;
def push(x):
    global maxfreq;
    if x not in freqMap:
        freqMap[x] = 0
    freq = freqMap[x] + 1;
    freqMap[x] = freq
    if (freq > maxfreq):
        maxfreq = freq
    if freq not in setMap:
        setMap[freq] = []
    setMap[freq].append(x);

def pop():
    global maxfreq
    top = setMap[maxfreq][-1];
    setMap[maxfreq].pop();
    freqMap[top] -= 1;
    if (len(setMap[maxfreq]) == 0):
        maxfreq -= 1;
    return top;

if __name__ == "__main__":
    # Push elements to the stack
    n=int(input())
    for i in range(0,n):
        x=int(input())
        push(x);
    # Pop elements
    print(pop())

