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
    int left,right,val;
    bool btreeGameWinningMove(TreeNode* root, int x) {
        val=x;
        int n=count(root);
        int maxm=max(left,max(right,n-left-right-1));
        return maxm>n/2;
    }
    int count(TreeNode* root){
        if(!root)return 0;
        int l=count(root->left);
        int r=count(root->right);
        if(root->val==val){left=l;right=r;}
        return 1+l+r;
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
    int n,x;
    cin >>n>>x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)cin >> nums[i];
    TreeNode* root=constructTree(nums,0);
    cout<<g.btreeGameWinningMove(root,x);
    return 0;
}
