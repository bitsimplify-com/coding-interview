class Node:

    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def treeHeight(root):
    if root is None:
        return 0
    q = []
    q.append(root)
    height = 0
    while (True):
        nodeCount = len(q)
        if nodeCount == 0:
            return height
        height += 1
        while (nodeCount > 0):
            node = q[0]
            q.pop(0)
            if node.left is not None:
                q.append(node.left)
            if node.right is not None:
                q.append(node.right)
            nodeCount -= 1

root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)

print(treeHeight(root))
