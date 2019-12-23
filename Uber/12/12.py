class newNode: 
    def __init__(self, data): 
        self.data = data
        self.left = None
        self.right = None
    
def isBST(root):
	global prev
	prev = None
	return isBSTUtil(root)

def isBSTUtil(root):
	global prev
	if root is None:
		return True
	if isBSTUtil(root.left) is False:
		return False
	if prev is not None and prev.data > root.data:
		return False
	prev = root
	return isBSTUtil(root.right)

m, n = map(int, input().split())
tree = []
for x in range(m):
    tree.append(newNode(x))
nodeValue = list(map(int, input().split()))
for x in range(m):
    tree[x].data = nodeValue[x]
for x in range(m):
    idx, l, r = map(int, input().split())
    if l >= 0:
        tree[idx].left = tree[l]
    if r >= 0:
        tree[idx].right = tree[r]
if isBST(tree[n]):
    print("YES")
else:
    print("NO")
