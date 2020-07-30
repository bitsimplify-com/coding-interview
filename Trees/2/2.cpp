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
    pair<int,int> dsum;
    void calSum(TreeNode* root,int d){
        if(!root)return;
        if(!root->left && !root->right){
            if(d>dsum.first){
                dsum={d,root->val};
            }
            else if(d==dsum.first)dsum.second+=root->val;
        }
        calSum(root->left,d+1);
        calSum(root->right,d+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        dsum={0,0};
        calSum(root,1);
        return dsum.second;
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
    vector<int> nums(n);
    for (int i = 0; i < n; i++)cin >> nums[i];
    TreeNode* root=constructTree(nums,0);
    cout<<g.deepestLeavesSum(root);
    return 0;
}
