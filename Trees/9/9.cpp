#include <bits/stdc++.h>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class sample {
public:
    int ind;
    TreeNode* preIn(vector<int> &B, unordered_map<int,int> &umap,int start,int end){
     if(start>end)return NULL;
     TreeNode* root=new TreeNode(B[ind--]);
     if(start==end)return root;
     int x=umap[root->val];
     root->right=preIn(B,umap,x+1,end);
     root->left=preIn(B,umap,start,x-1);
     return root;
    }
    TreeNode* buildTree(vector<int> &A, vector<int> &B) {
     unordered_map<int,int> umap;
     for(int i=0;i<A.size();i++)umap[A[i]]=i;
     ind=B.size()-1;
     return preIn(B,umap,0,B.size()-1);
    }
};

void preorder(TreeNode* root){
    if(!root)return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(TreeNode* root){
    if(!root)return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
int main()
{
    sample g;
     int n;
     cin >>n;
    vector<int> A(n);
    vector<int> B(n);
    for (int i = 0; i < n; i++)cin >> A[i];
    for (int i = 0; i < n; i++)cin >> B[i];
    TreeNode* root=g.buildTree(A,B);
    preorder(root);
    cout<<"\n";
    inorder(root);
    return 0;
}
