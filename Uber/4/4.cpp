#include <iostream>
#include <queue>
#include <vector>

struct Node {
    Node *left, *right;
    Node(): left(nullptr), right(nullptr) { }
};

int levelWithMaximumNodes(Node* root) {
    if (!root) {
        return -1;
    }
    std::queue<Node*> NodeQueue;
    NodeQueue.push(root);
    int level = 0, maxNodeCount = -1, levelWithMaxNode = 0;
    while (!NodeQueue.empty()) {
        int NodeCount = NodeQueue.size();
        if (NodeCount > maxNodeCount) {
            maxNodeCount = NodeCount;
            levelWithMaxNode = level;
        }
        while (NodeCount--) {
            Node* tempNode = NodeQueue.front();
            NodeQueue.pop();
            if (tempNode->left) {
                NodeQueue.push(tempNode->left);
            }
            if (tempNode->right) {
                NodeQueue.push(tempNode->right);
            }
        }
        level++;
    }
    return levelWithMaxNode;
}

int main() {
    int m, n;
    std::cin >> m >> n;
    std::vector<Node*> tree;
    tree.reserve(m);
    for (int i = 0; i < m; i++) {
        tree.push_back(new Node);
    }
    while (m--) {
        int idx, l, r;
        std::cin >> idx >> l >> r;
        if (l >= 0) tree[idx]->left = tree[l];
        if (r >= 0) tree[idx]->right = tree[r];
    }
    std::cout << levelWithMaximumNodes(tree[n]) + 1 << "\n";
    return 0;
}
