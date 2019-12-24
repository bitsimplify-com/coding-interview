from queue import Queue

class newNode: 
    def __init__(self, data): 
        self.data = data
        self.left = None
        self.right = None

def levelWithMaximumNodes(root):
    if(root == None):
        return -1
    NodeQueue = Queue()
    NodeQueue.put(root)
    level = 0
    maxNodeCount = -1
    levelWithMaxNode = 0
    while not NodeQueue.empty():
        NodeCount = NodeQueue.qsize()
        if(NodeCount > maxNodeCount):
            maxNodeCount = NodeCount
            levelWithMaxNode = level
        while(NodeCount > 0):
            tempNode = NodeQueue.get()
            if tempNode.left is not None:
                NodeQueue.put(tempNode.left)
            if tempNode.right is not None:
                NodeQueue.put(tempNode.right)
            NodeCount -= 1
        level += 1
    return levelWithMaxNode

m, n = map(int, input().split())
tree = []
for x in range(m):
    tree.append(newNode(x))

for x in range(m):
    idx, l, r = map(int, input().split())
    if l >= 0:
        tree[idx].left = tree[l]
    if r >= 0:
        tree[idx].right = tree[r]
a = levelWithMaximumNodes(tree[n])
print(a + 1)
