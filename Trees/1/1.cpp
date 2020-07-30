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
    TreeNode* constructMax(vector<int> nums,int start,int end){
        if(start>end)return NULL;
        int maxm=-1,maxi;
        for(int i=start;i<=end;i++){
            if(nums[i]>maxm){
                maxm=nums[i];
                maxi=i;
            }
        }
        TreeNode* root=new TreeNode(maxm);
        root->left=constructMax(nums,start,maxi-1);
        root->right=constructMax(nums,maxi+1,end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
       return constructMax(nums,0,nums.size()-1);
    }
};
TreeNode* constructTree(vector<int> nums,int start){
    if(start>=nums.size() || nums[start]==-1)return NULL;
    TreeNode *root=new TreeNode(nums[start]);
    root->left=constructTree(nums,start*2+1);
    root->right=constructTree(nums,start*2 + 2);
    return root;
}
void preorder(TreeNode* root){
    if(!root)return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    sample g;
    int n;
    cin >>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)cin >> nums[i];
    TreeNode* root=g.constructMaximumBinaryTree(nums);
    preorder(root);
    return 0;
}
