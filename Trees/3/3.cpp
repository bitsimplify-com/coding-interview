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
    int sum;
    void reqSum(TreeNode* root,int p,int gp){
        if(!root)return;
        if(!(gp&1)) sum+=root->val;
        reqSum(root->left,root->val,p);
        reqSum(root->right,root->val,p);
    }
    int sumEvenGrandparent(TreeNode* root) {
        sum=0;
        reqSum(root,1,1);
        return sum;
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
    vector<int> nums(n);
    for (int i = 0; i < n; i++)cin >> nums[i];
    TreeNode* root=constructTree(nums,0);
    cout<<g.sumEvenGrandparent(root);
    return 0;
}
