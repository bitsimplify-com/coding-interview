#include <iostream> 
using namespace std; 
#define MAX_HEIGHT 10000 
  
struct Node 
{ 
    int key; 
    Node *left, *right; 
}; 

Node* newNode(int key) 
{ 
    Node* node = new Node; 
    node->key = key; 
    node->left = node->right = NULL; 
    return (node); 
} 
  
void kDistantFromLeafUtil(Node* node, int path[], bool visited[], 
                          int pathLen, int k) { 
    if (node==NULL) return; 
  
    path[pathLen] = node->key; 
    visited[pathLen] = false; 
    pathLen++; 
  
    if (node->left == NULL && node->right == NULL && 
        pathLen-k-1 >= 0 && visited[pathLen-k-1] == false) { 
        cout << path[pathLen-k-1] << " "; 
        visited[pathLen-k-1] = true; 
        return; 
    } 
  
    kDistantFromLeafUtil(node->left, path, visited, pathLen, k); 
    kDistantFromLeafUtil(node->right, path, visited, pathLen, k); 
} 
  
void printKDistantfromLeaf(Node* node, int k) 
{ 
    int path[MAX_HEIGHT]; 
    bool visited[MAX_HEIGHT] = {false}; 
    kDistantFromLeafUtil(node, path, visited, 0, k); 
} 
  
int main() 
{ 
    // Let us create binary tree given in the above example 
    Node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
  
    cout << "Nodes at distance 2 are: "; 
    printKDistantfromLeaf(root, 2); 
  
    return 0; 
} 
