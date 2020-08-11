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
    struct node{
     TreeNode* n;
     int l;
    };
    vector<vector<int>>verticalOrderTraversal(TreeNode* A) {
    if(!A)return {};
    queue<node> q;
    q.push({A,0});
    unordered_map<int,vector<int>> umap;
    int minm=0;
    while(!q.empty()){
        node top=q.front();
        q.pop();
        TreeNode* r=top.n;
        int level=top.l;
        minm=min(minm,level);
        umap[level].push_back(r->val);
        if(r->left)q.push({r->left,level-1});
        if(r->right)q.push({r->right,level+1});
    }
    vector<vector<int>> result(umap.size());
    for(auto x:umap)result[x.first-minm]=x.second;
    return result;
    }
};
TreeNode* constructTree(vector<int> nums,int start){
    if(start>=nums.size() || nums[start]==-1)return NULL;
    TreeNode *root=new TreeNode(nums[start]);
    root->left=constructTree(nums,start*2+1);
    root->right=constructTree(nums,start*2 + 2);
    return root;
}
int main()
{
    sample g;
     int n;
     cin >>n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)cin >> A[i];
    TreeNode* root=constructTree(A,0);
    vector<vector<int>> result=g.verticalOrderTraversal(root);
    for(auto x:result){
        for(auto y:x)cout<<y<<" ";
        cout<<"\n";
    }
    return 0;
}
