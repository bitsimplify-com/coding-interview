#include<iostream>
#include<queue>
#include<vector>

class Node {
       public:
	int data;
	Node* left;
	Node* right;
	Node() {
		left = NULL;
		right = NULL;
	}
};

bool isBST(Node* root) {
	static Node* prev = NULL;
	if (root) {
		if (!isBST(root->left)) return false;
		if (prev != NULL && root->data <= prev->data) return false;
		prev = root;
		return isBST(root->right);
	}
	return true;
}

int main() {
	int m, n;
	std::cin >> m >> n;
	std::vector<Node*> tree;
	tree.reserve(m);
	for (int i = 0; i < m; i++) {
		tree.push_back(new Node());
	}
	for(int i = 0;i < m;i++) {
		std::cin >> tree[i] -> data;
	}
	while (m--) {
		int idx, l, r;
		std::cin >> idx >> l >> r;
		if (l >= 0) tree[idx]->left = tree[l];
		if (r >= 0) tree[idx]->right = tree[r];
	}
	if (isBST(tree[n]))
		std::cout << "YES\n";
	else
		std::cout << "NO\n";
	return 0;
}
